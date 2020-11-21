#include"SDLC_Msgbox.h"
#include"SDLC_Label.h"
#include"SDLC_Button.h"

/* 特制 Button */
class SDLC_Button_special:public SDLC_Button {
    private:
    SDLC_Msgbox *msgbox;
    public :
    SDLC_Button_special(SDLC_Context *context,char *text):SDLC_Button(context,text),msgbox(NULL) {}
    SDLC_Button_special(SDLC_Context *context,char *text,Uint32 bg):SDLC_Button(context,text,bg),msgbox(NULL){}
    SDLC_Button_special(SDLC_Context *context,char *text,int size, Uint32 bg):SDLC_Button(context,text,size,bg),msgbox(NULL){}
    /* 内部处理，比如内部实现移动，out/in事件等功能 */
    virtual bool handleEvent(const SDL_Event& event) {
        if(false == SDLC_Component::handleEvent(event)) { return false;}
        if(event.type == SDL_MOUSEBUTTONUP) {
            if(msgbox) msgbox -> setvisible(false);
        }
    }
    void setMsgBox(SDLC_Msgbox *mg) {
        msgbox = mg;
    }

};

static char *def_strs[] =  {"确定","取消"};
SDLC_Msgbox::SDLC_Msgbox(SDLC_Context *context):SDLC_Com_Radius(context,200,120) {
    setbgcolor(0xff333333);
    setRadius(10);
    setMovable(true);
    SDLC_Label *slb = new SDLC_Label(context,18,"");
    slb->setPostion((getWidth()- slb->getWidth())/2,10);
    
    addComponent(slb);
    label = slb;
        SDLC_Button_special *btn = new SDLC_Button_special(context,def_strs[0],0xff3345AB);
        btn->setMsgBox(this);
        btn->btnflag = 0;
         
        btn->setPostion(10,80);
        btn1 =(SDLC_Button*)btn; 
        addComponent(btn);
        btn = new SDLC_Button_special(context,def_strs[1],0xff33AB45);
        btn->setMsgBox(this);
        btn->btnflag = 1;
    
        btn->setPostion(200-btn->getWidth()-10,80);
        btn2 = (SDLC_Button*)btn;
        addComponent(btn);
    setPostion((context->getWidth() - getWidth())/2,(context->getHeight()-getHeight())/2);
    this->setvisible(false);
}

 

// int SDLC_Msgbox::fliterEvent(const SDL_Event& event){
//     return true;
// }

SDLC_Msgbox::~SDLC_Msgbox() {
}

void SDLC_Msgbox::show(char *msg,Handler cb) {
    label->setText(msg);
    btn1->setListener(cb);
    btn2->setListener(cb);
    label->setPostion((getWidth()- label->getWidth())/2,10);
    
    setvisible(true);
    raise();
}
