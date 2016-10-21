//
//  ArrayRandomOrder.h
//  C++
//
//  Created by albeeert on 10/21/16.
//  Copyright © 2016 Xinhou Jiang. All rights reserved.
//

#ifndef ArrayRandomOrder_h
#define ArrayRandomOrder_h

/*** 产生随机数组顺序 ***/
#define LENGTH 25
#include <time.h>
#include <vector>
#include<iostream>
using namespace std;

// 随机下标数组
int ArrayIndexNew[LENGTH] = {0};
// 随机下标数组原始备份
int ArrayIndex[LENGTH] = {0};
// 恢复完成的原始下标数组
vector<int> DoneArray;
// 恢复完成的生成下标数组
vector<int> DoneArrayNew;
// 下标偏移纠正量
int offset = 0;

/**
 * 产生一组随机下标
 */
void IndexGenerate() {
    // 生成新的随机下标
    for (int i=0; i<LENGTH; i++) {
        srand(unsigned(time(NULL)));
        ArrayIndexNew[i] = ArrayIndex[i] = rand()%(i+1);
    }
    // 下标恢复
    DoneArray.clear();
    for (int i=LENGTH-1; i>=0; i--) {
        offset = 0;
        for (vector<int>::iterator it = DoneArray.begin(); it != DoneArray.end(); it++) {
            if (ArrayIndexNew[i] >= *it) {
                offset++;
            }
        }
        ArrayIndexNew[i] += offset;
        // 继续恢复相同的下标
        do{
            offset = 0;
            for (vector<int>::iterator it = DoneArrayNew.begin(); it != DoneArrayNew.end(); it++) {
                if (ArrayIndexNew[i] == *it) {
                    offset++;
                }
            }
            ArrayIndexNew[i] += offset;
        }while (offset);
        // 当前下标恢复完成
        DoneArrayNew.push_back(ArrayIndexNew[i]);
        DoneArray.push_back(ArrayIndex[i]);
    }
}

/**
 * 打印数组
 */
void Print() {
    cout<<"原始数组下标：";
    for (int i=0; i<LENGTH; i++) {
        cout<<ArrayIndex[i]<<" ";
    }
    
    cout<<endl<<"生成数组下标：";
    for (int i=0; i<LENGTH; i++) {
        cout<<ArrayIndexNew[i]<<" ";
    }
    cout<<endl;
}

int main() {
    IndexGenerate();
    Print();
    return 0;
}

#endif /* ArrayRandomOrder_h */
