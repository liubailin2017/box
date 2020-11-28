#include<SDL2/SDL.h>
#include<iostream>
#include"SDLC_Component.h"
#include"SDLC_Context.h"
#include"SDLC_log.h"

static int    rmask = 0x000000ff;
static int    gmask = 0x0000ff00;
static int    bmask = 0x00ff0000;
static int    amask = 0xff000000;

extern bool isContain(int x ,int y,int rx,int ry, int rw,int rh);

bool SDLC_Component::defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp) {


    if(event.type == SDL_MOUSEBUTTONDOWN) {
        upLock = event.button.button;
        if(canRaise == true) { 
            raise();
        }
        if(/*context->curMvCmp == NULL && */_movable && upLock == 1) {
            context->curMvCmp = this;
            context->status[0] = event.button.x;
            context->status[1] = event.button.y; 
            context->status[2] = x;
            context->status[3] = y;
        }
    }
    
    if(mouseButtonHandler == NULL) {
        return true; /* 默认是被消耗 */
    }else 
        if(mouseButtonHandler(event,this)) {
            return true;
        }else {
            return false;
        }
        
}

void SDLC_Component::defaultOutHandler(SDLC_Component *cmp) {
    std::cout << "out  ID:"<< cmp->getId() <<std::endl;
    if(cmp->outHandler) outHandler(cmp);
}

void SDLC_Component::defaultInHandler(SDLC_Component *cmp) {   
    std::cout << "into ID:"<< cmp->getId()<<"uplock:"<< upLock<<std::endl;
    
    if(cmp->inHandler) inHandler(cmp);
}

void SDLC_Component::defaultStrickHandler(SDLC_Component *cmp) {
    if(strickHandler)
        strickHandler(this);
}

SDLC_Context* SDLC_Component::_context() {
    return context;
}

bool SDLC_Component::movable() {
    return _movable;
}
void SDLC_Component::setMovable(bool v) {
    _movable = v;
}
void SDLC_Component::setRaise(bool v) {
    canRaise = v;
}

void SDLC_Component::setbgcolor(Uint32 bg) {
    this ->bgcolor = bg;
    SDLC_Component::updateSurface();
}

Uint32 SDLC_Component::getBgcolor() {
    return bgcolor;
}

int SDLC_Component::abx() {
    SDLC_Component *head = header();
    if(head -> parent) {
        return head->parent->abx() + x; 
    }else {
        return x;
    }
}

int SDLC_Component::aby() {
    SDLC_Component *head = header();
    if(head -> parent) {
        return head->parent->aby() + y; 
    }else {
        return y;
    }
}

bool SDLC_Component::dispatch(const SDL_Event& event) {
    int intercept;
    
    if(brother) { /* 先交给兄弟结点 */
        if(brother -> dispatch(event)) {
            return true;
        }
    }

    intercept = fliterEvent(event);
    if(child && ((1 == intercept) || (2 == intercept)) )  { /*兄弟结点没有处理 交给子结点 */
        if(child -> dispatch(event)) {
            return true;
        }
    }

    if(1 == intercept && handleEvent(event)) { /* 所有结点没有处理 判断是否本结点处理 */
        return true;
    }

    if(3 == intercept)
        return true;

    return false;
}

int SDLC_Component::fliterEvent(const SDL_Event& event) {

    if(!isvisible) return 0;

    int bx = 0,by = 0;
    int tx = 0,ty = 0;
    Uint32 *bufp = NULL;
    
    if(event.type == SDL_MOUSEBUTTONDOWN) {
        bx = event.button.x;
        by = event.button.y;
        tx = abx();
        ty = aby();
        if(isContain(bx,by,tx,ty,width,height)) {
            bufp = (Uint32 *)surface->pixels + (bx-tx) + (by-ty) * surface->pitch/4;
            if(*bufp & 0xff000000) {
                return 1;
            }else  {
                return 2; /* 当前点为透明 (用来判断是否交给子控件,当前控件是透明的，而子控件不透明)*/
            }
        }
    }

    if(event.type == SDL_MOUSEBUTTONUP) {
        bx = event.button.x;
        by = event.button.y;
        tx = abx();
        ty = aby();
        if(isContain(bx,by,tx,ty,width,height)) {
            bufp = (Uint32 *)surface->pixels + (bx-tx) + (by-ty) * surface->pitch/4;
            if(*bufp & 0xff000000) {
                return 1;
            }else  {
                return 2;
            }
        } else {
            upLock = 0; /* 消除up锁定 */      
        }

    }
                                        /* 没有正在移动的对象 */
    if(event.type == SDL_MOUSEMOTION && NULL == context->curMvCmp) {
        bx = event.motion.x;
        by = event.motion.y;
        tx = abx();
        ty = aby();
        if(isContain(bx,by,tx,ty,width,height)) {
            bufp = (Uint32 *)surface->pixels + (bx-tx) + (by-ty) * surface->pitch/4;
            if(bufp &&(*bufp & 0xff000000)) {
                return 1;
            }
        }
    }
    
    return 0;
}
/* 通过了过滤器才能到这个函数 */
bool SDLC_Component::handleEvent(const SDL_Event& event) {

    if(event.type == SDL_MOUSEBUTTONUP ) {
        if(upLock == event.button.button) {
            upLock = 0; /*SDL_MOUSEBUTTONUP 和  SDL_MOUSEBUTTONDOWN 成对出现 */
            return defaultmouseButtonHandler(event,this);            
        }else {
            return false; /*  这里返回false 用来 刷新 uplock */ 
        }
    }

    if(false == defaultmouseButtonHandler(event,this)) return false; /* 先交给默认鼠标事件处理器 */

    if(event.type == SDL_MOUSEMOTION) {
        /* 产生out 事件 */
        SDLC_Component *t = context->curCmp; 
        if(t) { 
            while(t &&  t->findById(id) == NULL ){
                t->defaultOutHandler(t);
                t = t->header()->parent;
            }
        }
        // --- 
        t = context->curCmp;
        SDLC_Component * t_ = this;
        while( t_ ) {
            if(t && t_->findById(t->id)) {       
                break;
            }else {
                t_->defaultInHandler(t_);
            }
            t_ = t_->header()->parent;
        }
        context ->curCmp = this;
    }

    return true;
 
}

