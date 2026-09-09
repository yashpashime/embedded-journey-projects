#include <stdio.h>
#include "student.h"

void reverse_list(void)
{
    struct student *prev, *p, *next;

    prev = 0;
    p = head;

    while(p)
    {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }

    head = prev;

    printf("List reversed successfully\n");
}
