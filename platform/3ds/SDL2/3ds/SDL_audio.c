#include "../SDL_audio.h"

DECLSPEC SDL_AudioDeviceID SDLCALL SDL_OpenAudioDevice(const char *device,
                                                       int iscapture,
                                                       const SDL_AudioSpec *desired,
                                                       SDL_AudioSpec *obtained,
                                                       int allowed_changes)
{
	SDL_AudioDeviceID id;
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
	
}