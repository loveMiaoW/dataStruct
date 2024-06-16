
/********************************************************************
* File: array.h
* Description: Header file about array, define some functions and member variables.
* Version: 1.0.0
* Author: MrLiu,652455342@qq.com
* Date:2024/06/16 18:03:59
********************************************************************/

#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <iostream>

class Array {
public:
    Array(int size = 10);
    ~Array();

public:
    int push_back(int val);
    int pop_back(int *ele);
    int insert(int pos,int val);
    int easer(int pos);
    int find(int val);
    void showData();
private:
    int expend(int size);
private:
    int *mpArr;
    int mCap;
    int mCur;
};

#endif //__ARRAY_H__