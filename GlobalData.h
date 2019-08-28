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

class GameGloabalResouce{   
    
    public:
    palette global_palette;
    SDL_Window* global_w; 

    map m; 
    content c;
    
    int leve;
    bool isq = false;

    SDLC_Context context;
    int mleve;

    SDLC_Component topbar;
    void loadMainHandle();
    GameGloabalResouce();

};
#endif