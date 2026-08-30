#include"header.h"
void main()
{
	stl *head=0;
	char op;


	while(1)
	{
		printf(" *****STUDENT RECORD MENU*****\n");
		printf("________________________________\n");
	printf("a/A :add new record\nd/D :delete a record\ns/S :show the list\nm/M :modify the record\nv/V :save\ne/E :exit\nt/T :sort the list\nl/L :delete all the records\nr/R :reverse the list\n\n");
         printf("Enter your choice:\n");


	 scanf(" %c",&op);

	 switch(op)
	 {
		 case 'a': stud_add(&head);
		 break;
		 case 's': stud_show(head);
		 break;
		 case 'v': stud_save(head);
		 break;
		 case 'e': exit(0);
		 break;
		 default:printf("unkown option\n");
	 }

	}
}
