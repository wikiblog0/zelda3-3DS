#include "../SDL_events.h"
#include "../SDL_gamecontroller.h"
#include <3ds.h>
#include <stdbool.h>

static bool scanEvents = true;
static SDL_Event events[100];
static int numEvents = 0;

static void SDL_PumpEvents(void)
{
	//SDL_Quit
	if (aptMainLoop() == 0) {
		events[numEvents].type = SDL_QUIT;
		numEvents += 1;
	}

	//controller input
	hidScanInput();
	u32 kDown = hidKeysDown();
	u32 kUp = hidKeysUp();

	if (kDown != 0)
	{
		for (int i = 0; i < 32; i++)
		{
			events[numEvents].type = SDL_CONTROLLERBUTTONDOWN;
			switch ( (kDown & (1 << i)) )
			{
				case KEY_DUP:
				case KEY_CPAD_UP: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_DPAD_UP;
					numEvents += 1;
				} break;

				case KEY_DDOWN:
				case KEY_CPAD_DOWN: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_DPAD_DOWN;
					numEvents += 1;
				} break;

				case KEY_DLEFT:
				case KEY_CPAD_LEFT: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_DPAD_LEFT;
					numEvents += 1;
				} break;

				case KEY_DRIGHT:
				case KEY_CPAD_RIGHT: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
					numEvents += 1;
				} break;

				case KEY_A: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_B;
					numEvents += 1;
				} break;

				case KEY_B: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_A;
					numEvents += 1;
				} break;

				case KEY_X: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_Y;
					numEvents += 1;
				} break;

				case KEY_Y: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_X;
					numEvents += 1;
				} break;

				case KEY_L: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
					numEvents += 1;
				} break;

				case KEY_R: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
					numEvents += 1;
				} break;

				case KEY_START: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_START;
					numEvents += 1;
				} break;

				case KEY_SELECT: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_BACK;
					numEvents += 1;
				} break;
			};
		}
	}

	if (kUp != 0)
	{
		for (int i = 0; i < 32; i++)
		{
			events[numEvents].type = SDL_CONTROLLERBUTTONUP;
			switch ( (kUp & (1 << i)) )
			{
				case KEY_DUP:
				case KEY_CPAD_UP: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_DPAD_UP;
					numEvents += 1;
				} break;

				case KEY_DDOWN:
				case KEY_CPAD_DOWN: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_DPAD_DOWN;
					numEvents += 1;
				} break;

				case KEY_DLEFT:
				case KEY_CPAD_LEFT: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_DPAD_LEFT;
					numEvents += 1;
				} break;

				case KEY_DRIGHT:
				case KEY_CPAD_RIGHT: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
					numEvents += 1;
				} break;

				case KEY_A: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_B;
					numEvents += 1;
				} break;

				case KEY_B: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_A;
					numEvents += 1;
				} break;

				case KEY_X: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_Y;
					numEvents += 1;
				} break;

				case KEY_Y: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_X;
					numEvents += 1;
				} break;

				case KEY_L: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
					numEvents += 1;
				} break;

				case KEY_R: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
					numEvents += 1;
				} break;

				case KEY_START: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_START;
					numEvents += 1;
				} break;

				case KEY_SELECT: {
					events[numEvents].cbutton.button = SDL_CONTROLLER_BUTTON_BACK;
					numEvents += 1;
				} break;
			};
		}
	}
}

DECLSPEC int SDLCALL SDL_PollEvent(SDL_Event * event)
{
	if (scanEvents == true) {
		scanEvents = false;
		SDL_PumpEvents();
	}

	if (numEvents > 0) {
		numEvents -= 1;
		*event = events[numEvents];
		return 1;
	}

	scanEvents = true;
	return 0;
}