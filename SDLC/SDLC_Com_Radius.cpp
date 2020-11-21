#include"SDLC_Com_Radius.h"
#include"sdltool.h"
#include"math.h"

void SDLC_Com_Radius::setRadius(int r) {
    radius = r;
    updateSurface();
}

int SDLC_Com_Radius::getRadius() {
    return radius;
}

void ::SDLC_Com_Radius::updateSurface() {
    Uint32 mask_c = 0x00000000;
    SDLC_Component::updateSurface();
    int width = getWidth();
    int height = getHeight();
    for(int i = 0; i <= radius; i++) {
        int x = radius - sqrt(radius*radius - i * i);
        sdltool::line(surface,0,radius-i,x,radius - i,mask_c,1);/* 左上 */ 
        sdltool::line(surface,width-x,radius - i,width,radius-i,mask_c,1);  /* 右上 */
        sdltool::line(surface,0,height-radius+i,x,height- radius + i,mask_c,1); /* 左下 */
        sdltool::line(surface,width-x,height-radius+i,width,height-radius+i,mask_c,1);  /* 右下 */
    }

}

SDLC_Com_Radius::SDLC_Com_Radius(SDLC_Context *context):SDLC_Com_Radius(context,100,100) {}
SDLC_Com_Radius::SDLC_Com_Radius(SDLC_Context *context,int w,int d):SDLC_Com_Radius(context,0,0,w,d) {}
SDLC_Com_Radius::SDLC_Com_Radius(SDLC_Context *context,int x,int y,int w,int d):SDLC_Com_Radius(context,x,y,w,d,0xffffffff){}
SDLC_Com_Radius::SDLC_Com_Radius(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg):SDLC_Com_Radius(context,x,y,w,d,bg,0) {}

SDLC_Com_Radius::SDLC_Com_Radius(SDLC_Context *context,int x,int y,int w,int d,Uint32 bg,int r):SDLC_Component(context,x,y,w,d,bg),radius(r){
    setRadius(r);
}
