#include <stdio.h>
#include <string.h>
#include "student.h"

void sort_records(void)
{
    struct student *p, *q;
    int temp_roll;
    char temp_name[50];
    float temp_percentage;
    char ch;

    printf("N/n : Sort by name\n");
    printf("P/p : Sort by percentage\n");

    scanf(" %c", &ch);

    switch(ch)
    {
        case 'N':
        case 'n':
            for(p = head; p; p = p->next)
            {
                for(q = p->next; q; q = q->next)
                {
                    if(strcmp(p->name, q->name) > 0)
                    {
                        temp_roll = p->rollno;
                        p->rollno = q->rollno;
                        q->rollno = temp_roll;

                        strcpy(temp_name, p->name);
                        strcpy(p->name, q->name);
                        strcpy(q->name, temp_name);

                        temp_percentage = p->percentage;
                        p->percentage = q->percentage;
                        q->percentage = temp_percentage;
                    }
                }
            }

            printf("List sorted by name\n");
            break;

        case 'P':
        case 'p':
            for(p = head; p; p = p->next)
            {
                for(q = p->next; q; q = q->next)
                {
                    if(p->percentage < q->percentage)
                    {
                        temp_roll = p->rollno;
                        p->rollno = q->rollno;
                        q->rollno = temp_roll;

                        strcpy(temp_name, p->name);
                        strcpy(p->name, q->name);
                        strcpy(q->name, temp_name);

                        temp_percentage = p->percentage;
                        p->percentage = q->percentage;
                        q->percentage = temp_percentage;
                    }
                }
            }

            printf("List sorted by percentage\n");
            break;

        default:
            printf("Invalid choice\n");
    }
}
