#include"../SDLC_Component.h"
#include"AnimationTest.h"
#include"iostream"
#include<SDL2/SDL_image.h>
#include"../SDLC_Context.h"
 

void AnimationTest::updateSurface() {
    Uint32 color = * ((Uint32 *)src->pixels + rects.rect[cur].x + rects.rect[cur].y * src->pitch/4);

    SDLC_Component::updateSurface();
    SDL_SetColorKey(src,1,color);
    if(rects.len > 0) {
        SDL_BlitSurface(src,&rects.rect[cur],surface,NULL);
    }
}

AnimationTest::AnimationTest(SDLC_Context *context):SDLC_Component(context,100,100,45,80,0x00000000),cur(0){
    
    FILE *f = fopen("rects.txt","r");
    src = IMG_Load("Game Boy Advance - Fire Emblem 8 The Sacred Stones - Mauthedoog.png");
    int len;

    if(!f || !src) {
        rects.len = 0;
        rects.rect = NULL;
        printf("not find rects.txt or Game.png");
        return;
    }

    fscanf(f,"%d ",&len);

    rects.len = len;
    rects.rect = (SDL_Rect*) malloc(len*sizeof(SDL_Rect));


    for(int i = 0; i< len; i++) {
        fscanf(f,"%d,%d,%d,%d,",&rects.rect[i].x,&rects.rect[i].y,&rects.rect[i].w,&rects.rect[i].h);
    }
    setMovable(true);
    interval = 10;
    // for(int i = 0; i< 9; i++) {
    //     std::string filename("imgs/651-");
    //     filename+=((char)('0'+i+1));
    //     filename+=".png";
    //     imgs[i] = IMG_Load(filename.c_str());
    //     if(!imgs[i]) std::cout<<SDL_GetError()<<std::endl;
    // }
}

void AnimationTest::defaultStrickHandler(SDLC_Component *cmp) {
    AnimationTest * p = (AnimationTest *)cmp;
    p->cur ++;
    p->cur %= p->rects.len;
    cmp->_context()->notifyUpdate();
    if(strickHandler) strickHandler(cmp);
    SDLC_Component::defaultInHandler(cmp);
}

