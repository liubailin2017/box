
#include"../../SDLC_Component.h"
#include"../Image.h"
#include"../SDLC_Label.h"

#include"../SDLC_Button.h"

/*
  对话框,用来显示角色间的对话
*/


/* 

这个函数是当显示完成了，的回调
比如一个角色正在说话，说完后就调用这个函数，这个函数可以通知说： 嘿，我说完了，该你说了
*/

typedef void(*OnFinish)(int id);

class SDLC_Session : public SDLC_Component
{
private:
    int charCntOfLines; /* 每一行显示的字数*/ 
    OnFinish onfinish;
    /* 只允许显示3行*/
    SDLC_Label* label1;
    SDLC_Label* label2;
    SDLC_Label* label3;
    /* 头像 */
    SDLC_Image*headImg;

    SDLC_Button *btn1;
    SDLC_Button *btn2;
    

    std::string remain_msg;
    int headHeight;//头像高度
    int defHeight;
public:
    
    virtual void updateSurface();
    SDLC_Session(SDLC_Context *context,OnFinish onf);
    /* 可以在这实现一些动画效果 */
    //virtual void defaultStrickHandler(SDLC_Component *cmp);
    /* 点击时切换没显示完的文字 */
    virtual bool defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp);

    void Show(std::string msg); /* 只显示文字 */
    void Show(SDLC_Image*head,std::string msg); /* 显示头像和文字 */
    void Show(SDLC_Image *head,std::string msg,std::string btn1Text,std::string btn2Text,Handler cb); /* 带两个按键的对话框 */

};
