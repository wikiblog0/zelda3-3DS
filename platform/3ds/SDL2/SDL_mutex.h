#ifndef SDL_mutex_h_
#define SDL_mutex_h_

/**
 *  \file SDL_mutex.h
 *
 *  Functions to provide thread synchronization primitives.
 */

#include "SDL_stdinc.h"
//#include "SDL_error.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif


struct SDL_mutex;
typedef struct SDL_mutex SDL_mutex; //59

extern DECLSPEC SDL_mutex *SDLCALL SDL_CreateMutex(void); //64

#define SDL_mutexP(m)   SDL_LockMutex(m)
extern DECLSPEC int SDLCALL SDL_LockMutex(SDL_mutex * mutex); //72

#define SDL_mutexV(m)   SDL_UnlockMutex(m)
extern DECLSPEC int SDLCALL SDL_UnlockMutex(SDL_mutex * mutex); //90

extern DECLSPEC void SDLCALL SDL_DestroyMutex(SDL_mutex * mutex); //95












/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_mutex_h_ */