void SDLC_Component::setOutHandler(OutHandler handler) {
    SDLC_Component::outHandler = handler;
}
void SDLC_Component::setInHandler(InHandler handler) {
    SDLC_Component::inHandler = handler;
}

void SDLC_Component::setListener(Handler handler) {
    SDLC_Component::mouseButtonHandler = handler;
}

void SDLC_Component::display() {
    if(isvisible) updateSurface();
    SDLC_Component *tmp = this->child;
    while(tmp) {
        tmp->display();
        tmp = tmp->brother;
    }

    SDL_Rect ps = {x,y,width,height};
    if(isvisible){
        SDL_Surface* dest; 
        SDLC_Component *parent_ = header()->parent;
        if(parent_){
            dest = parent_->surface;
        }else {
            dest = context->surface;
        }
        SDL_BlitSurface(surface,NULL,dest,&ps);
    }
    else {
        return ;
    }
}

SDLC_Component* SDLC_Component::rear() {
    SDLC_Component *tmp = this;
    while (tmp->brother)
    {
        tmp = tmp -> brother;
    }
    return tmp;
}

SDLC_Component* SDLC_Component::header()
{
    SDLC_Component *tmp = this;
    while (tmp->prebrother)
    {
        tmp = tmp ->prebrother;
    }
    return tmp;
}


void SDLC_Component::updateSurface() {
    if(SDL_MUSTLOCK(surface)) {
        SDL_LockSurface(surface);
    }
    for(int i = 0; i< surface->w*surface->h; i++) {
        *((Uint32*)(surface->pixels)+i) = bgcolor;
    }
    if(SDL_MUSTLOCK(surface)) {
        SDL_UnlockSurface(surface);
    }
}

void SDLC_Component::setPostion(int x,int y) {
    this->x = x;
    this->y = y;
    context->notifyUpdate();
}

void SDLC_Component::setSize(int width,int height) {
    SDL_Surface *tmp = surface;
    surface = SDL_CreateRGBSurface(0,width,height,32,rmask,gmask,bmask,amask);
    SDL_SetSurfaceBlendMode(surface,SDL_BLENDMODE_BLEND);
    this->width = width;
    this->height = height;
    updateSurface();
    context->notifyUpdate();
    SDL_FreeSurface(tmp);
}

int SDLC_Component::getId() {
    return id;
}

bool SDLC_Component::visible() {
    return isvisible;
}

void SDLC_Component::setvisible(bool isvisible) {
    this->isvisible = isvisible;
}

void SDLC_Component::addComponent(SDLC_Component *cmp) {
    if(!cmp) return ;
    if(cmp->context != context)  {
        SDLC_LOG_.log(_2C "The Components do not match context");
        SDLC_LOG_.notice(_2C "");
        return ;
    }    
    cmp->id = context->generateId();
    if(child) {
        SDLC_Component *node = child->rear();
        node->setbrother(cmp);
    }else {
        setchild(cmp);
    }
}

void SDLC_Component::setchild(SDLC_Component *cmp) {
    if(cmp) {
        cmp->prebrother = NULL;
        cmp->parent = this;
        child = cmp;
    }else {
        child = NULL;
    }
}

void SDLC_Component::setbrother(SDLC_Component *cmp) {
    if(cmp) {
        cmp->parent = NULL;
        cmp->prebrother = this;
        brother = cmp;
    }else {
        brother = NULL;
    }
}

SDLC_Component* SDLC_Component::findById(int id) {
    if(this->id == id) {
        return this;
    }

    SDLC_Component *tmp = this->child;
    SDLC_Component *result = NULL;
    while(tmp) {
        if( ( result = tmp->findById(id) ) ){
            return result;
        }
        tmp = tmp->brother;
    }
    return result;
}

