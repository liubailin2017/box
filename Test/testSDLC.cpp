#include<iostream>
#include<string>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<math.h>

int _WIDTH =960;
int _HEIGHT =640;

#include "SDLC_log.h"
#include "SDLC_Context.h"
#include "SDLC_Component.h"
#include "Extends/SDLC_Button.h"
#include "Extends/AnimationTest.h"
#include"Extends/toolbar.h"
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
    SDLC_Init();
    SDL_Window* global_w = SDL_CreateWindow("hello,world",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    _WIDTH,_HEIGHT,
                                    SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
    SDLC_Context context(global_w);
    context.setInterval(1,mainstrick);
        SDLC_Component *tb = new Toolbar(&context);
      
        context.addComponent(tb);
    char *title[] = {"开始游戏","继续游戏","保存"};
     for(int i = 0; i < 3; i++) {
          SDLC_Component *sdlc_i = new SDLC_Button(&context,title[i],0xFF00FF00);
          sdlc_i->setMovable(true);
          sdlc_i->setPostion(100,i*50);
        tb->addComponent(sdlc_i);
     }
    ((SDLC_Button*)context.findById(2))->setText("你好，世界!");

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

