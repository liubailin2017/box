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
SDLC_Tooltip *tooltip;
SDLC_Context *g_Context;
int isq = 0;

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


bool onMessageBoxFinish(const SDL_Event& event,SDLC_Component *cmp) {
    SDLC_Button *btn = (SDLC_Button *)cmp;
    printf("ShowMessage : btnflag %d \n",btn->btnflag);
    if(event.type == SDL_MOUSEBUTTONUP) {
        isq = true;
    }
    return true;
}

bool onSessionSelected(const SDL_Event& event,SDLC_Component *cmp) {
    SDLC_Button *btn = (SDLC_Button *)cmp;
    if(event.type == SDL_MOUSEBUTTONDOWN) {
        SDLC_Msgbox *msg = new SDLC_Msgbox(g_Context);
        g_Context->addComponent(msg);
        if(btn->btnflag == 0) {
           msg->show("选择完成0",onMessageBoxFinish); 
        } else {
            msg->show("选择完成1",onMessageBoxFinish); 
        }
        g_Context->InvalidCompById(cmp->header()->getParent()->getId());
    }
    return true; 
}


void SessionOnFinish(int id) {
    SDLC_Msgbox *msg = new SDLC_Msgbox(g_Context);
    g_Context->addComponent(msg);
    msg->show("完成了对话",onMessageBoxFinish);
}

 
 
static int strick_thread(void *ptr);
SDL_mutex *mutex;
char bf[1024];

int main(int argc,char* agrv[]) {
    int ticket ;
    SDLC_Init();
    SDL_Window* global_w = SDL_CreateWindow("hello,world",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    _WIDTH,_HEIGHT,
                                    /*SDL_WINDOW_RESIZABLE|*/SDL_WINDOW_SHOWN);
    SDLC_Context context(global_w);
    g_Context = &context;

    context.setInterval(1,NULL);

    //SDLC_Example *comr = new SDLC_Example(&context,50);
    SDLC_Label *lb = new SDLC_Label(&context,24,"别再说你只知道薰衣草了，罗马尼亚有种花和\n日本樱花齐名，却不为人知");

    //AnimationTest *ani = new AnimationTest(&context);
    lb->setPostion((context.getWidth()-lb->getWidth())/2,(context.getHeight()-lb->getHeight())/2); 

    //comr->setMovable(true);
  
    SDLC_Image *img = new SDLC_Image(&context);
    SDLC_Session*session = new SDLC_Session(&context,&SessionOnFinish);
    img->load("test.png");
  
    //context.addComponent(comr);
    context.addComponent(lb);
    // context.addComponent(ani);
    // context.addComponent(&img);
    context.addComponent(session);
    session -> Show(img,
L"一天动物园管理员发现袋鼠从笼子里跑出来了，于是开会讨论，一致认为是笼子的高度过低"
"所以他们决定将笼子的高度由原来的10米加高到20米。结果第二天他们发现袋鼠还是跑到外面来，所以他们又决定再将高度加高到30米。"
"没想到隔天居然又看到袋鼠全跑到外面，于是管理员们大为紧张，决定一不做二不休，将笼子的高度加高到100米。"
"一天长颈鹿和几只袋鼠们在闲聊，“你们看，这些人会不会再继续加高你们的笼子？长颈鹿问。“很难说。袋鼠说∶“如果他们再继续忘记关门的话！",
onSessionSelected);
    SDL_Event event;
    mutex = SDL_CreateMutex();
//    SDL_Thread *thread = SDL_CreateThread(strick_thread, "strick_thread", (void *)&context);
  
    while (!isq)
    {
        if(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                isq = 1;
                break;
            }
           // SDL_LockMutex(mutex);
            
            context.dispatch(event);
           // SDL_UnlockMutex(mutex);
        }

        if(SDL_GetTicks() - ticket > 30) {
            //SDL_LockMutex(mutex);
                ticket = SDL_GetTicks();
                context.updateWindow();
                context.strick();
            //SDL_UnlockMutex(mutex);
        }
        SDL_Delay(10);
        context.freeInvalidComps();
    }
    
    SDL_DestroyWindow(global_w);

    
    return 0;
}

// static int strick_thread(void *ptr)
// {
//     int ticket = SDL_GetTicks();
//     SDLC_Context *context = (SDLC_Context *) ptr;
//     while (!isq)
//     {                
//         if(SDL_GetTicks() - ticket > 30) {
//             SDL_LockMutex(mutex);
//                 ticket = SDL_GetTicks();
//                 context->updateWindow();
//                 context->strick();
//             SDL_UnlockMutex(mutex);
//         }
//     }
    
//     return 0;
// }

/* 
todo
解决析构异常  V
*/