#ifndef _h_base_
#define _h_base_
enum direct {UP,RIGHT,DOWN,LEFT};
enum type {BLOCK = 0, PERSON = 1,BOX = 2,WALL = 4,INTEND = 8};
#define _PUSH_BYTE  128
#endif

#ifndef nullptr
#define nullptr 0
#endif
#ifdef _WIN32
#define B0 "  "
#else
#define B0 " "
#endif
#define B1 "♀"
#define B2 "□"
#define B4 "■"
#define B8 "☆"
#define B10 "★"
#define B9 "♂"
#define Er "E"
