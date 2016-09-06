//
//  main.cpp
//  C++
//
//  Created by Xinhou Jiang on 6/11/16.
//  Copyright © 2016 Xinhou Jiang. All rights reserved.
//
#include <iostream>
//#include <math.h>
#include <vector>    // 向量
#include "Sort.hpp"  // 排序算法
#include <thread>    // 线程
using namespace std;

void Hello(){
    cout<<"hello multi-thread!"<<endl;
}

int main()
{
    /**
     * 排序算法测试
     */
    Sort sort;
    //sort.bubblesort(sort.sortArray, sort.length);
    sort.selectsort(sort.sortArray, sort.length);
    
    /**
     * 向量的简单使用方法
     */
    // 定义int型向量
    vector<int>v;
    // 添加向量元素
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // 删除向量末尾元素
    v.pop_back();
    // 向量迭代器，遍历向量元素
    vector<int>::iterator iter;
    cout<<"向量测试结果:";
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    
    
    /**
     * 多线程
     */
    thread t(Hello);
    t.join();
    
    return 0;
}