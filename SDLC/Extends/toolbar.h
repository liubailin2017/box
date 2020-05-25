#ifndef _Toolbar_h_
#define _Toolbar_h_
#include "../SDLC_Context.h"
#include "../SDLC_Component.h"
#include "../Extends/SDLC_Label.h"
#include<string> 

class Toolbar : public SDLC_Component
{
private:
    int height1; // 收缩后高度
    int height2; // 伸展时高度
    int status; // 1 收缩 2 伸展
    int nx;
    int ny;
    int maxh;
    SDLC_Label *title;
public:
    void defaultStrickHandler(SDLC_Component* cmp);
    virtual void defaultOutHandler(SDLC_Component* cmp);
    virtual void defaultInHandler(SDLC_Component* cmp); 
    void addComponent(SDLC_Component* cmp);  
    void updateSurface();
    Toolbar(SDLC_Context* context);
    virtual ~Toolbar();

    void setText(const char*);
};
#endif