#include "LinkList.h"

int main()
{
    link* p;
    init(&p);
    display(p);
    insert(p,10,6);
    display(p);
    del(p,6);
    display(p);
    int elem = search(p,3);
    printf("%d\n",elem);
    update(p, 22, 11);
    display(p);
    return 0;
}