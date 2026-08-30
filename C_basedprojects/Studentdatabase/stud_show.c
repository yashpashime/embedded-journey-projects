#include"header.h"
void stud_show(stl *p)
{
	if(p==0)
	{
		printf("no record created\n");
		return;
	}
	else
	{
		while(p)
		{
			printf("-----------------------------------------------\n");
                        printf("%d %s %f\n",p->rollno,p->name,p->marks);
			printf("-----------------------------------------------\n");
			p=p->next;
		}
	}
}

