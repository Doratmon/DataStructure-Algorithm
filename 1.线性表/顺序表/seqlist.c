#include "seqlist.h"


//初始化
void init(SeqList* s)
{
    s->head = (int*)malloc(SIZE*sizeof(int));
    if(!s->head)
    {
        printf("Failed to malloc memory\n");
        exit(0);
    }
    s->len = 0;
    s->size = SIZE;
}

//显示所有元素
void display(SeqList* s)
{
    for (int i = 0; i < s->len; i++)
    {
        printf("%d ",s->head[i]);
    }
    printf("\n");
    
}

//查找第pos个位置的元素
int search(SeqList* s, int pos)
{
    if (pos < 1 || pos > s->len)
    {
        printf("查找位置非法\n");
        //假设元素均为正值
        return -1;
    }
    return s->head[pos-1];
    
}

//插入元素到第pos(从1开始)个位置
void insert(SeqList* s, int pos, int elem)
{
    //插入位置非法
    if (pos > s->len + 1 || pos < 1)
    {
        printf("插入位置非法\n");
        return;
    }

    //空间已满则重新分配空间
    if (s->len == s->size)
    {
        s->head = (int*)realloc(s->head,s->size + SIZE);
        if (!s->head)
        {
            printf("Failed to malloc memory\n");
            exit(0);
        }
        s->size = s->size + SIZE;
    }
    //索引为pos-1的元素开始依次往后移动
    for (int i = s->len-1; i >= pos-1; i--)
    {
        s->head[i+1] = s->head[i];
    }
    s->head[pos-1] = elem;
    s->len++;
    
}

//删除元素
void del(SeqList* s, int pos)
{
    if (pos > s->len || pos < 1)
    {
        printf("删除位置非法\n");
        return;
    }

    //从删除位置后一个开始往前移动
    for (int i = pos; i < s->len; i++)
    {
        s->head[i-1] = s->head[i];
    }
    s->len--;
}


//更新指定位置的元素
void update(SeqList* s, int pos,int NewElem)
{
    if (pos < 1 || pos > s->len)
    {
        printf("更新位置非法\n");
        return;
    }
    
    s->head[pos-1] = NewElem;
    
}
