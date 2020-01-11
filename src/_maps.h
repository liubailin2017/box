
/* 
自定义地图
 8: 目的地 ☆
 4: 墙壁  ■
 2: 箱子  □
 1: 玩家  ♀
 0: 空地
 10:箱子已在目的地  ★
 9:人在目的地上  ♂ 
 */

/**最外面一圈只能使用墙壁(4)*/
extern char flag[100];
#define _SIZE 450
#define _LEN 8
extern int _MAPS_def[][_SIZE/*28*16*/];
