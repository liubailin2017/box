#ifndef _h_SDLC_Event_
#define _h_SDLC_Event_

class SDLC_Component;
#include<SDL2/SDL.h>
typedef bool (*Handler)(const SDL_Event& event,SDLC_Component *cmp); /* 鼠标处理器 */
typedef void (*OutHandler)(SDLC_Component *cmp); 
typedef void (*InHandler)(SDLC_Component *cmp);
typedef void (*StrickHandler)(SDLC_Component *cmp); 
#endif