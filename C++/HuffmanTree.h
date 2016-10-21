//
//  HuffmanTree.h
//  C++
//
//  Created by albeeert on 10/6/16.
//  Copyright © 2016 Xinhou Jiang. All rights reserved.
//

#ifndef HuffmanTree_h
#define HuffmanTree_h

#include <iostream>
using namespace std;

#define n 5         // 字符个数（叶子个数）
#define m 2*(n)-1   // 总节点数：1+2+4+8+...+n

typedef struct{
    double weight;   // 节点权重
    int lchild;      // 左子树
    int rchild;      // 右子树
    int parent;      // 父节点
}HTNODE;

typedef HTNODE HuffmanT[m];  // 一棵线性结构存储的哈弗曼树

/**
 * 哈弗曼树初始化
 */
void InitHT(HuffmanT T)
{
    for(int i=0; i<m; i++)
    {
        T[i].lchild=-1;
        T[i].rchild=-1;
        T[i].parent=-1;
    }
    // 依次输入每个节点的权重
    for(int i=0; i<n; i++)
        std::cin>>T[i].weight;
}

/**
 * 找出还没有父节点的节点中权值最小的两个,p1和p2是要选出的权值最小的两个节点的下标，n1是新父节点的下标
 */
void SelectMin(HuffmanT T, int n1, int &p1, int &p2)
{
    int i, j;
    // 先任意找两个没有父节点的节点
    for(i=0; i<n1; i++)
        if(T[i].parent==-1)
        {
            p1=i;
            break;
        }
    for(j=i+1; j<n1;j++)
        if(T[j].parent==-1)
        {
            p2=j;
            break;
        }
    // 搜索替换成权值最小的节点
    for(i=0; i<n1; i++)
        if((T[p1].weight>T[i].weight) && (T[i].parent==-1) && (p2!=i))
            p1=i;
    for(i=0; i<n1; i++)
        if((T[p2].weight>T[i].weight) && (T[i].parent==-1) && (p1!=i))
            p2=i;
    
}
/**
 * 构造哈弗曼树
 */
void CreatHT(HuffmanT T)
{
    int i, p1, p2;
    InitHT(T);
    // 非叶子节点
    for(i=n; i<m; i++)
    {
        // 找出还没有父节点的节点中权值最小的两个
        SelectMin(T, i, p1, p2);
        T[p1].parent=T[p2].parent=i;
        T[i].lchild=p1;
        T[i].rchild=p2;
        T[i].weight=T[p1].weight+T[p2].weight;
    }
}

/**
 * 打印哈弗曼树
 */
void printHT(HuffmanT T)
{
    for(int i=0; i<m; i++)
    {
        std::cout<<T[i].weight<<'\t'<<T[i].parent<<'\t'<<T[i].rchild<<'\t'<<T[i].lchild<<std::endl;
    }
}

/**
 * 前台测试
 */
int main(){
    HuffmanT T;
    CreatHT(T);
    printHT(T);
    return 0;
}

#endif /* HuffmanTree_h */
