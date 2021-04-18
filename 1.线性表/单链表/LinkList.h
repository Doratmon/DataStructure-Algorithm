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
*参数：p_head 指向链表的头指针的指针
*返回值：无
*/
void init(link** p_head);

/*
*功能：显示链表中的元素
*参数：链表的头指针
*返回值：无
*/
void display(link* head);

/*
* 功能：向链表中第pos个位置插入元素
* 参数：head 链表头指针
*      elem 插入的元素
*      pos 插入的位置
* 返回值：无
*/
void insert(link* head, int elem, int pos);

/*
* 功能：删除链表中第pos个位置的元素
* 参数：head 链表头指针
*      pos 删除的位置
* 返回值：无
*/
void del(link* head, int pos);

/*
* 功能：查找第pos个位置的元素
* 参数：head 链表头指针
*      pos 查找的位置
* 返回值：第pos个位置的元素值
*/
int search(link* head, int pos);

/*
* 功能：更新链表第pos个位置的元素为NewElem
* 参数：head 链表头指针
*      pos 更新元素所在位置
*      NewElem 旧元素更新为NewElem
* 返回值：无
*/
void update(link* head, int pos, int NewElem);

/*
* 功能：迭代反转链表
* 参数: p_head 指向链表头指针的指针
* 返回值：无
*/
void iteration_reverse(link** p_head);

/*
* 功能：递归反转链表（无头节点）
* 参数：head 链表的头指针
* 返回值：逆转链表后的头指针
*/
link* recursive_reverse(link* head);

/*
* 功能：头插法逆转链表
* 参数：head  链表的头指针
* 返回值：
*/
link* head_reverse(link* head);

/*
* 功能：判断两个链表是否相交（只需判断最后一个节点的地址是否相同）
* 参数：head1 链表1头指针
*      head2 链表2头指针
* 返回值：1 相交
*        0 不相交
* 时间复杂度: O(n)
*/
int LinkIntersect(link* head1, link* head2);


/*
* 功能：判断两个链表是否相交
*      (从较长链表中截取和较短链表同样长的部分进行比较)
*      修改代码可列出具体相同的节点
* 参数：head1 链表1头指针
*      head2 链表2头指针
* 返回值：1 相交
*        0 不相交
* 时间复杂度: O(n)
*/
/*
int LinkIntersect(link* head1, link* head2)
{
    int len1 = 0, len2 = 0, step;
    link* phead1 = head1, *phead2 = head2;
    link* plong = NULL; //指向更长的链表
    link* pshort = NULL; //指向更短的链表
    while (phead1)
    {
        len1++;
        phead1 = phead1->next;
    }

    while (phead2)
    {
        len2++;
        phead2 = phead2->next;
    }

    if (len1 > len2)
    {
        plong = phead1;
        pshort = phead2;
        step = len2;
    }else{
        plong = phead2;
        pshort = phead1;
        step = len1;
    }
    
    //调整plong，使得和pshort指向的链表相同长度
    while(step--)
    {
        plong = plong->next;
    }

    while(pshort && plong)
    {
        if(pshort == plong)//有节点相同就返回
        {
            return 1;
        }
        pshort = pshort->next;
        plong = plong->next;
    }

    return 0;
}
*/
#endif