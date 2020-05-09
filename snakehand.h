#ifndef _h_snakehand
#define _h_sankehand
#include "SDLC/SDLC_log.h"
#include "SDLC/SDLC_Context.h"
#include "SDLC/SDLC_Component.h"
#include "SDLC/Extends/Image.h"
void snake_init();
void snake_destory();
void snake_strick(SDLC_Component *cmp);
void snake_draw_main(SDL_Surface *surface) ;
bool snake_main_hand(const SDL_Event& event,SDLC_Context *context);
#endif