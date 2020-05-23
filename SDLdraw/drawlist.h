class palette;

class block;

/* 加载图片资源文件 */
void drawlist_init_img();

/* 在 palette (模版) 上绘制一个 obj*/
void drawobj(palette* p,block* obj);
struct SDL_Surface;
/* 把 模版上的surface 复制到 surface 上 */
void SDLdraw_update(SDL_Surface *surface);
