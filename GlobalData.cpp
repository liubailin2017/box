#include"menu_event.h"

#include"GlobalData.h"

#include"fini/fini.h"

#include"snakehand.h"
#include"edithand.h"
#include"mainhand.h"
int _WIDTH =960;
int _HEIGHT =640;

int strick_thread(void *ptr);

GameGloabalResouce::GameGloabalResouce():
                                    fini(FINI_Create("conf.ini")),
                                    global_w(SDL_CreateWindow("推箱子",
                                        SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                        _WIDTH=FINI_GetInt(fini,"WIDTH"),_HEIGHT=FINI_GetInt(fini,"HEIGHT"),FINI_GetInt(fini,"FULLSCREEN")==1?SDL_WINDOW_FULLSCREEN_DESKTOP:SDL_WINDOW_SHOWN/*
                                        SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN*/)),
                                    isInit(SDLC_Init()), /*  加载 SDL2 */
                                    context(SDLC_Context(global_w)), 
                                    topbar(new Toolbar(&context)),
                                    msgbox(new SDLC_Msgbox(&context)),
                                    m(map()),
                                    c(content(&m)),
                                    leve(0),
                                    isq(false),img_help(new Helpbar(&context))
{
    context.addComponent(msgbox);
    context.addComponent(topbar);
    SDLC_Component *sc = new SDLC_Button(&context,FINI_GetStr(fini,"MENU1"),0xff223355);
    sc->setListener(&event_replay_level);
    topbar->addComponent(sc);
    sc = new SDLC_Button(&context,FINI_GetStr(fini,"MENU2"),0xff223355);
    sc->setListener(&event_pre_level); 
    topbar->addComponent(sc);
    sc = new SDLC_Button(&context,FINI_GetStr(fini,"MENU3"),0xff223355);  
    sc->setListener(&event_next_level);
    topbar->addComponent(sc);
    sc = new SDLC_Button(&context,FINI_GetStr(fini,"MENU4"),0x22333333);
    sc->setListener(&event_edit);
    topbar->addComponent(sc);
    sc = new SDLC_Button(&context,FINI_GetStr(fini,"MENU5"),0xff553322);  
    sc->setListener(&event_change_game);
    topbar->addComponent(sc);
    sc = new SDLC_Button(&context,FINI_GetStr(fini,"MENU6"),0xff334422);  
    sc->setListener(&event_back);
    topbar->addComponent(sc);
    sc = new SDLC_Button(&context,FINI_GetStr(fini,"MENU7"),0xff006622);  
    sc->setListener(&event_help);
    topbar->addComponent(sc);
    context.addComponent(img_help);
     sc = new SDLC_Button(&context,FINI_GetStr(fini,"MENU8"),0xff0066ff);  
    sc->setListener(&event_exit);
    topbar->addComponent(sc);
    loadMainHandle();
    bmapload(); /* 地图加载 */  
    selectLeve(leve, c);
    snake_init();
    
    mutex = SDL_CreateMutex();
    thread_strick = SDL_CreateThread(strick_thread,"strick_thread",NULL);
}


void GameGloabalResouce::loadMainHandle() {
    context.setListener(&draw_main);
    context.setListener(&main_hand);
    context.setInterval(1,&mainstrick);
}

void GameGloabalResouce::changeHandle(int id) {
 
    switch (id)
    {
        case 1:
        GloabalData.loadMainHandle();
            break;
        case 2:
            context.setListener(&snake_draw_main);
            context.setListener(&snake_main_hand);
            context.setInterval(10,&snake_strick);
            break;
        case 3:
            context.setListener(&edit_draw_main);
            context.setListener(&edit_main_hand);
            context.setInterval(0,&edit_strick);
            break;
        default:
            break;
    }

}

void GameGloabalResouce::bmapload() {
    if(bmap.bmap) {
        for(int i = 0; i< bmap.cnt_map; i++) {
            delete[] bmap.bmap[i];
        }
        delete[] bmap.bmap;
        bmap.bmap = nullptr;
        bmap.cnt_map = 0;
    }
    fromFile(&bmap.cnt_map,&bmap.bmap);
    
}

#include"box/_maps.h"
#include<string.h>

void fromDef(int *len/* output */, int* **bmap /* output */) {
    *bmap = new int*[_LEN];
    for(int i = 0; i< _LEN; i++) {
        int w = _MAPS_def[i][0];
        int h = _MAPS_def[i][1];
        (*bmap)[i] = new int[w*h+2];
        memcpy((*bmap)[i],_MAPS_def[i],sizeof(int)*(w*h+2));
    }
    *len = _LEN;
}

#include<stdio.h>
void fromFile(int* len/* output */, int* **bmap /* output */) {
    FILE *fmap = fopen(FINI_GetStr(GloabalData.fini,"MAP"),"r");
    if(!fmap) {
       fromDef( len, bmap);
       return ;
    }
    fscanf(fmap,"%d,",len);
    *bmap = new int*[*len];
    for(int i = 0; i< *len; i++) {
        int w;
        fscanf(fmap,"%d,",&w);
        int h;
        fscanf(fmap,"%d,",&h);
        (*bmap)[i] = new int[w*h+2];
        (*bmap)[i][0] = w;
        (*bmap)[i][1] = h;
        for(int j = 0 ;j < w*h; j++) {
            int t;
            if(j%w == 0) printf("\n"); 
            fscanf(fmap,"%d,",&t);
            (*bmap)[i][j+2] = t;
            printf("%d,",t);
        }
    }
    fclose(fmap);
}

void selectLeve(int leve,content &c) {
    std::string title;
    /*step 1 */
    c.getmap()->read(GloabalData.bmap.bmap[leve]);
    /*step 2 */
    palette p(c.getmap()->_w(),c.getmap()->_h(),_WIDTH/c.getmap()->_w(),_HEIGHT/c.getmap()->_h());
    GloabalData.global_palette = p;
    GloabalData.global_palette.reset();
    GloabalData.c.display();
    /*step 3 */
    c.init();
    title = "当前关卡:"+std::to_string(leve+1)+"    "+flag[leve];
    GloabalData.topbar->setText(title.c_str());
    // SDL_SetWindowTitle(GloabalData.global_w,title.c_str());
    
}
