#include<iostream>
#include"../bfs.h"
int test() {
    tool::queue<int> qint;
    qint.push(4321);
    std::cout <<qint.peek()<<std::endl;
    return 0;
}

