class palette;

class block;
/* 加载图片资源文件 */
void drawlist_init_img();

/* 在 palette (模版) 上绘制一个 obj*/
void drawobj(palette* p,block* obj);

/* 把 模版上的surface 复制到 窗口上 */
void SDLdraw_update();
