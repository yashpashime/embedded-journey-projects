#include <stdio.h>
#include <stdlib.h>
#include "student.h"

struct student *head = NULL;

int main()
{
    char ch;

    load_records();

    while(1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");
        printf("Enter your choice: ");

        scanf(" %c", &ch);

        switch(ch)
        {
            case 'a':
            case 'A':
                add_record();
                break;

            case 'd':
            case 'D':
                delete_record();
                break;

            case 's':
            case 'S':
                show_records();
                break;

            case 'm':
            case 'M':
                modify_record();
                break;

            case 'v':
            case 'V':
                save_records();
                break;

            case 't':
            case 'T':
                sort_records();
                break;

            case 'l':
            case 'L':
                delete_all();
                break;

            case 'r':
            case 'R':
                reverse_list();
                break;

            case 'e':
            case 'E':
                printf("\nS/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter your choice: ");

                scanf(" %c", &ch);

                switch(ch)
                {
                    case 'S':
                    case 's':
                        save_records();
                        delete_all();
                        printf("Program terminated\n");
                        return 0;

                    case 'E':
                    case 'e':
                        delete_all();
                        printf("Program terminated without saving\n");
                        return 0;

                    default:
                        printf("Invalid choice\n");
                }
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
