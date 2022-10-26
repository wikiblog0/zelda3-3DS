#ifndef SDL_keyboard_h_
#define SDL_keyboard_h_

#include "SDL_stdinc.h"
//#include "SDL_error.h"
#include "SDL_keycode.h"
#include "SDL_video.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif


typedef struct SDL_Keysym
{
    SDL_Scancode scancode;      /**< SDL physical key code - see ::SDL_Scancode for details */
    SDL_Keycode sym;            /**< SDL virtual key code - see ::SDL_Keycode for details */
    Uint16 mod;                 /**< current key modifiers */
    Uint32 unused;
} SDL_Keysym; //53



extern DECLSPEC SDL_Keymod SDLCALL SDL_GetModState(void); //82

extern DECLSPEC SDL_Keycode SDLCALL SDL_GetKeyFromName(const char *name); //150



/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_keyboard_h_ */