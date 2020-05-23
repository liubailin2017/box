#include"menu_event.h"
#include"mainhand.h"
bool event_next_level(const SDL_Event& event,SDLC_Component *cmp ) {
    if(event.type != SDL_MOUSEBUTTONDOWN) return true;
    if(GloabalData.leve < GloabalData.bmap.cnt_map-1) { 
        ++GloabalData.leve;
        selectLeve(GloabalData.leve,GloabalData.c);
    }
    return true;
}

bool event_pre_level(const SDL_Event& event,SDLC_Component *cmp ) {
    if(event.type != SDL_MOUSEBUTTONDOWN) return true;

    if(GloabalData.leve > 0) { 
        --GloabalData.leve;
        selectLeve(GloabalData.leve,GloabalData.c);
    }
    return true;
}

bool event_replay_level(const SDL_Event& event,SDLC_Component *cmp ) {
        if(event.type != SDL_MOUSEBUTTONDOWN) return true;
        selectLeve(GloabalData.leve,GloabalData.c);
        return true;
}
bool event_help(const SDL_Event& event,SDLC_Component *cmp ) {
        if(event.type != SDL_MOUSEBUTTONDOWN) return true;
        GloabalData.img_help.setvisible(! GloabalData.img_help.visible());
        return true;
}
 
bool event_back(const SDL_Event& event,SDLC_Component *cmp ){
    if(event.type != SDL_MOUSEBUTTONDOWN) return true;
    GloabalData.c.back();
    return true;   
}
static int id = 1;
bool event_change_game(const SDL_Event& event,SDLC_Component *cmp ) {
    if(event.type != SDL_MOUSEBUTTONDOWN) return true;

    if(id == 1) {
        id = 2;
    }else if(id == 2) {
        id = 1;
    }

    GloabalData.changeHandle(id);
    
    return true;
}

#include"edithand.h"
bool event_edit(const SDL_Event& event,SDLC_Component *cmp ) {
    if(event.type != SDL_MOUSEBUTTONDOWN) return true;

    if(id == 1) {
        id = 3; 
        edit_hand_init();
    }else if(id == 3) {
        edit_hand_exit();
        id = 1;
    }
    
    GloabalData.changeHandle(id);
    return true;
}