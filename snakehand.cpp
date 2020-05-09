#include<stdio.h>
#include"snakehand.h"
#include<stdlib.h> 
#include"GlobalData.h"
#define CNT_W 32
#define CNT_H 24

#define delay 300

enum DIRECT{
    S_UP = 0,S_RIGHT,S_DOWN,S_LEFT
};

struct Food {
    int x;
    int y;
    int flag;
};

struct Node {
    int x;
    int y;
    struct Node *next;
};

struct Scene {
    struct Node* snake;
    enum DIRECT curDir;
    struct Food* food;
    int score;
    int cntw;
    int cnth;
    Uint32 bg;
    Uint32 snakeColor;
    Uint32 foodColor;
};
struct{
    struct Scene scene;
    int isgameover = 0; /*  0正在游戏；1表示游戏结束，但是还没有重新开始; 2重新开始 */ 

}snake_gl;

void resetFood(struct Scene *scene) {
    struct Food* food = scene->food;
    int maxw = scene ->cntw;
    int maxh = scene ->cnth;
    int x = rand() % maxw;
    int y = rand() % maxh;
    food ->x = x;
    food ->y = y;
    food->flag = 0;
}

void init(struct Scene *scene) {
    if(scene == NULL) {
        printf("init err\n");
        exit(1);
    }
    scene->cnth = CNT_H;
    scene->cntw = CNT_W;
    scene->curDir = S_LEFT;
    scene->score = 0;
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    head->x = 10;
    head->y = 10;
    head->next = NULL;
    
    struct Node *tmp = head;
    for(int i = 0; i < 3; i++) {
        tmp->next = (struct Node*)malloc(sizeof(struct Node));
        tmp->next->next =NULL;
        tmp->next->x = tmp->x+1;
        tmp->next->y = tmp->y;
        tmp= tmp->next;
    }
    scene->snake = head;
    scene->food = (struct Food*) malloc(sizeof(struct Food));
    resetFood(scene);
    scene->bg = 0x00110300;
    scene->foodColor = 0x00777777;
    scene->snakeColor = 0x00665566;
}

void draw(struct Scene *scene,SDL_Surface *surface) {
    int w = surface->w;
    int h = surface->h;
    int cw = w/scene->cntw;
    int ch = h/scene->cnth;
    SDL_Rect rect = {0,0,w,h};
    SDL_Rect rect2 = {1,1,w-2,h-2};
    SDL_FillRect(surface,&rect,0x00000000);
    SDL_FillRect(surface,&rect2,scene->bg);
    struct Node *it = scene->snake;
    int ish = 1;
    while (it)
    {
        rect.x = cw * it->x;
        rect.y = ch * it->y;
        rect.w = cw;
        rect.h = ch;
        SDL_Rect tmp = rect;
        tmp.x ++;
        tmp.y ++;
        tmp.w-=2;
        tmp.h-=2;
        if(ish) {
            ish = 0;
            SDL_FillRect(surface,&rect,0x00000000);
        }else{
            SDL_FillRect(surface,&rect,0x66666666);
        }
        SDL_FillRect(surface,&tmp,scene->snakeColor);
        it = it->next;
    }
    
    rect.x = scene->food->x * cw;
    rect.y = scene->food->y * ch;
    rect.w = cw;
    rect.h = ch;
    SDL_FillRect(surface,&rect,scene->foodColor);    
}

void move(struct Scene *scene) {
    struct Node *head = scene->snake;
    struct Node *rear = head->next;
    struct Node *prear = head;
    
    enum DIRECT dir = scene->curDir;

    while(prear->next->next) {
        prear= prear->next;
    }

    if(scene->food->x == scene->snake->x && scene->food->y == scene->snake->y) {
        rear = (struct Node*)malloc(sizeof(struct Node));
        resetFood(scene);
        scene->score ++;
        printf("%d\n",scene->score);
    }else {
        rear = prear->next;
        prear->next = NULL;
    }

    switch (dir)
    {
    case S_UP:
        rear->x = head->x;
        rear->y = head->y-1;
        rear->next = head;
        break;
    case S_RIGHT:
        rear->x = head->x+1;
        rear->y = head->y;
        rear->next = head;
        break;
    case S_DOWN:
        rear->x = head->x;
        rear->y = head->y+1;
        rear->next = head;
        break;
    case S_LEFT:
        rear->x = head->x-1;
        rear->y = head->y;
        rear->next = head;
        break;
    default:
        break;
    }

    scene->snake = rear;
    GloabalData.context.notifyUpdate(); 
}

