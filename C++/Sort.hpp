//
//  Sort Algorithm.hpp
//  C++
//
//  Created by Xinhou Jiang on 16/9/6.
//  Copyright © 2016年 Xinhou Jiang. All rights reserved.
//
#include <iostream>
#define ArrCount 8 // 待排序数组长度

#ifndef Sort_Algorithm_hpp
#define Sort_Algorithm_hpp

class Sort {
    
public:
    int length;
    int *sortArray;
    
    Sort();
    ~Sort();
    
    // 打印
    void print(int *list);
    
    // 1.冒泡排序(升序，大者后冒)
    void bubblesort(int *list, int count);
    
    // 2.选择排序
    // 算法思想（升序）：从第一个元素开始，依次与后面未排序的元素比较选择最小的元素交换位置，自身最小不交换
    void selectsort(int *list,int count);
    
};

/**
 * 排序算法测试
 */
//Sort sort;
//sort.bubblesort(sort.sortArray, sort.length);
//sort.selectsort(sort.sortArray, sort.length);

#endif /* Sort_Algorithm_hpp */
