#ifndef box_palette_h_
#define box_palette_h_
#include<SDL2/SDL.h>
class palette
{
private:
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
int    rmask = 0xff000000;
int    gmask = 0x00ff0000;
int    bmask = 0x0000ff00;
int    amask = 0x000000ff;
#else
int    rmask = 0x000000ff;
int    gmask = 0x0000ff00;
int    bmask = 0x00ff0000;
int    amask = 0xff000000;
#endif
    int x;
    int y;
    int box_w;
    int box_h;
    int c;
    SDL_Surface *surface;
    bool isfinsh();
public:
    void reset();
    bool paint(SDL_Surface *s);
    bool paint_(SDL_Surface *s); // use this function if you don't want to move into next point;
    SDL_Surface* getSuface();
    palette(int x,int y,int box_w,int box_h);
    palette(int x,int y);
    void setsize(int w,int h);
    palette& operator=(const palette &plt);

    palette();
    ~palette();
};
#endif

