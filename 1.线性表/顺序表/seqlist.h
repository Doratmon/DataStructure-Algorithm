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
*功能:查找指定元素所在位置
*参数：SeqList* s 顺序表地址
*     int elem 要找的元素
*返回值：元素出现的第一个位置
*/
int search(SeqList* s, int elem);


/*
*功能:插入元素到指定位置
*参数：SeqList* s 顺序表地址
*     int elem 要插入的元素
*     int pos 元素插入的位置
*返回值：无
*/
void insert(SeqList* s, int elem, int pos);

/*
*功能:删除指定位置的元素
*参数：SeqList* s 顺序表地址
*     int pos 要删除元素的位置
*返回值：无
*/
void del(SeqList* s, int pos);

/*
*功能:修改元素
*参数：SeqList* s 顺序表地址
*     int elem 旧元素
*     int new_elem 新元素
*返回值：无
*/
void update(SeqList* s, int elem,int new_elem);
