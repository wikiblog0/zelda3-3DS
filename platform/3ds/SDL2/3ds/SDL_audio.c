#include "../SDL_audio.h"
#include <3ds.h>

#define BUF_SIZE 4096 //(8192)
#define NDSP_NUM_CHANNELS 2
static ndspWaveBuf waveBuf[NDSP_NUM_CHANNELS];
static volatile bool audioEnabled = false;
static volatile unsigned char fillBlock = 0;
static void (*processAudio) (void*, uint8_t*, int) = NULL;
static Thread threadID;
static Handle threadRequest;
static SDL_AudioSpec spec;

static void audioCallback(void* const arg)
{
    if (!audioEnabled)
        return;

    svcSignalEvent(threadRequest);
}

static void audioThread(void* arg)
{
    ndspChnReset(0);
    ndspChnSetInterp(0, NDSP_INTERP_NONE);
    ndspChnSetRate(0, spec.freq);
    ndspChnSetFormat(0, NDSP_FORMAT_STEREO_PCM16);

    for (int i = 0; i < NDSP_NUM_CHANNELS; i++) {
        waveBuf[i].data_vaddr = (uint8_t*)linearAlloc(BUF_SIZE);
        waveBuf[i].nsamples = BUF_SIZE / 2 / 2;
        waveBuf[i].looping = false;
        waveBuf[i].status = NDSP_WBUF_DONE;
    }

    svcCreateEvent(&threadRequest, RESET_ONESHOT);
    ndspSetCallback(audioCallback, NULL);

    while (audioEnabled)
    {
        if (waveBuf[fillBlock].status == NDSP_WBUF_DONE)
        {
            processAudio(NULL, (uint8_t*)waveBuf[fillBlock].data_vaddr, BUF_SIZE);

            ndspChnWaveBufAdd(0, &waveBuf[fillBlock]);
            DSP_FlushDataCache(waveBuf[fillBlock].data_vaddr, BUF_SIZE);

            fillBlock = !fillBlock;
        }

        svcWaitSynchronization(threadRequest, UINT64_MAX);
        svcClearEvent(threadRequest);
    }

    svcCloseHandle(threadRequest);

    for (int i = 0; i < NDSP_NUM_CHANNELS; i++)
        linearFree((uint8_t*)waveBuf[i].data_vaddr);
    audioEnabled = false;
}

DECLSPEC SDL_AudioDeviceID SDLCALL SDL_OpenAudioDevice(const char *device, int iscapture, const SDL_AudioSpec *desired, SDL_AudioSpec *obtained, int allowed_changes)
{
    ndspInit();
    audioEnabled = true;

    spec = *desired;
    *obtained = *desired;

    processAudio = spec.callback;

    s32 prio = 0;
    svcGetThreadPriority(&prio, CUR_THREAD_HANDLE);
    threadCreate(audioThread, NULL, 4*1024, prio-1, -1, true);

	SDL_AudioDeviceID id = 1;
	return id;
}

DECLSPEC void SDLCALL SDL_PauseAudioDevice(SDL_AudioDeviceID dev,
                                           int pause_on)
{

}

DECLSPEC void SDLCALL SDL_MixAudioFormat(Uint8 * dst,
                                         const Uint8 * src,
                                         SDL_AudioFormat format,
                                         Uint32 len, int volume)
{

}

DECLSPEC void SDLCALL SDL_CloseAudioDevice(SDL_AudioDeviceID dev)
{
	svcSignalEvent(threadRequest);
    threadJoin(threadID, U64_MAX);

    ndspExit();
}