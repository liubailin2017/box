#include<iostream>
#include"base.h"
#include"block.h"
#include"person.h"
#include"box.h"
#include"content.h"
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h> 
#include<time.h>
#ifdef _WIN32
    #include<conio.h>
    #define clear_sc() system("cls") 
#else
    #define clear_sc() system("clear")
    char getch();
#endif

void   _mdelay(int   time);
#include"_maps.h"
using namespace std;
void init() {
	#if defined (__WIN32) /*解决 win下unicode乱码问题*/
	system("@CHCP 65001");
	system("@cls");
	#endif
}
 
int main() {
//  init();
    bool isq = false;
    int _LEVEL = sizeof(_MAPS_def)/ sizeof(_MAPS_def[0]);
    for(int leve = 0; leve<_LEVEL && !isq; leve++) {
        map m;   
        m.read(_MAPS_def[leve]);
        content c(&m);
        char in;
        bool isf = false;
        while(!isq && !isf) {
            clear_sc();
            std::cout<<"leve:("<<(leve+1)<<"/"<< _LEVEL <<")"<<std::endl;
            c.display();
            std::cout << "****back(b) move(asdw)****"<<std::endl;

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
                std::cout<<"***play record***"<<endl;
            }
            std::cout<<"press any key to contine."<<endl;
            getch();
        }
    }

    if(!isq)
        std::cout << "You have completed all the leves!"<<std::endl;
    else 
        std::cout <<"bye!"<<std::endl;
    getch();
    return 0;
}

void   _mdelay(int   time)
{ 
#ifdef _WIN32
	time /= 1000;
#endif
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

