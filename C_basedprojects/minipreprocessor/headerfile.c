#include"header.h"
void headerfile(FILE *pf,FILE *of)
{
	char a[20],ch;
	int j=0;

	while((ch=fgetc(pf))!=EOF)
	{
		if(ch=='#')//search for #  if found
		{
			ch=fgetc(pf);//read next character
			j=0;// resets j
			while(ch!='<'&& ch!=EOF && j<19 ) //and copy the word in char array 
			{
			//	printf("j=%d,ch=%c (%d)\n",j,ch,ch); debug purpose
				a[j]=ch;
				j++;
				ch=fgetc(pf);

			}
			a[j]='\0';  // string last char

			if(strcmp(a,"include")==0)//compare if its inlcude or not 
			{
				char path[100]="/usr/include/";//give path for headerfile to be found 

				char s[30];//new array
				int k=0;
				while((ch=fgetc(pf))!='>' && ch!=EOF && k<29)//read the word 
				{
					s[k]=ch;
					k++;
				}
				s[k]='\0';//got the name of header file
			//printf("Header = %s\n", s);
				strcat(path,s);// conactenate with path so that when file opens its correctly reads header file
			//	printf("Header = %s\n", path);
				char lc;// to read character from header file
				FILE * lf;//library file
				lf=fopen(path,"r"); //open the header file in read mode
				if(lf==0) //check if header file present or not
				{
					printf("header file not found\n");
					return;
				}
				while((lc=fgetc(lf))!=EOF)// read header file and write it in output.i file
				{
					fputc(lc,of);
				}
				fclose(lf);
			}
			else
			{
				fputc('#',of);
				for(int i=0;i<j;i++)
				{
					fputc(a[i],of);
				}
				fputc(ch,of);
			}


		}
		else
		{
			fputc(ch,of);
		}


	}

}
