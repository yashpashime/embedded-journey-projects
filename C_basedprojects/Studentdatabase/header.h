#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
	int rollno;
	char name[20];
	float marks;
	struct student *next; 
}stl;


void stud_add(stl **);
void stud_del(stl **);
void stud_show(stl *);
void stud_mod(stl **);
void stud_save(stl *);
