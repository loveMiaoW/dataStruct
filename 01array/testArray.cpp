/********************************************************************
* File: testArray.cpp
* Description: Test class array.
* Version: 1.0.0
* Author: MrLiu,652455342@qq.com
* Date:2024/06/16 19:12:30
********************************************************************/

#include "array.h"

int main(int argc, char** argv)
{
    Array arr;
    for(int i = 0; i < 10; i++) {
        arr.push_back(i);
        std::cout << i <<  " insert is ok" << std::endl; 
    }

    arr.showData();

    int delEle;
    for(int i = 0; i < 3; i++) {
        arr.pop_back(&delEle);
        std::cout << "del element is: " << delEle << std::endl;
    }
    std::cout << delEle<< std::endl;
    arr.showData();


    arr.insert(0,111);
    arr.insert(1,111111);
    arr.insert(5,80);
    arr.showData();

    std::cout << "easer"<< std::endl;
    for(int i = 0; i < 3; i++) {
        arr.easer(0);
    }
    arr.showData();
    return 0;
}