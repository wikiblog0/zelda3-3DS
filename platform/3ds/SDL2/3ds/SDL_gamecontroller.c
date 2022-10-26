#include "../SDL_gamecontroller.h"

typedef struct _SDL_GameController {
	int data;
} SDL_GameController;

DECLSPEC SDL_bool SDLCALL SDL_IsGameController(int joystick_index)
{
	if (joystick_index == 0)
		return SDL_TRUE;

	return SDL_FALSE;
}

DECLSPEC SDL_GameController *SDLCALL SDL_GameControllerOpen(int joystick_index)
{
	if (joystick_index != 0)
		return NULL;

	SDL_GameController *controller = (SDL_GameController *)malloc(sizeof(SDL_GameController));
	return controller;
}