void chageDirect(struct Scene *scene,enum DIRECT dir) {
   switch (dir)
    {
    case S_UP:
        if(scene->curDir == S_DOWN) return ;
        break;
    case S_RIGHT:
        if(scene->curDir == S_LEFT) return ;
        break;
    case S_DOWN:
        if(scene->curDir == S_UP) return ;
        break;
    case S_LEFT:
        if(scene->curDir == S_RIGHT) return ;
        break;
    }
    scene ->curDir = dir;
    move(scene);
}

int isStrikeWall(struct Scene *scene) {
    int x = scene->snake->x;
    int y = scene->snake->y;
    int w = scene->cntw;
    int h = scene->cnth;

    int isEatSelf = 0, isStrike = 0;

    if(x >= 0 && x < w && y >= 0 && y < h) {
        isStrike = 0;
    }else {
        isStrike = 1;
    }
    
    struct Node *it = scene->snake->next;
    while (it)
    {
        if( x == it->x && y == it->y) {
            isEatSelf = 1;
            break;
        }
        it = it->next;
    }

    return isEatSelf || isStrike;
}

void Destory(struct Scene* scene) {
    struct Node *tmp = scene->snake;

    while(tmp) {
        struct Node *tmp2;
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2;
    }

    free(scene->food);
    scene->snake = NULL;
    scene->food = NULL;
}


// int main(int argc,char* agrv[]) {
//     SDL_Event event; 
//     int isq = 0;
  
  
  
//     while (!isq)
//     {
// /* isq */
//     init(&scene);
//     isgameover = 0;
//     while (isgameover != 2 && !isq)
//     {
//         while(SDL_PollEvent(&event)) {
//           ;
//         }

//         if(!isgameover && SDL_GetTicks() - tick > delay) {
//             tick = SDL_GetTicks();
//         }
        
//         if(!isgameover && isStrikeWall(&scene)) {
//              isgameover = 1;
//         }
         

//         SDL_Delay(30);
//     }
//     Destory(&scene);
// /* isq */
//     }
//     SDL_DestroyWindow(w);
//     return 0;
// }

void snake_init() {
  init(&snake_gl.scene);
}
void snake_destory() {
    Destory(&snake_gl.scene);
}
/* 这是更新背景时的回调 */
void snake_draw_main(SDL_Surface *surface) {
    char title[256] = {0};
    draw(&snake_gl.scene,surface);
    sprintf(title,"贪食蛇 分数 : %5d",snake_gl.scene.score);
    SDL_SetWindowTitle(GloabalData.global_w,title); 
}

void snake_strick(SDLC_Component *cmp){
    if(snake_gl.isgameover == 0  ) {
        move(&snake_gl.scene);
        if(isStrikeWall(&snake_gl.scene)) {
            snake_gl.isgameover = 1;
        } 
    }
}

bool snake_main_hand(const SDL_Event& event,SDLC_Context *context) {
    switch (event.type)
            {
            case SDL_KEYDOWN:
            if(snake_gl.isgameover == 1) {
                snake_destory(); 
                snake_init();
                snake_gl.isgameover = 0;
            }
            else { /* ------------------- */
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        chageDirect(&snake_gl.scene,S_UP);
                                         
                        break;
                    case SDLK_RIGHT:
                        chageDirect(&snake_gl.scene,S_RIGHT);
                                   
                        break;
                    case SDLK_DOWN:
                        chageDirect(&snake_gl.scene,S_DOWN); 
                                        
                        break;
                    case SDLK_LEFT:
                        chageDirect(&snake_gl.scene,S_LEFT);
                        break;
                }
            }/* ---------------------*/
                switch (event.key.keysym.sym){
                    case SDLK_TAB:
                        GloabalData.changeHandle(1); 
                    break;  
                }
 
                break;
            case SDL_KEYUP:
                break;
            case SDL_MOUSEBUTTONDOWN:
                break;
            case SDL_MOUSEBUTTONUP:
                break;
            case SDL_QUIT: 
                GloabalData.isq =true;
                break;
            default:
                break;
            }
}
