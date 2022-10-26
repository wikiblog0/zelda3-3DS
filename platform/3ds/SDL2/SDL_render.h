#ifndef SDL_render_h_
#define SDL_render_h_

#include "SDL_stdinc.h"
#include "SDL_rect.h"
#include "SDL_video.h"

#include "begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif



typedef enum
{
    SDL_RENDERER_SOFTWARE = 0x00000001,         /**< The renderer is a software fallback */
    SDL_RENDERER_ACCELERATED = 0x00000002,      /**< The renderer uses hardware
                                                     acceleration */
    SDL_RENDERER_PRESENTVSYNC = 0x00000004,     /**< Present is synchronized
                                                     with the refresh rate */
    SDL_RENDERER_TARGETTEXTURE = 0x00000008     /**< The renderer supports
                                                     rendering to texture */
} SDL_RendererFlags; //73

typedef struct SDL_RendererInfo
{
    const char *name;           /**< The name of the renderer */
    Uint32 flags;               /**< Supported ::SDL_RendererFlags */
    Uint32 num_texture_formats; /**< The number of available texture formats */
    Uint32 texture_formats[16]; /**< The available texture formats */
    int max_texture_width;      /**< The maximum texture width */
    int max_texture_height;     /**< The maximum texture height */
} SDL_RendererInfo; //86

typedef enum
{
    SDL_TEXTUREACCESS_STATIC,    /**< Changes rarely, not lockable */
    SDL_TEXTUREACCESS_STREAMING, /**< Changes frequently, lockable */
    SDL_TEXTUREACCESS_TARGET     /**< Texture can be used as a render target */
} SDL_TextureAccess; //106

struct SDL_Renderer;
typedef struct SDL_Renderer SDL_Renderer; //132

struct SDL_Texture;
typedef struct SDL_Texture SDL_Texture; //138

extern DECLSPEC SDL_Renderer * SDLCALL SDL_CreateRenderer(SDL_Window * window,
                                               int index, Uint32 flags); //202

extern DECLSPEC int SDLCALL SDL_GetRendererInfo(SDL_Renderer * renderer,
                                                SDL_RendererInfo * info); //225

extern DECLSPEC SDL_Texture * SDLCALL SDL_CreateTexture(SDL_Renderer * renderer,
                                                        Uint32 format,
                                                        int access, int w,
                                                        int h); //252

extern DECLSPEC int SDLCALL SDL_LockTexture(SDL_Texture * texture,
                                            const SDL_Rect * rect,
                                            void **pixels, int *pitch); //470

extern DECLSPEC void SDLCALL SDL_UnlockTexture(SDL_Texture * texture); //498

extern DECLSPEC int SDLCALL SDL_RenderSetLogicalSize(SDL_Renderer * renderer, int w, int h); //554

extern DECLSPEC int SDLCALL SDL_RenderClear(SDL_Renderer * renderer); //755

extern DECLSPEC int SDLCALL SDL_RenderCopy(SDL_Renderer * renderer,
                                           SDL_Texture * texture,
                                           const SDL_Rect * srcrect,
                                           const SDL_Rect * dstrect); //873

/**
 *  \brief Update the screen with rendering performed.
 */
extern DECLSPEC void SDLCALL SDL_RenderPresent(SDL_Renderer * renderer); //1063

extern DECLSPEC void SDLCALL SDL_DestroyTexture(SDL_Texture * texture); //1071

extern DECLSPEC void SDLCALL SDL_DestroyRenderer(SDL_Renderer * renderer); //1079



/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif
#include "close_code.h"

#endif /* SDL_render_h_ */