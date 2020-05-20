#include<math.h>
#include<stdio.h>
#include"sdltool.h"
namespace sdltool {
int rounding(const float a){return (int) (a + 0.5);}

int Putpixel(SDL_Surface *surface, int Px, int Py,Uint32 color)
{
    switch(surface->format->BytesPerPixel)
    {
    case 4 :
    {
        Uint32 *bufp;
        if( Px < surface->pitch/4 && Px >= 0 &&
                Py < surface->h && Py >= 0)
        {
            if(SDL_MUSTLOCK(surface))
                if(SDL_LockSurface(surface) < 0)
                    return 0;
            bufp = (Uint32 *)surface->pixels + Px + Py * surface->pitch/4;
            *bufp = color;
            if(SDL_MUSTLOCK(surface))
            {
                SDL_UnlockSurface(surface);
            }
            return 1 ;    /*  ********** !è¿å ************/
        }
        else
            return 0 ;
    }
    break;
    default :
        printf("sdl2 Unsupported\n");
    }
    return 0;
}

void line(SDL_Surface *surface,int x0, int y0, int xEnd, int yEnd,Uint32 color,int width)
{
    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
    float xInc, yInc, x = (float)x0, y = (float)y0;
    int wy = 1, wx = 1;
    if(fabs(dx)>fabs(dy))
    {
        wy = width;
         steps = fabs(dx);
    }
    else
    {
        wx = width;
         steps = fabs(dy);
    }
 //   printf("x0:%d ,y0:%d x1:%d y1:%d ,steps:%d\n",x0,y0,xEnd,yEnd,steps);

    xInc = (float)(dx)/(float)(steps);
    yInc = (float)(dy)/(float)(steps);
    Putpixel(surface,rounding(x),rounding(y),color);
    for(k=0;k<steps;k++)
    {
         x += xInc;
         y += yInc;
         for(int i = 0; i<wx;i++)
         {
            for(int j = 0; j < wy ;j ++)
            {
                Putpixel(surface,rounding(x+i-wx/2),rounding(y+j-wy/2),color);
            }
         }
    }
}
}