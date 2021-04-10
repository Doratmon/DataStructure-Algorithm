#ifndef LINKLIST
#define LINKLIST

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct link
{
    int elem;
    struct link* next;
} link;

/*
*功能：初始化链表（考虑头节点）
*参数：链表的头指针
*返回值：无
*/
void init(link** p);

/*
*功能：显示链表中的元素
*参数：链表的头指针
*返回值：无
*/
void display(link* p);

/*
* 功能：向链表中第pos个位置插入元素
* 参数：p 链表头指针
*      elem 插入的元素
*      pos 插入的位置
* 返回值：无
*/
void insert(link* p, int elem, int pos);

/*
* 功能：删除链表中第pos个位置的元素
* 参数：p 链表头指针
*      pos 删除的位置
* 返回值：无
*/
void del(link* p, int pos);

/*
* 功能：查找第pos个位置的元素
* 参数：p 链表头指针
*      pos 查找的位置
* 返回值：第pos个位置的元素值
*/
int search(link* p, int pos);

/*
* 功能：更新链表第pos个位置的元素为NewElem
* 参数：p 链表头指针
*      pos 更新元素所在位置
*      NewElem 旧元素更新为NewElem
* 返回值：无
*/
void update(link* p, int pos, int NewElem);


#endif