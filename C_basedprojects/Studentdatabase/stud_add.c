#include"header.h"
void stud_add(stl **p)
{
     stl *n,*last; 
     n=malloc(sizeof(stl));
     printf("enter the data\n");
     scanf(" %d %s %f",&n->rollno,n->name,&n->marks);
     
     n->next=0;
     if(*p==0)
     {
	     *p=n;

     }
     else
     {
	     last=*p;
	     while(last->next)
		     last=last->next;

            last->next=n;
     }

}
