#ifndef _GlobalData_h
#define _GlobalData_h
#include"SDLdraw/palette.h"
#include"SDLdraw/drawlist.h"

#include"Box/base.h"
#include"Box/block.h"
#include"Box/person.h"
#include"Box/box.h"
#include"Box/content.h"

#include "SDLC/Extends/SDLC_Button.h"
#include "SDLC/Extends/toolbar.h"
#include "SDLC/Extends/helpbar.h"
#include "fini/fini.h"
/* 全局对象，用于初始化环境 */
struct GameGloabalResouce{   
    
    public:
    FIni *fini;
    int isInit; 
    SDL_Window* global_w; 
    SDLC_Context context;
    Toolbar topbar;
    Helpbar img_help;
    
    palette global_palette;
    map m; 
    content c;

    int leve;
    bool isq;
    int ticket ;
    struct {
        int **bmap;
        int cnt_map; //地图个数
    }bmap;
    /* 放最后，等全局变量创建完成，才创建线程 */
    SDL_mutex *mutex;
    SDL_Thread *thread_strick;
    /* 加载地图
        这里可以加载默认的地图，也可从文件中加载
    */
    void bmapload();

    void loadMainHandle();
    GameGloabalResouce();
    void changeHandle(int id);
};

extern struct GameGloabalResouce GloabalData;

void fromFile(int* len/* output */, int* **bmap /* output */); /* 从文件加载 */
void fromDef(int *len/* output */, int* **bmap /* output */) ; /* 加载默认地图 */
void selectLeve(int leve,content &c); /* 选择关卡 */
#endif
