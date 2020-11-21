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
#include "SDLC_Example.h"
#include "Extends/SDLC_Button.h"
#include "Extends/AnimationTest.h"
#include"Extends/toolbar.h"
#include"Extends/SDLC_Label.h"
#include"Extends/SDLC_Msgbox.h"
#include"Extends/game/SDLC_Session.h"
#include"Extends/Image.h"
#include<string.h>
#include<time.h> 
bool test_event(const SDL_Event& event,SDLC_Component *cmp ) {
    printf("type : %d \n",event.type);
    return false;
}
bool up_event(const SDL_Event& event,SDLC_Component *cmp ) {
    if(event.type == SDL_MOUSEBUTTONUP) { 
        printf("up id : %d \n",cmp->getId());
    }else if(event.type == SDL_MOUSEBUTTONDOWN) {
        printf("down id : %d \n",cmp->getId());
    }
    return true;
}

bool btnHander(const SDL_Event& event,SDLC_Component *cmp) {
    SDLC_Button *btn = (SDLC_Button *)cmp;
    printf("id %d \n",btn->btnflag);
}
static int strick_thread(void *ptr);
SDL_mutex *mutex;
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

    SDLC_Example *comr = new SDLC_Example(&context,50);
   // SDLC_Label *lb = new SDLC_Label(&context,24,"别再说你只知道薰衣草了，罗马尼亚有种花和日本樱花齐名，却不为人知");
    AnimationTest *ani = new AnimationTest(&context);
    //lb->setPostion((context.getWidth()-lb->getWidth())/2,(context.getHeight()-lb->getHeight())/2); 
 
    comr->setMovable(true);
    SDLC_Msgbox msg(&context);
    SDLC_Image img(&context);
    SDLC_Session session(&context,0);
    
    img.load("test.tga");
    msg.show("hello",btnHander);
    context.addComponent(comr);
    context.addComponent(&msg);
  //  context.addComponent(lb);
    context.addComponent(ani);
    context.addComponent(&img);
    context.addComponent(&session);
    session.Show("hello,world");
    SDL_Event event;
    mutex = SDL_CreateMutex();
    SDL_Thread *thread = SDL_CreateThread(strick_thread, "strick_thread", (void *)&context);
  
    while (!isq)
    {
        if(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                isq = 1;
                break;
            }
            SDL_LockMutex(mutex);
            context.dispatch(event);
            SDL_UnlockMutex(mutex);
        }
        SDL_Delay(10);
    }
    
    SDL_DestroyWindow(global_w);

    
    return 0;
}

static int strick_thread(void *ptr)
{
    int ticket = SDL_GetTicks();
    SDLC_Context *context = (SDLC_Context *) ptr;
    while (!isq)
    {                
        if(SDL_GetTicks() - ticket > 30) {
            SDL_LockMutex(mutex);
                ticket = SDL_GetTicks();
                context->updateWindow();
                context->strick();
            SDL_UnlockMutex(mutex);
        }
    }
    
    return 0;
}