#ifndef _SDLC_Tooltip_h_Extends_
#define _SDLC_Tooltip_h_Extends_
#include"SDLC_Component.h"
#include"Extends/SDLC_Label.h"

#include<vector>
class SDLC_Tooltip : public SDLC_WLabel {

private :
    void clear_surface();
    int div_height;
    std::vector<SDL_Surface *> texts; 
protected:
    
    

public:
   
    SDLC_Tooltip(SDLC_Context *context);
    /* override */
    virtual void updateSurface();
    /* override */
    virtual void setText(std::wstring text);
    virtual int fliterEvent(const SDL_Event& event); /* 不捕获所有事件 */
    void show(std::wstring msg,int x,int y);
    void hide();
    virtual ~SDLC_Tooltip();
};

#endif

