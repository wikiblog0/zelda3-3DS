#include "../SDL.h"
#include <3ds.h>

DECLSPEC int SDLCALL SDL_Init(Uint32 flags)
{
	int result = 0;

	if (flags | SDL_INIT_TIMER) {

	}

	if (flags | SDL_INIT_AUDIO) {

	}

	if (flags | SDL_INIT_VIDEO) {
		//gfxInitDefault();
		//consoleInit(GFX_BOTTOM, NULL);
		//gfxSetScreenFormat(GFX_TOP, GSP_RGB565_OES);
	}

	if (flags | SDL_INIT_JOYSTICK) {

	}

	if (flags | SDL_INIT_HAPTIC) {

	}

	if (flags | SDL_INIT_GAMECONTROLLER) {

	}

	if (flags | SDL_INIT_EVENTS) {

	}

	if (flags | SDL_INIT_SENSOR) {

	}

	return result;
}

DECLSPEC void SDLCALL SDL_Quit(void)
{
	
}