#ifndef SDL_rect_h_
#define SDL_rect_h_

#include "SDL_stdinc.h"
//#include "SDL_error.h"
#include "SDL_pixels.h"
//#include "SDL_rwops.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif



typedef struct SDL_Point
{
    int x;
    int y;
} SDL_Point; //52

typedef struct SDL_Rect
{
    int x, y;
    int w, h;
} SDL_Rect; //93



/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_rect_h_ */