#ifndef _h_sdltool
#define _h_sdltool
#include<SDL2/SDL.h>

namespace sdltool{
    void line(SDL_Surface *surface,int x0, int y0, int xEnd, int yEnd,Uint32 color,int width);
    int Putpixel(SDL_Surface *surface, int Px, int Py,Uint32 color);
}

#endif
