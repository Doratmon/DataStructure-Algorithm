#include "LinkList.h"

//链表初始化
void init(link** p_head)
{
    link* temp = (link*)malloc(sizeof(link));
    *p_head = temp;

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
void display(link* head)
{
    link* temp = head;
    temp = temp->next;
    while(temp)
    {
        printf("%d ",temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

//向链表中插入元素
void insert(link* head, int elem, int pos)
{
    link* temp = head; //头节点

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
void del(link* head, int pos)
{
    link* temp = head;//temp指向链表的头节点
    
        
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
int search(link* head, int pos)
{
    link* temp = head;
    
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
void update(link* head, int pos, int NewElem)
{
    link* temp = head;

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

void iteration_reverse(link** p_head)
{
    if (*p_head == NULL || (*p_head)->next == NULL)
    {
        return;
    }
    
    link* begin = NULL;
    link* middle = (*p_head)->next;//指向首元节点
    link* end = middle->next;

    while (end)
    {
        middle->next = begin;
        begin = middle;
        middle = end;
        end = end->next;
    }
    middle->next = begin;
    (*p_head)->next = middle;//头节点指向反转前的最后一个节点
}


link* recursive_reverse(link* head)
{
    //只有一个节点或者找到最后一个节点就返回
    if (head->next == NULL || head == NULL)
    {
        return head;
    }

    link* new_head = recursive_reverse(head->next);//始终指向最后一个节点

    head->next->next = head;
    head->next = NULL;

    return new_head;
}

//带头节点的链表head从指向首元节点开始
link* head_reverse(link* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    link* new_head = NULL;
    link* temp = NULL;
   
    //带头节点的链表需要从首元节点开始
    /*
    * code ...
    */

    while(head)
    {
        temp = head;
        head = head->next;
        temp->next = new_head;

        new_head = temp;
    }

    return new_head;
}

int LinkIntersect(link* head1, link* head2)
{
    //找到链表1的最后一个节点
    while(head1->next)
    {
        head1 = head1->next;
    }

    //找到链表2的最后一个节点
    while(head2->next)
    {
        head2 = head2->next;
    }

    if (head1 == head2)
    {
        return 1;
    }else
    {
        return 0;
    }
    
    
}