#include"adapt.h"
#include<iostream>
#include"src/base.h"
#include"src/block.h"
#include"src/person.h"
#include"src/box.h"
#include"src/content.h"


#include <unistd.h> 
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
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

