/********************************************************************
* File: array.cpp
* Description: Implement the functions defined by the header file.s
* Version: 1.0.0
* Author: MrLiu,652455342@qq.com
* Date:2024/06/16 18:17:00
********************************************************************/

#include "array.h"

/**
* @brief: Constructor function, assignment.
* @param param1 (int): default array size, user passes in custom parameters.
* @throws none: none
* @date:2024/06/16 19:13:48
*/
Array::Array(int size)
{
    this->mCap = size;
    this->mCur = 0;
    this->mpArr = new int[this->mCap]();
}

/**
* @brief: Destructors function, free up memory.
* @date:2024/06/16 19:16:44
*/
Array::~Array()
{
    delete []this->mpArr;
    this->mpArr = nullptr;
}

/**
* @brief: Expanded the array.
* @param param1 (int): Expanded capacity.
* @throws none: none.
* @date:2024/06/16 19:17:49
*/
int Array::expend(int size)
{
    int *p = new int[size]();
    memcpy(p,this->mpArr,sizeof(2 * this->mCap));
    delete []this->mpArr;
    this->mCap = size;
    this->mpArr = p;
    return 1;
}

/**
 * @bried: push back element.
 * @param param1 (int): push back element.
 * @throws none: none.
 * @date: 2024/06/16 19:17:49
*/
int Array::push_back(int val)
{
    if(this->mCur == this->mCap) {
        expend(2 * this->mCap);
    }
    this->mpArr[this->mCur] = val;
    this->mCur++;
    return 1;
}

/**
* @brief: Tail deletes and returns to delete the element.
* @param param1 (int*): return the element's address. 
* @throws none: none.
* @date:2024/06/16 19:21:46
*/
int Array::pop_back(int *ele) 
{
    if(this->mCur == 0) {
        return 0;
    }
    *ele = this->mpArr[--mCur];
    return 1;
}

/**
* @brief: insert element by pos.
* @param param1 (int): pos.
* @param param2 (int): val.
* @throws string: pos is no ok.
* @date:2024/06/16 19:23:32
*/
int Array::insert(int pos, int val)
{
    if(pos < 0 || pos > this->mCur) {
        throw "pos is no";
        return 0;
    }

    for(int i = this->mCur;i >= pos; i--) {
        this->mpArr[i] = this->mpArr[i - 1];
    }

    this->mpArr[pos] = val;
    this->mCur++;
    return 1;
}

int Array::easer(int pos)
{
    if(pos < 0 || pos >= this->mCur) {
        throw "pos is not ok";
        return 0;
    }
    for(int i = pos; i < this->mCur; i++) {
        this->mpArr[i] = this->mpArr[i + 1];
    }
    this->mCur--;
    return 1;
}

int Array::find(int val)
{
    int index = -1;
    for(int i = 0; i < this->mCur; i++) {
        if(this->mpArr[i] == val) {
            index = i;
            return index;
        }
    }
    return -1;
}

/**
* @brief: show Data.
* @date:2024/06/16 19:24:49
*/
void Array::showData()
{
    std::cout << "array element nums: " << this->mCur << std::endl;
    std::cout << "array element cap: " << this->mCap << std::endl;
    std::cout << "element: " << std::endl;
    for(int i = 0;i < this->mCur; i++) {
        std::cout << this->mpArr[i] << std::endl;
    }
}
