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

//查找元素（返回查找到的第一个位置）
int search(SeqList* s, int elem)
{
    for (int i = 0; i < s->len; i++)
    {
        if(s->head[i] == elem)
            return i+1;
    }
    return -1;
}

//插入元素到指定位置 pos为插入到哪个位置(从1 开始)
void insert(SeqList* s, int elem, int pos)
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


//更新指定元素的值
void update(SeqList* s, int elem,int new_elem)
{
    int pos = search(s,elem);
    s->head[pos-1] = new_elem;
    
}
