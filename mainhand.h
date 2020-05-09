#ifndef _mainhand_h
#define _mainhand_h

#include"bfs.h"
#include<SDL2/SDL.h>

#include"src/base.h"
#include"src/block.h"
#include"src/person.h"
#include"src/box.h"
#include"src/content.h"

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

void main_init();
void main_save();
void loadleve(int leve,content &c);
bool hand_evet(const SDL_Event& event, SDLC_Component *cmp) ;

#endif