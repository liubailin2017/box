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
#include"Extends/SDLC_Label.h"

bool test_event(const SDL_Event& event,SDLC_Component *cmp ) {
    printf("type : %d \n",event.type);
    return true;
}

char bf[1024];
int isq = 0;
int main(int argc,char* agrv[]) {
    int ticket ;
    SDLC_Init();
    SDL_Window* global_w = SDL_CreateWindow("hello,world",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    _WIDTH,_HEIGHT,
                                    SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
    SDLC_Context context(global_w);
    context.setInterval(1,NULL);

    SDLC_Label *lb = new SDLC_Label(&context,24,"别再说你只知道薰衣草了，罗马尼亚有种花和日本樱花齐名，却不为人知");  
    context.addComponent(lb);
    lb->setPostion((context.getWidth()-lb->getWidth())/2,(context.getHeight()-lb->getHeight())/2);
    SDLC_Button *btn = new SDLC_Button(&context,"HELLO,WORLD",0xff00ff00);
    context.addComponent(btn);
    SDLC_Component *container = new SDLC_Component(&context,500,500);
    context.addComponent(container);
    container->setMovable(true);
    for(int i = 0; i< 8 ;i++) {
        SDLC_Component *c =  new SDLC_Component(&context,i*10,i*10,100,100,0xff00ff00+i*0xf);

        c->setMovable(true);
        container->addComponent(c);

    }
    Toolbar *tb = new Toolbar(&context);
            for(int j = 0; j< 30; j++){
                        SDLC_Button *btni =  new SDLC_Button(&context,"HELLO,WORLD",0xff00ff00);
                        tb->addComponent(btni);
                        btni->setListener(test_event);
    }
    context.addComponent(tb);
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

