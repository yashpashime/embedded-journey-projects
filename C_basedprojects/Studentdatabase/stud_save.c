#include"header.h"
void stud_save(stl *p)
{
	char op;
	if(p==0)
	{
		printf("no record found to be saved_____\n");
		return;
	}
	printf("enter \n");
	printf("S :save and exit\nE :exit without saving\n");
	scanf(" %c",&op);
	switch(op)
	{

		case 'S':FILE *fp;
			 fp=fopen("student.dat","w");

			 while(p)
			 {
				 fprintf(fp,"%d %s %f\n",p->rollno,p->name,p->marks);
				 p=p->next;
			 }
			 printf("data saved in a file\n");
			 fclose(fp);
			 exit(0);
			 break;

		case 'E':printf("exiting without save\n");
			 break;
	}

}
