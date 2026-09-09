#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void delete_all(void)
{
    struct student *p;

    p = head;

    while(p)
    {
        head = p->next;
        free(p);
        p = head;
    }

    printf("All records deleted successfully\n");
}
