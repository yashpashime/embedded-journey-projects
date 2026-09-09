#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void delete_record(void)
{
    struct student *p, *prev;
    char ch;
    int roll;
    char name[50];
    int found = 0;

    printf("R/r : Enter roll number to delete\n");
    printf("N/n : Enter name to delete\n");
    scanf(" %c", &ch);

    switch(ch)
    {
        case 'R':
        case 'r':
            printf("Enter roll number: ");
            scanf("%d", &roll);

            if(roll <= 0)
            {
                printf("Invalid roll number\n");
                return;
            }

            p = head;
            prev = 0;

            while(p)
            {
                if(p->rollno == roll)
                {
                    if(p == head)
                        head = p->next;
                    else
                        prev->next = p->next;

                    free(p);

                    printf("Record deleted successfully\n");
                    return;
                }

                prev = p;
                p = p->next;
            }

            printf("Record not found\n");
            break;


        case 'N':
        case 'n':
            printf("Enter name: ");
            scanf("%49s", name);

            p = head;

            while(p)
            {
                if(strcmp(p->name, name) == 0)
                {
                    printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                           p->rollno, p->name, p->percentage);

                    found = 1;
                }

                p = p->next;
            }

            if(found == 0)
            {
                printf("Record not found\n");
                return;
            }

            printf("Enter roll number of the record to delete: ");
            scanf("%d", &roll);

            if(roll <= 0)
            {
                printf("Invalid roll number\n");
                return;
            }

            p = head;
            prev = 0;

            while(p)
            {
                if(p->rollno == roll && strcmp(p->name, name) == 0)
                {
                    if(p == head)
                        head = p->next;
                    else
                        prev->next = p->next;

                    free(p);

                    printf("Record deleted successfully\n");
                    return;
                }

                prev = p;
                p = p->next;
            }

            printf("Selected record not found\n");
            break;


        default:
            printf("Invalid choice\n");
    }
}
