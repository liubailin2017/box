#ifndef _GlobalData_h
#define _GlobalData_h
#include"SDLdraw/palette.h"
#include"SDLdraw/drawlist.h"

#include"src/base.h"
#include"src/block.h"
#include"src/person.h"
#include"src/box.h"
#include"src/content.h"

#include "SDLC/SDLC_log.h"
#include "SDLC/SDLC_Context.h"
#include "SDLC/SDLC_Component.h"
#include "SDLC/Extends/Image.h"
#include "SDLC/Extends/toolbar.h"
#include "SDLC/Extends/helpbar.h"
class GameGloabalResouce{   
    
    public:

    int isInit; 
    SDL_Window* global_w; 
    SDLC_Context context;
    Toolbar topbar;
    Helpbar img_help;
    map m; 
    content c;

    int leve;
    bool isq;


    palette global_palette;

    struct {
        int **bmap;
        int cnt_map; //地图个数
    }bmap;
    /* 加载地图
        这里可以加载默认的地图，也可从文件中加载
    */
    void bmapload();

    void loadMainHandle();
    GameGloabalResouce();
    void changeHandle(int id);
};

extern GameGloabalResouce GloabalData;

#endif