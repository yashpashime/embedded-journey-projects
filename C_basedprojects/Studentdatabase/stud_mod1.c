#include <stdio.h>
#include <string.h>
#include "student.h"

void modify_record(void)
{
    struct student *p;
    char ch;
    int roll;
    char name[50];
    float percentage;
    int found;

    printf("R/r : Modify by roll number\n");
    printf("N/n : Modify by name\n");
    printf("P/p : Modify by percentage\n");

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

            while(p)
            {
                if(p->rollno == roll)
                {
                    printf("Current details:\n");
                    printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                           p->rollno, p->name, p->percentage);

                    printf("Enter new name: ");
                    scanf("%49s", p->name);

                    while(1)
                    {
                        printf("Enter new percentage: ");
                        scanf("%f", &percentage);

                        if(percentage >= 0.0 && percentage <= 100.0)
                            break;

                        printf("Invalid percentage. Enter between 0.00 and 100.00\n");
                    }

                    p->percentage = percentage;

                    printf("Record modified successfully\n");
                    return;
                }

                p = p->next;
            }

            printf("Record not found\n");
            break;


        case 'N':
        case 'n':
            printf("Enter name: ");
            scanf("%49s", name);

            p = head;
            found = 0;

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

            printf("Enter roll number of record to modify: ");
            scanf("%d", &roll);

            if(roll <= 0)
            {
                printf("Invalid roll number\n");
                return;
            }

            p = head;

            while(p)
            {
                if(p->rollno == roll && strcmp(p->name, name) == 0)
                {
                    printf("Enter new name: ");
                    scanf("%49s", p->name);

                    while(1)
                    {
                        printf("Enter new percentage: ");
                        scanf("%f", &percentage);

                        if(percentage >= 0.0 && percentage <= 100.0)
                            break;

                        printf("Invalid percentage. Enter between 0.00 and 100.00\n");
                    }

                    p->percentage = percentage;

                    printf("Record modified successfully\n");
                    return;
                }

                p = p->next;
            }

            printf("Selected record not found\n");
            break;


        case 'P':
        case 'p':
            printf("Enter percentage: ");
            scanf("%f", &percentage);

            if(percentage < 0.0 || percentage > 100.0)
            {
                printf("Invalid percentage\n");
                return;
            }

            p = head;
            found = 0;

            while(p)
            {
                if(p->percentage == percentage)
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

            printf("Enter roll number of record to modify: ");
            scanf("%d", &roll);

            if(roll <= 0)
            {
                printf("Invalid roll number\n");
                return;
            }

            p = head;

            while(p)
            {
                if(p->rollno == roll && p->percentage == percentage)
                {
                    while(1)
                    {
                        printf("Enter new percentage: ");
                        scanf("%f", &percentage);

                        if(percentage >= 0.0 && percentage <= 100.0)
                            break;

                        printf("Invalid percentage. Enter between 0.00 and 100.00\n");
                    }

                    p->percentage = percentage;

                    printf("Percentage modified successfully\n");
                    return;
                }

                p = p->next;
            }

            printf("Selected record not found\n");
            break;


        default:
            printf("Invalid choice\n");
    }
}
