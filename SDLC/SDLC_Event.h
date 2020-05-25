#ifndef _h_SDLC_Event_
#define _h_SDLC_Event_

class SDLC_Component;
#include<SDL2/SDL.h>
/*
    鼠标事件处理器  
 */
typedef bool (*Handler)(const SDL_Event& event,SDLC_Component *cmp); 

/* 鼠标移出事件 */
typedef void (*OutHandler)(SDLC_Component *cmp); 
/* 鼠标进入事件 */
typedef void (*InHandler)(SDLC_Component *cmp);
/* 时钟事件 */
typedef void (*StrickHandler)(SDLC_Component *cmp); 

#endif