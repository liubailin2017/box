#include<iostream>
#include<string>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include<math.h>

int _WIDTH =960;
int _HEIGHT =640;

#include "SDLC_log.h"
#include "SDLC_Context.h"
#include "SDLC_Component.h"
#include "Extends/SDLC_Button.h"
#include "Extends/AnimationTest.h"
bool onmove(const SDL_Event &event,SDLC_Component *cmp) {

     switch (event.type)
     {
     case SDL_MOUSEMOTION:
          cmp->setbgcolor(0xff00ff00);
          break;
     default:
          break;
     }
     return true;
}
void mainstrick(SDLC_Component *cmp) {
  
}
int isq = 0;
int main(int argc,char* agrv[]) {
    int ticket ;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    
    SDL_Window* global_w = SDL_CreateWindow("hello,world",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    _WIDTH,_HEIGHT,
                                    SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
    SDLC_Context context(global_w);
    context.setInterval(1,mainstrick);


     for(int i = 0; i < 3; i++) {
          SDLC_Component *sdlc_i = new SDLC_Button(&context,i*120,50,100,50,0xff00ff00);
          sdlc_i->setMovable(true);
        context.addComponent(sdlc_i);

     }


    SDL_Event event;
    ticket = SDL_GetTicks();
    while (!isq)
    {
        while(SDL_PollEvent(&event)) {

            switch (event.type)
            {
            case SDL_QUIT:
                isq = 1;
                break;
            }
            context.dispatch(event);
        }

        int t = SDL_GetTicks();
        if(SDL_GetTicks() - ticket > 30) {

                ticket = SDL_GetTicks();
                context.updateWindow();
                context.strick();
        }
        if(SDL_GetTicks()-t < 10){
           SDL_Delay(10);
        }
    }
    
    SDL_DestroyWindow(global_w);

    return 0;
}

