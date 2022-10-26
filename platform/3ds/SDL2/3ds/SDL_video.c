#include "../SDL_video.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct SDL_Window
{
    char title[0x100];
    int x, y;
    int w, h;
    Uint32 flags;
} SDL_Window;

DECLSPEC int SDLCALL SDL_GetDisplayUsableBounds(int displayIndex, SDL_Rect * rect)
{
	return 0;
}

DECLSPEC int SDLCALL SDL_GetWindowDisplayIndex(SDL_Window * window)
{
	return 0;
}

DECLSPEC SDL_Window * SDLCALL SDL_CreateWindow(const char *title,
                                               int x, int y, int w,
                                               int h, Uint32 flags)
{
    SDL_Window *window = (SDL_Window *)malloc(sizeof(SDL_Window));
    
    sprintf(window->title, "%.255s", title);
    window->x = x;
    window->y = y;
    window->w = w;
    window->h = h;
    window->flags = flags;

	return window;
}

DECLSPEC Uint32 SDLCALL SDL_GetWindowFlags(SDL_Window * window)
{
	return 0;
}

DECLSPEC void SDLCALL SDL_SetWindowTitle(SDL_Window * window,
                                         const char *title)
{

}

DECLSPEC void SDLCALL SDL_SetWindowPosition(SDL_Window * window,
                                            int x, int y)
{

}

DECLSPEC void SDLCALL SDL_GetWindowPosition(SDL_Window * window,
                                            int *x, int *y)
{

}

DECLSPEC void SDLCALL SDL_SetWindowSize(SDL_Window * window, int w, int h)
{

}

DECLSPEC void SDLCALL SDL_GetWindowSize(SDL_Window * window, int *w, int *h)
{
    *w = 400;
    *h = 240;
}

DECLSPEC int SDLCALL SDL_GetWindowBordersSize(SDL_Window * window,
                                              int *top, int *left,
                                              int *bottom, int *right)
{
	return 0;
}

DECLSPEC void SDLCALL SDL_SetWindowBordered(SDL_Window * window,
                                            SDL_bool bordered)
{

}

DECLSPEC int SDLCALL SDL_SetWindowFullscreen(SDL_Window * window,
                                             Uint32 flags)
{
	return 0;
}

DECLSPEC int SDLCALL SDL_SetWindowHitTest(SDL_Window * window,
                                          SDL_HitTest callback,
                                          void *callback_data)
{
	return 0;
}

DECLSPEC void SDLCALL SDL_DestroyWindow(SDL_Window * window)
{
	if (window)
        free(window);
}

DECLSPEC void *SDLCALL SDL_GL_GetProcAddress(const char *proc)
{
    return NULL;
}

DECLSPEC int SDLCALL SDL_GL_SetAttribute(SDL_GLattr attr, int value)
{
    return 0;
}

DECLSPEC SDL_GLContext SDLCALL SDL_GL_CreateContext(SDL_Window * window)
{
    return NULL;
}

DECLSPEC void SDLCALL SDL_GL_GetDrawableSize(SDL_Window * window, int *w, int *h)
{
    *w = 400;
    *h = 240;
}

DECLSPEC int SDLCALL SDL_GL_SetSwapInterval(int interval)
{
    return 0;
}

DECLSPEC int SDLCALL SDL_GL_GetSwapInterval(void)
{
    return 0;
}

DECLSPEC void SDLCALL SDL_GL_SwapWindow(SDL_Window * window)
{

}