# c++推箱子

## 操作说明

    <鼠标拖动搬运工> <点击空白处，或箱子> 控制方向
    <上、下、左、右 键> 控制方向
    <空格> <右键> 返回
    <pgup> 下一关
    <pgdn> 上一关

    另外通过的关卡，窗口标题栏会有<*>提示

## 特征

在[map.txt](https://github.com/liubailin2017/box/blob/graph/map.txt)文件中编辑地图

    自定义地图说明
    8: 目的地 ☆
    4: 墙壁  ■
    2: 箱子  □
    1: 玩家  ♀
    0: 空地
    10:箱子已在目的地  ★
    9:人在目的地上  ♂

## 演示

![加载图片请稍候...](readme_img/prtsc.gif)
[B站](https://www.bilibili.com/video/BV1Sa4y1e7nv)
## 依赖

### [SDL2](http://www.libsdl.org/download-2.0.php)

### [SDL2_image](http://www.libsdl.org/projects/SDL_image/)

## 编译

### windows

    首先你需要在 
    ./src 
    ./SDLdraw 
    ./ 
    三个目录下的 CMakeLists.txt 文件中指定 SDL2 SDL2_image目录为你电脑上对应的路径，
    
    然后请使用<cmd> cd 到源码<跟目录> 运行

    cmake cmake -G "MinGW Makefiles" .
    mingw32-make

#### NOTE

    如果不成功，请测试 

    gcc -v
    mingw32-make -v
    gdb -v

    cmake --version

    命令是否可用

### ubuntu(linux)（未测试）

    cmake .
    make

## 下载

### [windows](https://github.com/liubailin2017/box/releases/download/1.10-g/output.zip)

### [linux](https://github.com/liubailin2017/box/releases/download/ver1.1-g/box-linux.tar)
