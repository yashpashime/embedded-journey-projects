#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void show_records(void)
{
    struct student *p;

    p = head;

    if (p == 0)
    {
        printf("No student records available\n");
        return;
    }

    printf("---------------------------------------------\n");
    printf("Roll No.    Name        Percentage\n");
    printf("---------------------------------------------\n");

    while (p)
    {
        printf("%-12d%-12s%.2f\n",
               p->rollno,
               p->name,
               p->percentage);

        p = p->next;
    }

    printf("---------------------------------------------\n");
}
