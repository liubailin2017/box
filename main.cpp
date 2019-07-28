#include<iostream>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<math.h>
#define PI  (3.14159)
#define WIDTH 960
#define HEIGHT 640
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

#include"src/base.h"
#include"src/block.h"
#include"src/person.h"
#include"src/box.h"
#include"src/content.h"


#include"SDLdraw/palette.h"
#include"SDLdraw/drawlist.h"
palette global_palette;

#include"src/_maps.h"
int main(int argc,char* agrv[]) {
    
    int isq = false;
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);
    drawlist_init_img();

    SDL_Surface *bg = IMG_Load("bg.png");
    if(!bg) {
        std::cout<<SDL_GetError()<<std::endl;
    };

    SDL_Window* w = SDL_CreateWindow("hello,world",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    WIDTH,HEIGHT,
                                    SDL_WINDOW_SHOWN);
    SDL_Surface* win_surface = SDL_GetWindowSurface(w);

    SDL_Event event;
    int leve = 0;
    map m;   
    m.read(_MAPS_def[leve]);
    palette p(m._w(),m._h(),WIDTH/m._w(),HEIGHT/m._h());
    global_palette  = p;
    
    content c(&m);
    c.display();
 
    while (!isq)
    {
 
        while(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_UP:
                    c.actinput(UP);
                    break;
                case SDLK_LEFT:
                    c.actinput(LEFT);
                    break;
                case SDLK_RIGHT:
                    c.actinput(RIGHT);
                    break;
                case SDLK_DOWN:
                    c.actinput(DOWN);
                    break;
                case SDLK_SPACE:
                    c.back();
                default:
                    break;
                }
                if(c.isfinsh()){
                       leve++;
                       m.read(_MAPS_def[leve]);
                       palette p(m._w(),m._h(),WIDTH/m._w(),HEIGHT/m._h());
                       global_palette  = p;
                       c.init();
                }
                global_palette.reset();
                SDL_BlitScaled(bg,NULL,global_palette.getSuface(),NULL);
                c.display();

                break;
            case SDL_QUIT: 
                isq =true;
                break;
            default:
                break;
            }
        }
     
        SDL_BlitSurface(global_palette.getSuface(),NULL,win_surface,NULL);
        SDL_UpdateWindowSurface(w);
    }
    
    SDL_DestroyWindow(w);
    return 0;
}