SDLC_Component* SDLC_Component::removeById(int id) {
    SDLC_Component *tmp = findById(id);
    if(tmp == NULL) return NULL;
    if(tmp->prebrother) {
        tmp->prebrother->setbrother(tmp->brother);
    }else {
        if(tmp->parent) {
            tmp->parent->setchild(tmp->brother);
        }else if(isRoot()) {
            context->components = tmp->brother;
            if(tmp->brother) {
                tmp->brother -> parent = NULL;
                tmp->brother -> prebrother = NULL;
            }
        }
    }

    tmp->parent = NULL;
    tmp->prebrother = NULL;
    tmp->brother = NULL;
    tmp->id = 0;
    return tmp;
}


int SDLC_Component::getX() { return x; }
int SDLC_Component::getY() { return y; }
int SDLC_Component::getWidth() { return width; }
int SDLC_Component::getHeight() { return height; }
SDLC_Component* SDLC_Component::getParent() { return parent; }
 
void SDLC_Component::setInterval(int i,StrickHandler h) {
    if(i >= 0) {
        interval = i;
        strickHandler = h;    
    }

}

void SDLC_Component::strick() {
    SDLC_Component *tmp = this->child;
    while(tmp) {
        tmp->strick();
        tmp = tmp->brother;
    }

    if(0 == intervalc) {    
        defaultStrickHandler(this);
    }
    
    intervalc += 1;
    intervalc %= (interval+1); 
    
}

void SDLC_Component::raise() {
    SDLC_Component* _parent = header()->parent;
    if(_parent){
        _parent->raise();
    }
    if(!canRaise) return ;
    SDLC_Component *tag = rear();
    if(tag->id == id) return ;
  
    if(this->prebrother) {
        this->prebrother->setbrother(this->brother);
    }else {
        if(this->parent) {
            this->parent->setchild(this->brother);
        }else {
            context->components = this->brother;
            if(this->brother) {
                this->brother -> parent = NULL;
                this->brother -> prebrother = NULL;
            }
        }
    }
    this->brother = NULL;
    this->parent = NULL;
    this->prebrother = NULL;
    
    tag->setbrother(this);
    context->notifyUpdate();
}

bool SDLC_Component::isRoot() {
        return (context->components  == this);
}

SDLC_Component::SDLC_Component(SDLC_Context *context):SDLC_Component(context,0,0) {}
SDLC_Component::SDLC_Component(SDLC_Context *context,int w,int h):SDLC_Component(context,0,0,w,h) {}
SDLC_Component::SDLC_Component(SDLC_Context *context,int x,int y,int w,int h):SDLC_Component(context,x,y,w,h,0xffffffff){}
SDLC_Component::SDLC_Component(SDLC_Context *context,int x,int y,int w,int h,Uint32 bg) :
                                                        id(0),
                                                        x(x),y(y),width(w),height(h),
                                                        isvisible(true),
                                                        upLock(0),
                                                        context(context),
                                                        brother(NULL),prebrother(NULL),
                                                        child(NULL),parent(NULL),
                                                        mouseButtonHandler(NULL),
                                                        outHandler(NULL),inHandler(NULL),
                                                        strickHandler(NULL),
                                                        bgcolor(bg),_movable(false),
                                                        intervalc(0),interval(0),
                                                        canRaise(true)
{
    surface = SDL_CreateRGBSurface(0,width,height,32,rmask,gmask,bmask,amask);
    SDL_SetSurfaceBlendMode(surface,SDL_BLENDMODE_BLEND);

    if(SDL_MUSTLOCK(surface)) {SDL_LockSurface(surface);}
    for(int i = 0; i< surface->w*surface->h; i++) {
        *((Uint32*)(surface->pixels)+i) = bgcolor;
    }
    if(SDL_MUSTLOCK(surface)) {SDL_UnlockSurface(surface);}
}

    /*

    Root
    |
    2----3-----4---D
    |    |     |
    5-6  7-8-9 E-F
    |            |
    A-B-C        G

    */
#ifdef DEUBG
static int  cnt = 0;
#endif

SDLC_Component::~SDLC_Component(){

        if(isRoot() || parent || prebrother) {
            removeById(id);
        }

        if(child) {

            /* 使儿子失联  */
            child -> parent = NULL;
            delete child;          
            child = NULL;
        }

        if(brother) {
            if(parent || prebrother) { /*  如果测能联系 */
                brother->prebrother = prebrother;
                brother->parent = parent;                
            } else { /* 使兄弟失联  */
                brother ->prebrother = NULL;
                delete brother;
                brother = NULL;
            }
        }
#ifdef DEBUG
        cnt ++;
        printf("delete cnt : %d, id:%d\n",cnt,id);
#endif
        if(context->curCmp == this) {
            context->curCmp = nullptr;
        }
        if(context->curMvCmp == this) {
            context->curMvCmp = nullptr;
        }
        SDL_FreeSurface(surface);

}
