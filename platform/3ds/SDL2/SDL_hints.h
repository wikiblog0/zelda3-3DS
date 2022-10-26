#ifndef SDL_hints_h_
#define SDL_hints_h_

#include "SDL_stdinc.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif





#define SDL_HINT_RENDER_SCALE_QUALITY       "SDL_RENDER_SCALE_QUALITY" //143



extern DECLSPEC SDL_bool SDLCALL SDL_SetHint(const char *name,
                                             const char *value); //1518







/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_hints_h_ */