#include "LinkList.h"

int main()
{
    link* head1, *head2;
    init(&head1);
    init(&head2);

    update(head1,1,10);
    update(head2,2,0);

    display(head1);
    display(head2);

    int result = LinkIntersect(head1,head2);
    printf("相交结果为%d\n",result);

    return 0;
}