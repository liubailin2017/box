#ifndef _customadapt_h_
#define _customadapt_h_
#include <stdio.h>
#ifdef _WIN32
    #include<conio.h>
    #define clear_sc() system("cls") 
#else
    #define clear_sc() system("clear")
    char getch();
#endif
void   _mdelay(int   time);
#endif