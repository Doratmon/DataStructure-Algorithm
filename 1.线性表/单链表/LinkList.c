#include "LinkList.h"

//链表初始化
void init(link** p)
{
    link* temp = (link*)malloc(sizeof(link));
    *p = temp;

    for (int i = 1; i <= SIZE ; i++)
    {
        link* node = (link*)malloc(sizeof(link));
        node->elem = i;
        temp->next = node;
        temp = node;
    }

    temp->next = NULL;
    
}

//显示链表中的元素
void display(link* p)
{
    link* temp = p;
    temp = temp->next;
    while(temp)
    {
        printf("%d ",temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

//向链表中插入元素
void insert(link* p, int elem, int pos)
{
    link* temp = p; //头节点

    //找到插入位置的上一个节点
    for(int i = 1; i < pos; i++)
    {
        if (!temp)
        {
            printf("插入位置无效\n");
            return;
        }
        
        temp = temp->next; 
    }

    link* node = (link*)malloc(sizeof(link));
    node->elem = elem;
    node->next = temp->next; //1. 新节点的next指针指向插入位置的节点
    temp->next = node;//2. 插入位置的前一个节点的next指针指向新节点
}

//删除链表中的元素
void del(link* p, int pos)
{
    link* temp = p;//temp指向链表的头节点
    
        
    //找到删除位置的前一个节点
    for(int i = 1; i < pos; i++)
    {
        if (!temp)
        {
            printf("删除位置非法\n");
            return;
        }
        temp = temp->next;   
    }

    link* node = temp->next;//要删除的节点
    temp->next = node->next;//删除位置的前一个节点的next指针指向删除位置的后一个节点
    free(node);//释放要删除节点的内存
}

//查找第pos个位置的元素值
int search(link* p, int pos)
{
    link* temp = p;
    
    for (int i = 1; i <= pos; i++)
    {
        if (!temp)
        {
            printf("查找位置非法\n");
            //假设元素均为正值
            return -1;
        }
        temp = temp->next;   
    }
    return temp->elem;
}

//更新链表第pos个位置的元素为NewElem
void update(link* p, int pos, int NewElem)
{
    link* temp = p;

    for (int i = 1; i <= pos; i++)
    {
        if (!temp)
        {
            printf("更新位置非法\n");
            return;
        }

        temp = temp->next;
    }

    temp->elem = NewElem;

}