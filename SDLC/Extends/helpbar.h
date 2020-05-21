#ifndef _Helpbar_h_Extends_
#define _Helpbar_h_Extends_
#include "../SDLC_Component.h"
#include "Image.h"
class Helpbar: public SDLC_Image {
    public :
        Helpbar(SDLC_Context *context);
        virtual int fliterEvent(const SDL_Event& event);
};

#endif