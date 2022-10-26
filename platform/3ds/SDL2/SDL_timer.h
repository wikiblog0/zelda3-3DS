#ifndef SDL_timer_h_
#define SDL_timer_h_

/**
 *  \file SDL_timer.h
 *
 *  Header for the SDL time management routines.
 */

#include "SDL_stdinc.h"
//#include "SDL_error.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif


extern DECLSPEC Uint32 SDLCALL SDL_GetTicks(void); //45


extern DECLSPEC Uint64 SDLCALL SDL_GetPerformanceCounter(void); //61

extern DECLSPEC Uint64 SDLCALL SDL_GetPerformanceFrequency(void); //66

/**
 * \brief Wait a specified number of milliseconds before returning.
 */
extern DECLSPEC void SDLCALL SDL_Delay(Uint32 ms); //71






/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_timer_h_ */