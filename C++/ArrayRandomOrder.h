//
//  ArrayRandomOrder.h
//  C++
//
//  Created by albeeert on 10/21/16.
//  Copyright © 2016 Xinhou Jiang. All rights reserved.
//

#ifndef ArrayRandomOrder_h
#define ArrayRandomOrder_h

/*** 产生随机数组顺序1 ***/
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
    // 生成随机下标
    IndexGenerate();
    // 打印结果
    Print();
    return 0;
}


/*** 产生随机数组顺序2 ***/
#define LENGTH 25
#include <time.h>
#include <vector>
#include<iostream>
using namespace std;

// 原数组
vector<int> oldArray;
// 打乱后的数组
vector<int> newArray;

/**
 * 将数组随机打乱
 */
void RandomArray(vector<int>oldArray, vector<int> &newArray) {
    // 随机打乱
    for (int i=LENGTH; i>0; i--) {
        srand(unsigned(time(NULL)));
        // 选中的随机下标
        int index = rand()%i;
        // 根据选中的下标将原数组选中的元素push到新数组
        newArray.push_back(oldArray[index]);
        // 将原数组中选中的元素剔除
        oldArray.erase(oldArray.begin()+index);
    }
}

/**
 * 打印数组
 */
void Print() {
    cout<<"原数组：";
    for (vector<int>::iterator it = oldArray.begin() ; it!=oldArray.end() ; it++) {
        cout<<*it<<" ";
    }
    
    cout<<endl<<"打乱后的数组：";
    for (vector<int>::iterator it = newArray.begin() ; it!=newArray.end() ; it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main() {
    // 初始化原数组
    for(int i=0; i<LENGTH ;i++)
        oldArray.push_back(i);
    // 打乱
    RandomArray(oldArray, newArray);
    // 打印结果
    Print();
    return 0;
}

#endif /* ArrayRandomOrder_h */