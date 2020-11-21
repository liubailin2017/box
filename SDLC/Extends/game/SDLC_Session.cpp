#include"SDLC_Session.h"
#include"../../SDLC_Context.h"



SDLC_Session::SDLC_Session(SDLC_Context *context,OnFinish onf):
SDLC_Component(context),
label1(context,""),label2(context,""),label3(context,16,""),
bg(context){
    onfinish = onf;
    addComponent(&bg);
    bg.addComponent(&label1);
    bg.addComponent(&label2);
    bg.addComponent(&label3);
    label1.setPostion(0,0);
    label2.setPostion(0,20);
    label3.setPostion(0,40);

    bg.load("session.png");
    bg.setPostion(50,0);
    
    /* 在最下面显示*/
    setPostion(0,context->getHeight() - 100);
    setSize(context->getWidth(),context->getHeight());
    charCntOfLines = 10;
}

/* 可以在这实现一些动画效果 */
//virtual void SDLC_SessiondefaultStrickHandler(SDLC_Component *cmp);
/* 点击时切换没显示完的文字 */

bool SDLC_Session::defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp) {
    SDLC_Component::defaultmouseButtonHandler(event,cmp);
}

void SDLC_Session::Show(std::string msg) {
    remain_msg = msg;
    if(remain_msg.length() > charCntOfLines) {
        label1.setText(remain_msg.substr(0,charCntOfLines));
        remain_msg = remain_msg.substr(charCntOfLines,remain_msg.length()-charCntOfLines);
    } else {
        label1.setText(remain_msg);
        remain_msg = "";
    }
    
    if(remain_msg.length() > charCntOfLines) {
        label2.setText(remain_msg.substr(0,charCntOfLines));
        remain_msg = remain_msg.substr(charCntOfLines,remain_msg.length()-charCntOfLines);
    } else {
        label2.setText(remain_msg);
        remain_msg = "";
    }
    
    if(remain_msg.length() > charCntOfLines) {
        label3.setText(remain_msg.substr(0,charCntOfLines));
        remain_msg = remain_msg.substr(charCntOfLines,remain_msg.length()-charCntOfLines);
    } else {
        label3.setText(remain_msg);
        remain_msg = "";
    }


}

//    void SDLC_Session::Show(SDLC_Image*head,std::string *msg); /* 显示头像和文字 */
//    void SDLC_Session::Show(SDLC_Image *head,std::string *msg,Handler cb); /* 带两个按键的对话框 */