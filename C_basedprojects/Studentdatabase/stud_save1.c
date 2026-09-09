#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void save_records(void)
{
    struct student *p;
    FILE *fp;

    p = head;

    if(p == 0)
    {
        printf("No record found to be saved\n");
        return;
    }

    fp = fopen("student.dat", "w");


    while(p)
    {
        fprintf(fp, "%d %s %f\n",
                p->rollno,
                p->name,
                p->percentage);

        p = p->next;
    }

    fclose(fp);

    printf("Data saved in file\n");
}

void load_records(void)
{
    struct student *n, *last;
    FILE *fp;

    fp = fopen("student.dat", "r");

    if(fp == NULL)
        return;

    while(1)
    {
        n = malloc(sizeof(struct student));

        if(fscanf(fp, "%d %s %f",
                  &n->rollno,
                  n->name,
                  &n->percentage) == EOF)
        {
            free(n);
            break;
        }

        n->next = 0;

        if(head == 0)
            head = n;
        else
        {
            last = head;

            while(last->next)
                last = last->next;

            last->next = n;
        }
    }

    fclose(fp);
}

