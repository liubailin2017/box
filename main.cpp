#include<iostream>
#include<string>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<math.h>

int _WIDTH =960;
int _HEIGHT =640;


#include"src/base.h"
#include"src/block.h"
#include"src/person.h"
#include"src/box.h"
#include"src/content.h"


#include"SDLdraw/palette.h"
#include"SDLdraw/drawlist.h"

palette global_palette;
SDL_Window* global_w; 

#include"src/_maps.h"

void loadleve(int leve,content &c);
void main_init();

int main(int argc,char* agrv[]) {

    int isq = false;

    main_init();

    SDL_Event event;
    int leve = 0;

    int mleve  = sizeof(_MAPS_def)/(_SIZE*sizeof(int));
    map m; 
    content c(&m);

    loadleve(leve,c);
    global_palette.reset();
    c.display();
    int cwid=_WIDTH,chei=_HEIGHT;

    while (!isq)
    {
        while(SDL_PollEvent(&event)) {
            
            SDL_GetWindowSize(global_w,&_WIDTH,&_HEIGHT);
            if( !(cwid == _WIDTH && _HEIGHT == chei)) {
                global_palette.setsize(_WIDTH/m._w(),_HEIGHT/m._h());
                cwid = _WIDTH;
                chei =_HEIGHT;
                std::cout<<"resize"<<std::endl;
            }
            
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_UP:
                            c.actinput(UP);
                            break;
                        case SDLK_LEFT:
                            c.actinput(LEFT);
                            break;
                        case SDLK_RIGHT:
                            c.actinput(RIGHT);
                            break;
                        case SDLK_DOWN:
                            c.actinput(DOWN);
                            break;
                        case SDLK_SPACE:
                            c.back();
                            break;
                        case SDLK_PAGEUP:
                            if(leve < mleve-1) { 
                                ++leve;
                                loadleve(leve,c);
                            }
                            break;
                        case SDLK_PAGEDOWN:
                            if(leve>0) {
                                leve--;
                                loadleve(leve,c);
                            }
                            break;
                        default:
                            break;
                    }

                    if(c.isfinsh()){
                        flag[leve] = '*';
                        leve++;
                        leve %= mleve;
                        loadleve(leve,c);
                    }

                    global_palette.reset();
                    c.display();

                    break;
                case SDL_QUIT: 
                    isq =true;
                    break;
                default:
                    break;
            }
        }
        SDLdraw_updateWindow();
    }
    
    SDL_DestroyWindow(global_w);
    
    FILE* f = fopen("data.sav","wb+");
    if(f){
        fwrite(flag,sizeof(flag),1,f);
        fclose(f);
    }

    return 0;
}


void loadleve(int leve,content &c) {
    std::string title;
    c.getmap()->read(_MAPS_def[leve]);
    palette p(c.getmap()->_w(),c.getmap()->_h(),_WIDTH/c.getmap()->_w(),_HEIGHT/c.getmap()->_h());
    global_palette = p;
    c.init();
    title = "level:"+std::to_string(leve+1)+"    "+flag[leve];
    SDL_SetWindowTitle(global_w,title.c_str());
}

void main_init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    drawlist_init_img();
    SDL_Window* w = SDL_CreateWindow("hello,world",
                                    SDL_UNSUPPORTED,SDLK_UNDERSCORE,
                                    _WIDTH,_HEIGHT,
                                    SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
    global_w = w;
    
    FILE *f = fopen("data.sav","rb+");
    if(f){
        fread(flag,sizeof(flag),1,f);
        fclose(f);
    }
}
