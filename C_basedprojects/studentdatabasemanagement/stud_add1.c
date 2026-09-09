#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void add_record(void)
{
    struct student *n;
    struct student *p;
    int roll;

    n = malloc(sizeof(struct student));


    roll = 1;

    while(1)
    {
        p = head;

        while(p)
        {
            if(p->rollno == roll)
                break;

            p = p->next;
        }

        if(p == NULL)
            break;

        roll++;
    }

    n->rollno = roll;

    printf("Enter student name: ");
    scanf("%49s", n->name);

    if(n->name[0] == '\0')
    {
        printf("Student name cannot be empty\n");
        free(n);
        return;
    }

    while(1)
    {
        printf("Enter percentage: ");
        scanf("%f", &n->percentage);

        if(n->percentage >= 0.0 && n->percentage <= 100.0)
            break;

        printf("Invalid percentage. Enter between 0.00 and 100.00\n");
    }

    n->next = NULL;

    if(head == NULL)
    {
        head = n;
    }
    else
    {
        p = head;

        while(p->next)
            p = p->next;

        p->next = n;
    }

    printf("Record added successfully\n");
    printf("Assigned Roll No: %d\n", n->rollno);
}
