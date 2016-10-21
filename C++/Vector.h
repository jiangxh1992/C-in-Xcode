//
//  Vector.h
//  C++
//
//  Created by albeeert on 10/16/16.
//  Copyright © 2016 Xinhou Jiang. All rights reserved.
//
#ifndef Vector_h
#define Vector_h

#include <iostream>
#include <vector>        // 向量
#include <algorithm>
using namespace std;
/**
 * 向量的简单使用方法
 */
int main(){
    // 定义int型向量
    vector<int>v;
    // 添加向量元素
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    cout<<v.empty()<<endl;
    cout<<v.size()<<endl;
    
    // 向量迭代器，遍历向量元素
    vector<int>::iterator iter;
    cout<<"向量测试结果:";
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    return 0;
}


/** 1.vector向量的创建与初始化 **/
// 创建一个int型的向量，不指定长度
vector<int> vint;
// 创建一个double型的向量，指定长度为10
vector<double> vdouble(10);
// 创建一个float类型的向量并初始化，指定长度为10，每个元素初始值都为3.14
vector<float> vfloat(10,3.14);

/** 2.尾部元素的扩张 **/
// vector是一个动态可伸缩的泛型数组，自带内存分配管理功能，通过push_back函数可以不断在尾部添加新元素
v.push_back(1);
v.push_back(2);
v.push_back(3);

/** 3. vector元素的访问**/
// 可以使用[]操作符下标访问
cout<<v[3]<<endl;
// 可以使用迭代器访问，迭代器是一个指针，通过*访问其元素
vector<int>::iterator iter;
for (iter = v.begin(); iter != v.end(); iter++) {
    cout<<*iter<<" ";
}

/** 元素的插入：insert **/
// insert可以在vector任意位置插入新元素，第一个参数是迭代器位置而不是下标，第二个参数是新元素
// 在第0个元素前插入新元素9，9成为第0个元素
v.insert(v.begin(),9);
// 在第2个元素前面插入新元素9，9成为第2个元素
v.insert(v.begin()+2,9);
// 在最后一个元素后面插入新元素9，9成为最后一个元素
v.insert(v.end(),9);

/** 元素的删除：erase、clear **/
// 删除第2个元素
v.erase(v.begin()+2);
// 删除第0个元素到第2个元素之间的所有元素，包括第0个元素，但不包括第2个元素
v.erase(v.begin(),v.begin()+2);
// 清空所有元素
v.clear();

/** 向量元素的反向排序：reverse **/
// reverse反向排序算法函数要添加算法头文件：#include<algorithm>
reverse(v.begin(), v.end());

/** 向量排序算法：sort **/
// sort跟reverse在一个头文件里，使用前也要引入algorithm头文件
// 默认的排序为升序排序
sort(v.begin(),v.end());
// 降序排序需要自定义sort算法
bool Compare(const int &a, const int &b){
    return a>b;
}
sort(v.begin(),v.end(),Compare);

/** 向量的大小 **/
// 向量是否为空
cout<<v.empty()<<endl;
// 向量的元素个数
cout<<v.size()<<endl;





#endif /* Vector_h */
