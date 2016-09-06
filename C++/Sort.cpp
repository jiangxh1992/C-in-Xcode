//
//  Sort Algorithm.cpp
//  C++
//
//  Created by Xinhou Jiang on 16/9/6.
//  Copyright © 2016年 Xinhou Jiang. All rights reserved.
//

#include "Sort.hpp"

Sort::Sort(){
    length = ArrCount;
    
    int arr[ArrCount] = {2,4,1,3,6,5,0,7};
    sortArray = new int[length];
    for (int i = 0; i<length; i++) {
        sortArray[i] = arr[i];
    }
}

Sort::~Sort(){
    std::cout<<"destrctor!"<<std::endl;
}

// 打印
void Sort::print(int *list){
    
    for(int i=0;i<length;i++)
        std::cout<<list[i]<<" ";
    std::cout<<std::endl;
}

// 1.冒泡排序(升序，大者后冒)
void Sort::bubblesort(int *list, int count)
{
    std::cout<<"冒泡排序前：";
    print(list);
    for (int i=0;i<count;i++)
    {
        for (int j=0; j<count-i-1; j++)
        {
            if (list[j+1]<list[j])
            {
                int tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
    }
    std::cout<<"冒泡排序结果：";
    print(list);
}

// 2.选择排序
// 算法思想（升序）：从第一个元素开始，依次与后面未排序的元素比较选择最小的元素交换位置，自身最小不交换
void Sort::selectsort(int *list,int count)
{
    std::cout<<"选择排序前：";
    print(list);
    // 从第一个开始依次对每一个元素排序
    for(int i=0;i<count-1;i++)
    {
        // 从未排序的元素中选择最小元素
        int k=i;
        for(int j=i+1;j<count;j++)
            if(list[j]<list[k])
                k=j;
        // 如果不是自身最小则交换
        if(k!=i)
        {
            int tmp=list[i];
            list[i]=list[k];
            list[k]=tmp;
        }
    }
    std::cout<<"选择排序结果：";
    print(list);
}