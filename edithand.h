#ifndef _h_edithand
#define _h_edithand
#include "SDLC/SDLC_Context.h"
#include "SDLC/SDLC_Component.h"

void edit_hand_init();
void edit_hand_exit();
void edit_strick(SDLC_Component *cmp);
void edit_draw_main(SDL_Surface *surface);
bool edit_main_hand(const SDL_Event& event,SDLC_Context *context);
#endif
