#include"toolbar.h"


Toolbar::Toolbar(SDLC_Context* context):SDLC_Component(context),height1(20),height2(100),nx(10),ny(0),maxh(0) {
    setPostion(0,0);
    status = 1;
    setSize(_context()->getWidth(),height1);    
    setbgcolor(0x88667766);
    title = new SDLC_Label(context,18,"当前关卡：0");
    title->setSize(width,title->getHeight());
    addComponent(title);
    nx = 10;
}

void Toolbar::defaultOutHandler(SDLC_Component *cmp) {
    status = 1;
    SDLC_Component::defaultOutHandler(cmp);
}
void Toolbar::updateSurface(){
    SDLC_Component::updateSurface();
}
void Toolbar::defaultInHandler(SDLC_Component *cmp) {
    status  = 2;
    SDLC_Component::defaultInHandler(cmp);
}

void Toolbar::addComponent(SDLC_Component *cmp) {
    SDLC_Component::addComponent(cmp);
    cmp->setPostion(nx,ny);
    nx += cmp->getWidth() + 20;
    if(maxh <cmp->getHeight()) maxh = cmp -> getHeight();
    if(nx >= width) {
        nx = 10;
        ny += maxh+30;
        maxh = 0;
    }
    height2= maxh +  ny+ 10; 
}
void Toolbar::defaultStrickHandler(SDLC_Component *cmp) {
    
    if(status == 1) {
        int h = getHeight();
        if(h > height1) {
            h -= 5;
            setSize(_context()->getWidth(),h);
        }
    }else if(status == 2) { 
        int h = getHeight();
        if(h < height2) {
            h += 5;        
            setSize(_context()->getWidth(),h);    
        }
    }
   
    SDLC_Component::defaultStrickHandler(cmp);
}

Toolbar::~Toolbar() {

}

void Toolbar::setText(const char *text) {
    if(title) {
        title->setText(text);
    }
}