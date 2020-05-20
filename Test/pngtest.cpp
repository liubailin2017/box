#include<iostream>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<math.h>

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


int main(int argc,char* agrv[]) {
  
    int isq = false;
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    SDL_Surface *bg = IMG_Load("101.png");
    if(!bg) {
        std::cout<<SDL_GetError()<<std::endl;
    };
    SDL_Window *w = SDL_CreateWindow("Box",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    640,320,
                                    SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_ShowWindow(w);

    SDL_Surface *prs= IMG_Load("img/intend.png");
    if(!prs) {
        std::cout<<SDL_GetError()<<std::endl;
    };


    SDL_Surface* win = SDL_GetWindowSurface(w);

   
    SDL_UpdateWindowSurface(w);
    SDL_Rect trg={50,50,320,240};
    SDL_Rect src = {0,0,prs->w,prs->h};
           
    SDL_Event event;

    SDL_Surface* surface = SDL_CreateRGBSurface(0,640,320,32,rmask,gmask,bmask,amask); 
    // SDL_SetSurfaceBlendMode(bg,SDL_BLENDMODE_BLEND);
    
    // SDL_SetSurfaceBlendMode(surface,SDL_BLENDMODE_BLEND);

    // for(int i = 0; i< 640*320; i++) {
    //     ((Uint32 *)surface->pixels)[i] = 0xFF0000FF;
    // }

    if(SDL_BlitScaled(bg,NULL,surface,NULL)) {
        std::cout<<"2"<<SDL_GetError()<<std::endl;
    };
    if(SDL_BlitScaled(prs,&src,surface,&trg)) {
        std::cout<<"2"<<SDL_GetError()<<std::endl;
    };
    

    if(SDL_BlitScaled(surface,NULL,win,NULL)) {
        std::cout<<"3"<<SDL_GetError()<<std::endl;
    };
 
    SDL_UpdateWindowSurface(w);
 
    while (!isq)
    {

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