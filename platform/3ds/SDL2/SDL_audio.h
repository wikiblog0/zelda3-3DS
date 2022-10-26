#ifndef SDL_audio_h_
#define SDL_audio_h_

#include "SDL_stdinc.h"
#include "SDL_error.h"
//#include "SDL_endian.h"
#include "SDL_mutex.h"
//#include "SDL_thread.h"
//#include "SDL_rwops.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif




typedef Uint16 SDL_AudioFormat; //64

#define AUDIO_U8        0x0008  /**< Unsigned 8-bit samples */
#define AUDIO_S8        0x8008  /**< Signed 8-bit samples */
#define AUDIO_U16LSB    0x0010  /**< Unsigned 16-bit samples */
#define AUDIO_S16LSB    0x8010  /**< Signed 16-bit samples */
#define AUDIO_U16MSB    0x1010  /**< As above, but big-endian byte order */
#define AUDIO_S16MSB    0x9010  /**< As above, but big-endian byte order */
#define AUDIO_U16       AUDIO_U16LSB
#define AUDIO_S16       AUDIO_S16LSB //96

typedef void (SDLCALL * SDL_AudioCallback) (void *userdata, Uint8 * stream,
                                            int len); //163

typedef struct SDL_AudioSpec
{
    int freq;                   /**< DSP frequency -- samples per second */
    SDL_AudioFormat format;     /**< Audio data format */
    Uint8 channels;             /**< Number of channels: 1 mono, 2 stereo */
    Uint8 silence;              /**< Audio buffer silence value (calculated) */
    Uint16 samples;             /**< Audio buffer size in sample FRAMES (total samples divided by channel count) */
    Uint16 padding;             /**< Necessary for some compile environments */
    Uint32 size;                /**< Audio buffer size in bytes (calculated) */
    SDL_AudioCallback callback; /**< Callback that feeds the audio device (NULL to use SDL_QueueAudio()). */
    void *userdata;             /**< Userdata passed to callback (ignored for NULL callbacks). */
} SDL_AudioSpec; //189

typedef Uint32 SDL_AudioDeviceID; //330

extern DECLSPEC SDL_AudioDeviceID SDLCALL SDL_OpenAudioDevice(const char
                                                              *device,
                                                              int iscapture,
                                                              const
                                                              SDL_AudioSpec *
                                                              desired,
                                                              SDL_AudioSpec *
                                                              obtained,
                                                              int
                                                              allowed_changes); //385

extern DECLSPEC void SDLCALL SDL_PauseAudioDevice(SDL_AudioDeviceID dev,
                                                  int pause_on); //419


#define SDL_MIX_MAXVOLUME 128 //649

extern DECLSPEC void SDLCALL SDL_MixAudioFormat(Uint8 * dst,
                                                const Uint8 * src,
                                                SDL_AudioFormat format,
                                                Uint32 len, int volume); //668

extern DECLSPEC void SDLCALL SDL_CloseAudioDevice(SDL_AudioDeviceID dev); //849


/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_audio_h_ */