
#include "seqlist.h"


int main()
{

    SeqList s;
    init(&s);
    int n,elem,NewElem,pos;
    int i=1;
    while(i)
    {
        printf("1.插入元素\n2.删除元素\n3.显示所有元素\n4.更新元素\n5.查找元素\n\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("\n插入元素：");
            scanf("%d",&elem);
            printf("\n插入位置：");
            scanf("%d",&pos);
            insert(&s,elem,pos);
            break;
        
        case 2:
            printf("\n删除位置：");
            scanf("%d",&pos);
            del(&s,pos);
            break;
        
        case 3:
            display(&s);
            break;
        
        case 4:
            printf("\n更新的位置：");
            scanf("%d",&pos);
            printf("\n更新为:");
            scanf("%d",&NewElem);
            update(&s,pos,NewElem);
            break;
        
        case 5:
            printf("\n查找的位置：");
            scanf("%d",&pos);
            search(&s,pos);

        default:
            break;
        }
        printf("\n\n继续？Yes-1 No-0：");
        scanf("%d",&i);
    }
    return 0;
}