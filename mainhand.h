#ifndef _mainhand_h
#define _mainhand_h

#include"bfs.h"
#include<SDL2/SDL.h>

#include"box/base.h"
#include"box/block.h"
#include"box/person.h"
#include"box/box.h"
#include"box/content.h"

#include "SDLC/SDLC_log.h"
#include "SDLC/SDLC_Context.h"
#include "SDLC/SDLC_Component.h"
#include "SDLC/Extends/Image.h"

struct MainHandResouce{   
    tool::queue<tool::pos> qpos;
    tool::bfs _bfs;
    tool::pos *path;
    tool::queue<tool::pos> qpath;
    int path_isend;
    tool::pos Mouse_pre;
    MainHandResouce();
};

extern MainHandResouce mainHandleRes;
/* 添加模块只需要实现下面3个函数 */
void draw_main(SDL_Surface *surface);
bool main_hand(const SDL_Event& event, SDLC_Context *context);
void mainstrick(SDLC_Component *cmp);

bool hand_evet(const SDL_Event& event, SDLC_Component *cmp) ;

#endif