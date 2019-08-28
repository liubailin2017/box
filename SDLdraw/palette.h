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
    int w;
    int h;
    int box_w;
    int box_h;
    int c; // current 
    SDL_Surface *surface;
    Uint8 *data;
    bool isfinsh();
public:
    void reset();
    bool paint(SDL_Surface *s);
    bool paint_(SDL_Surface *s); // use this function if you want not to move into next point;
    bool paint(SDL_Surface *s,int d);
    bool paint_(SDL_Surface *s,int d); // use this function if you want not to move into next point;
    
    SDL_Surface* getSuface();
    int getW();
    int getH();
    int getBoxW();
    int getBoxH();
    Uint8* getData();
    palette(int w,int h,int box_w,int box_h);
    palette(int h,int w);
    void setsize(int bw,int bh);
    palette& operator=(const palette &plt);

    palette();
    ~palette();
};
#endif

