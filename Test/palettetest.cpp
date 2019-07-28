#include<iostream>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<math.h>
#define PI  (3.14159)
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


#include"../SDLdraw/palette.h"

int main(int argc,char* agrv[]) {
    
    int isq = false;
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);
    SDL_Surface *bg = IMG_Load("bg.jpeg");
    if(!bg) {
        std::cout<<SDL_GetError()<<std::endl;
    };
    SDL_Window *w = SDL_CreateWindow("Box",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    bg->w,bg->h,
                                    SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_ShowWindow(w);

    SDL_Surface *prs= IMG_Load("person.png");
    if(!prs) {
        std::cout<<SDL_GetError()<<std::endl;
    };

    palette p(3,3,100,100);
    for(int i = 0; i< 9; i++)
        if(!p.paint(prs)) std::cout<<"paint failure"<<std::endl;
    
    SDL_Surface* win = SDL_GetWindowSurface(w);

   
    SDL_UpdateWindowSurface(w);

    SDL_Event event;   
    while (!isq)
    {


   if(SDL_BlitSurface(bg,NULL,win,NULL)) {
        std::cout<<SDL_GetError()<<std::endl;
    };
   if(SDL_BlitSurface(p.getSuface(),NULL,win,NULL)) {
        std::cout<<SDL_GetError()<<std::endl;
    };
    SDL_UpdateWindowSurface(w);
 
        while(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_KEYDOWN:
            
                break;
            case SDL_KEYUP:
                break;
            case SDL_MOUSEBUTTONDOWN: 
                    break;
            case SDL_MOUSEBUTTONUP:
                    break;
            case SDL_QUIT: 
                isq =true;
                break;
            default:
                break;
            }
        }
    }
    
    SDL_DestroyWindow(w);
    return 0;
}