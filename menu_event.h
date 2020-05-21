#ifndef _menu_event_h
#define _menu_event_h
#include "SDLC/SDLC_Event.h" 
#include"GlobalData.h"

bool event_next_level(const SDL_Event& event,SDLC_Component *cmp );

bool event_pre_level(const SDL_Event& event,SDLC_Component *cmp );

bool event_replay_level(const SDL_Event& event,SDLC_Component *cmp );

bool event_help(const SDL_Event& event,SDLC_Component *cmp );

bool event_change_game(const SDL_Event& event,SDLC_Component *cmp );

bool event_back(const SDL_Event& event,SDLC_Component *cmp );
#endif