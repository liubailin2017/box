#include"SDLC_Session.h"
#include"../../SDLC_Context.h"



SDLC_Session::SDLC_Session(SDLC_Context *context,OnFinish onf):
    SDLC_Component(context),
    label1(new SDLC_WLabel(context,16,L"")),
    label2(new SDLC_WLabel(context,16,L"")),
    label3(new SDLC_WLabel(context,16,L"")),
    btn1(new SDLC_Button(context,"是",0xffff5566)),btn2(new SDLC_Button(context,"否",0xff55ff66)),
    headImg(nullptr),
    headHeight(0),
    defHeight(100)
{
    onfinish = onf;

    addComponent(btn1);
    addComponent(btn2);
    btn1->setTooltip(L"选择就表示你同意");
    btn2->setTooltip(L"选择就表示你不同意");
    addComponent(label1);
    addComponent(label2);
    addComponent(label3);
    

    btn1->setPostion(context->getWidth()-100,10);
    btn2->setPostion(context->getWidth()-100,50);
    

    printf("id1 = %d  id2 = %d \n",btn1->getId(),btn2->getId());
    setbgcolor(0x5566ff66);

    
    /* 在最下面显示*/
    setPostion(0,context->getHeight() - defHeight);
    setSize(context->getWidth(),defHeight);
    charCntOfLines = 30;
    setvisible(false);
}

/* 可以在这实现一些动画效果 */
//virtual void SDLC_SessiondefaultStrickHandler(SDLC_Component *cmp);
/* 点击时切换没显示完的文字 */

bool SDLC_Session::defaultmouseButtonHandler(const SDL_Event& event,SDLC_Component *cmp) {
    
    if(event.type == SDL_MOUSEBUTTONDOWN) {
        if(btn1->visible() == false) { /* 当可操作的按钮没有时才换页，否则等待按钮的事件 */
            if (remain_msg.length() > 0) {
                Show(headImg, remain_msg,onSelected);
            }else {
                setvisible(false);
                if(onfinish) {
                    onfinish(id);
                }
            }
        }
    }
    return SDLC_Component::defaultmouseButtonHandler(event,cmp);
}

/* 图像超出部分，背景透明 */
void SDLC_Session::updateSurface() {
    if(SDL_MUSTLOCK(surface)) {
        SDL_LockSurface(surface);
    }
    int outLines = 0; 
    if(headHeight > defHeight) {
        for(int i = 0; i< surface->w*(headHeight-defHeight); i++) {
            *((Uint32*)(surface->pixels)+i) = 0; //透明色
        }
        outLines = headHeight - defHeight;
    }
    int offset = surface->w * outLines;
    for(int i = 0; i < surface->w * defHeight ; i++) {
        *((Uint32*)(surface->pixels)+(i + offset)) = bgcolor;
    }
    
    if(SDL_MUSTLOCK(surface)){
        SDL_UnlockSurface(surface);
    }
}

void SDLC_Session::Show(std::wstring msg) {
    Show(nullptr,msg);
}

void SDLC_Session::Show(SDLC_Image*head,std::wstring msg) {
    Show(head,msg,nullptr);
}


void SDLC_Session::Show(SDLC_Image *head,std::wstring msg,Handler cb) {
    if(headImg) {
        removeById(headImg->getId());
    }
    
    headImg = head;
    onSelected = cb;

    btn1->btnflag = 0;
    btn2->btnflag = 1;
    btn1->setListener(onSelected);
    btn2->setListener(onSelected);
    if(headImg) { /* 如果有头像，根据头像调整高度 */ 
        addComponent(headImg);
        headHeight = headImg->getHeight();
        if( headHeight > defHeight) {
            setSize(getWidth(),headHeight); 
        } else {
            setSize(getWidth(),defHeight);
        }
    }else {
        setSize(getWidth(),defHeight);
    }
    setPostion(0,context->getHeight() - getHeight()); //始终位于最底部

    remain_msg = msg;
    if(remain_msg.length() > charCntOfLines) {
        label1->setText(remain_msg.substr(0,charCntOfLines));
        remain_msg = remain_msg.substr(charCntOfLines,remain_msg.length()-charCntOfLines);
    } else {
        label1->setText(remain_msg);
        remain_msg = L"";
    }
    
    if(remain_msg.length() > charCntOfLines) {
        label2->setText(remain_msg.substr(0,charCntOfLines));
        remain_msg = remain_msg.substr(charCntOfLines,remain_msg.length()-charCntOfLines);
    } else {
        label2->setText(remain_msg);
        remain_msg = L"";
    }
    
    if(remain_msg.length() > charCntOfLines) {
        label3->setText(remain_msg.substr(0,charCntOfLines));
        remain_msg = remain_msg.substr(charCntOfLines,remain_msg.length()-charCntOfLines);
    } else {
        label3->setText(remain_msg);
        remain_msg = L"";
    }

    if(remain_msg.length() > 0 || nullptr == onSelected) {
        btn1->setvisible(false);
        btn2->setvisible(false);
    } else {
        btn1->setvisible(true);
        btn2->setvisible(true);
    }

    if(headImg) { /* 适配头像高度 */
        int outLines = headHeight - defHeight;
        if( outLines < 0) outLines = 0;
        label1->setPostion(headImg->getWidth(),outLines+ 10);
        label2->setPostion(headImg->getWidth(),outLines+30);
        label3->setPostion(headImg->getWidth(),outLines+50);

        btn1->setPostion(context->getWidth()-100,outLines+10);
        btn2->setPostion(context->getWidth()-100,outLines+50);
    
    }else {
        label1->setPostion(10,0);
        label2->setPostion(10,20);
        label3->setPostion(10,40);

        btn1->setPostion(context->getWidth()-100,10);
        btn2->setPostion(context->getWidth()-100,50);
    
    }

    setvisible(true);
}


