#include "../SDL_mutex.h"

typedef struct SDL_mutex
{
	int data;
} SDL_mutex;

DECLSPEC SDL_mutex *SDLCALL SDL_CreateMutex(void)
{
	SDL_mutex *mutex = (SDL_mutex *)malloc(sizeof(SDL_mutex));
	return mutex;
}

DECLSPEC int SDLCALL SDL_LockMutex(SDL_mutex * mutex)
{
	return 0;
}

DECLSPEC int SDLCALL SDL_UnlockMutex(SDL_mutex * mutex)
{
	return 0;
}

DECLSPEC void SDLCALL SDL_DestroyMutex(SDL_mutex * mutex)
{
	if (mutex)
		free(mutex);
}