#ifndef _h_SDLC_Event_
#define _h_SDLC_Event_

class SDLC_Component;
#include<SDL2/SDL.h>
/*
    鼠标SDL_MOUSEBUTTONDOWN ,SDL_MOUSEBUTTONDOWN处理器  
    通常情况鼠标SDL_MOUSEBUTTONDOWN 事件的处理请返回 true,
    返回false 可能会影响事件分发链，产生异常
 */
typedef bool (*Handler)(const SDL_Event& event,SDLC_Component *cmp); 

/* 鼠标移出事件 */
typedef void (*OutHandler)(SDLC_Component *cmp); 
/* 鼠标进入事件 */
typedef void (*InHandler)(SDLC_Component *cmp);
/* 时钟事件 */
typedef void (*StrickHandler)(SDLC_Component *cmp); 

#endif