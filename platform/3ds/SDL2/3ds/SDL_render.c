#include "../SDL_render.h"
#include <3ds.h>
#include <stdlib.h>

typedef struct SDL_Renderer
{
	SDL_Window *window;
	int index;
	Uint32 flags;
} SDL_Renderer;

typedef struct SDL_Texture
{
	Uint32 format;
	int access;
	int w, h;
	char *pixels;
} SDL_Texture;

DECLSPEC SDL_Renderer * SDLCALL SDL_CreateRenderer(SDL_Window * window,
	                                               int index, Uint32 flags)
{
	SDL_Renderer *renderer = (SDL_Renderer *)malloc(sizeof(SDL_Renderer));

	renderer->window = window;
	renderer->index = index;
	renderer->flags = flags;

	return renderer;
}

DECLSPEC int SDLCALL SDL_GetRendererInfo(SDL_Renderer * renderer,
                                         SDL_RendererInfo * info)
{
	if (!info) {
		//SDL_SetError();
		return -1;
	}

	//I guess I get to make shit up
	info->name = "3DS";
	info->flags = 0;
	info->num_texture_formats = 1;
	info->max_texture_width = 1024;
	info->max_texture_height = 1024;

	return 0;
}

DECLSPEC SDL_Texture * SDLCALL SDL_CreateTexture(SDL_Renderer * renderer,
                                                 Uint32 format,
                                                 int access, int w, int h)
{
	SDL_Texture *texture = (SDL_Texture *)malloc(sizeof(SDL_Texture));

	texture->format = format;
	texture->access = access;
	texture->w = w;
	texture->h = h;
	texture->pixels = (char *)malloc(w * h * 4);

	return texture;
}

DECLSPEC int SDLCALL SDL_LockTexture(SDL_Texture * texture,
                                     const SDL_Rect * rect,
                                     void **pixels, int *pitch)
{
	if (!texture)
		return -1;

	*pixels = texture->pixels;
	*pitch = texture->w * 4;
	
	return 0;
}

DECLSPEC void SDLCALL SDL_UnlockTexture(SDL_Texture * texture)
{

}

DECLSPEC int SDLCALL SDL_RenderSetLogicalSize(SDL_Renderer * renderer, int w, int h)
{
	return 0;
}

DECLSPEC int SDLCALL SDL_RenderClear(SDL_Renderer * renderer)
{
	return 1;
}

static unsigned long thisTime = 0;
static unsigned long lastTime = 0;
static bool skip = false;

inline DECLSPEC int SDLCALL SDL_RenderCopy(SDL_Renderer * renderer,
                                    	   SDL_Texture * texture,
                                    	   const SDL_Rect * srcrect,
                                    	   const SDL_Rect * dstrect)
{
	if (!texture)
		return -1;

	lastTime = thisTime;
	thisTime = osGetTime();
	if (thisTime - lastTime > (1000 / 60))
	{
		skip = !skip;
		if (skip) {
			//gfxSwapBuffers();
			//gspWaitForVBlank();
			return 0;
		}
	}

	char* fb = (char*)gfxGetFramebuffer(GFX_TOP, GFX_LEFT, 0, 0);
/*
	int x = 1;
	int y = 0;

	long i = ((240 - y - 1) + (240 * x)) * 3;
	fb[i] = 0xff;
	fb[i+1] = 0xff;
	fb[i+2] = 0xff;
*/

	//long pos = 0;
	char *in = texture->pixels;
	//short pix;
	char r, g, b;
	int xoff = (400 - texture->w) / 2;
	int yoff = (240 - texture->h) / 2;
	char* pos;


	for (int y = yoff; y < yoff+texture->h; y++) {
		for (int x = xoff; x < xoff+texture->w; x++) {
			//r = *in++;
			//g = *in++;
			//b = *in++;
			
			pos = &fb[((x*240) + (240-y-1)) * 3];
			*pos++ = *in++;
			*pos++ = *in++;
			*pos++ = *in++;
			in++;
			

			//in += 4;
		
			//if (x >= 400)
			//	continue;

			//fb[(x*240)+ (240-y-1)] = ((r>>3)<<11) | ((g>>2)<<5) | (b>>3);
		}
		//in += 4 * texture->w;
		//if (y >= 240)
		//	break;
	}

	gfxSwapBuffers();
	gspWaitForVBlank();

	return 0;
}

DECLSPEC void SDLCALL SDL_RenderPresent(SDL_Renderer * renderer)
{
	//gfxSwapBuffers();
	//gspWaitForVBlank();
}

DECLSPEC void SDLCALL SDL_DestroyTexture(SDL_Texture * texture)
{
	if (texture)
		free(texture);
}

DECLSPEC void SDLCALL SDL_DestroyRenderer(SDL_Renderer * renderer)
{
	if (renderer)
		free(renderer);
}