#ifndef SDL_stdinc_h_
#define SDL_stdinc_h_

//#include "SDL_config.h"

#ifndef Sint32
#include <stddef.h>
#define Sint8  char
#define Sint16 short
#define Sint32 int
#define Sint64 long
#define Uint8  unsigned char
#define Uint16 unsigned short
#define Uint32 unsigned int
#define Uint64 unsigned long
#endif

#define SDL_OUT_BYTECAP(x) //304

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
#define SDL_reinterpret_cast(type, expression) reinterpret_cast<type>(expression)
#define SDL_static_cast(type, expression) static_cast<type>(expression)
#define SDL_const_cast(type, expression) const_cast<type>(expression)
#else
#define SDL_reinterpret_cast(type, expression) ((type)(expression))
#define SDL_static_cast(type, expression) ((type)(expression))
#define SDL_const_cast(type, expression) ((type)(expression))
#endif //146

#define SDL_FOURCC(A, B, C, D) \
    ((SDL_static_cast(Uint32, SDL_static_cast(Uint8, (A))) << 0) | \
     (SDL_static_cast(Uint32, SDL_static_cast(Uint8, (B))) << 8) | \
     (SDL_static_cast(Uint32, SDL_static_cast(Uint8, (C))) << 16) | \
     (SDL_static_cast(Uint32, SDL_static_cast(Uint8, (D))) << 24)) //154

#ifdef __CC_ARM
/* ARM's compiler throws warnings if we use an enum: like "SDL_bool x = a < b;" */
#define SDL_FALSE 0
#define SDL_TRUE 1
typedef int SDL_bool;
#else
typedef enum
{
    SDL_FALSE = 0,
    SDL_TRUE = 1
} SDL_bool;
#endif //172

extern DECLSPEC void *SDLCALL SDL_memset(SDL_OUT_BYTECAP(len) void *dst, int c, size_t len); //424





/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_stdinc_h_ */