#ifndef SEQLISTHEADER //防止重复包含
#define SEQLISTHEADER

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

//顺序表结构
typedef struct SeqList
{
    int* head;
    int len;//记录顺序表当前长度
    int size;//记录顺序表分配的存储容量
}SeqList;

/*
*功能:初始化顺序表
*参数：SeqList* s 顺序表地址
*返回值：无
*/
void init(SeqList* s);

/*
*功能:显示所有元素
*参数：SeqList* s 顺序表地址
*返回值：无
*/
void display(SeqList* s);

/*
*功能:查找第pos个位置的元素
*参数：s 顺序表地址
*     pos 查找的位置
*返回值：第pos个位置的元素值
*/
int search(SeqList* s, int pos);


/*
*功能:插入元素到指定位置
*参数：s 顺序表地址
*     pos 元素插入的位置
*     elem 要插入的元素 
*返回值：无
*/
void insert(SeqList* s,  int pos, int elem);

/*
*功能:删除指定位置的元素
*参数：s 顺序表地址
*     pos 删除元素的位置
*返回值：无
*/
void del(SeqList* s, int pos);

/*
*功能:修改元素
*参数：s 顺序表地址
*     pos 第pos个位置
*     NewElem 新元素
*返回值：无
*/
void update(SeqList* s, int pos,int NewElem);
#endif