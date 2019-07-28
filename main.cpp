#include<iostream>
#include"src/base.h"
#include"src/block.h"
#include"src/person.h"
#include"src/box.h"
#include"src/content.h"

#include"adapt.h"

using namespace std;

void init() {
	#if defined (__WIN32) /*解决 win下unicode乱码问题*/
	system("@CHCP 65001");
	system("@cls");
	#endif
}
#include"src/_maps.h"
int main(int argc,char* argv[]) {
    init();
    bool isq = false;
    int _LEVEL = sizeof(_MAPS_def)/_SIZE;
    for(int leve = 0; leve<_LEVEL && !isq; leve++) {
        map m;   
        m.read(_MAPS_def[leve]);
        content c(&m);
        char in;
        bool isf = false;
        while(!isq && !isf) {
            clear_sc();
            std::cout<<"关卡"<<(leve)<<std::endl;
            c.display();
            std::cout << "****回退(b)方向控制（asdw)****"<<std::endl;

            in = getch();
        
            switch (in)
            {
                case 'w' :
                case 'W' :
                c.actinput(UP);
                break;
                case 's' :
                case 'S' :
                    c.actinput(DOWN);
                    break;
                case 'a' :
                case 'A' :
                    c.actinput(LEFT);
                    break;
                case 'd' :
                case 'D' :
                    c.actinput(RIGHT);
                    break;
                case 'b':
                case 'B':
                    c.back();
                    break;
                case 'q':
                case 'Q':
                    isq = true;
                    break;
                default:
                    break;
            }
            isf = c.isfinsh();
        }

        if(!isq) {
            map rm;   
            rm.read(_MAPS_def[leve]);
            content rc(&rm);
            int tmp;
            int s = 3000/c.msize();
            while( (tmp = c.popf()) != -1) {
                direct d = (direct)((~_PUSH_BYTE) & tmp);
                rc.actinput(d);
                _mdelay(1000*s);
                clear_sc();
                rc.display(); 
                std::cout<<"***回放***"<<endl;
            }
            std::cout<<"press any key to contine."<<endl;
            getch();
        }

    }

    if(!isq)
        std::cout << "恭喜你,完成了所有关卡!"<<std::endl;
    else 
        std::cout <<"再见!"<<std::endl;
    getch();
    return 0;
}
