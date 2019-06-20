#include<iostream>
#include"base.h"
#include"block.h"
#include"person.h"
#include"box.h"
#include"content.h"
#include<stdio.h>
#include<stdlib.h>

#ifdef _WIN32
    #include<conio.h>
#define clear_sc() system("cls") 
#else
#define clear_sc() system("clear")
#include <unistd.h> 

char getch();
#endif
void   _mdelay(int   time);

#include"_maps.h"
using namespace std;
int main() {
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

void   _mdelay(int   time)
{ 
    clock_t   now   =   clock(); 

    while(   clock()   -   now   <   time   ); 
} 

#ifdef _WIN32
    
#else
#include <termio.h>
char getch(void)
{
     struct termios tm, tm_old;
     int fd = 0, ch;
 
     if (tcgetattr(fd, &tm) < 0) {
          return -1;
     }
 
     tm_old = tm;
     cfmakeraw(&tm);
     if (tcsetattr(fd, TCSANOW, &tm) < 0) {
          return -1;
     }
 
     ch = getchar();
     if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {
          return -1;
     }
    
     return ch;
} 
#endif