#include"header.h"
void commentremoval(FILE *pf,FILE *of)
{
	char ch;
	int eof=0;
l:
	while((ch=fgetc(pf))!=EOF)//gets character by character data from my input.c file
	{

		if(ch=='/') //if 1st char '/' found then check next character
		{
			ch=fgetc(pf);//moves file pointer to next char
			if(ch=='/')//checks if next char is '/' if its then single line comment started
			{

				while(ch!='\n')//skips the characters till '\n'found 
				ch=fgetc(pf);
				fputc('\n',of);//prints \n in output file
			}
			else if(ch=='*')//checks if next character is '*' if its then multiline comment started
			{
				while((ch=fgetc(pf))!=EOF)//runs till end of the file
				{
			        	//ch=fgetc(pf);
					if(ch=='\n')//if in multiline new line starts then
					{
						fputc('\n',of);
					}
					if(ch=='*')//if '*' found check next character is '/' or not if found then till then skip char 
					{
						ch=fgetc(pf);
						if(ch=='/')
						{
							eof=1;
							break;
						}

					}
				}
				if(eof==0)//if next char not found eof flag i used to indicate and give error
				{
					printf("error:unterminated multiline comment\n");
					return;
				}
				fputc('\n',of);//printf next line in output.i file

			}
			else
			{
				fseek(pf,-2,SEEK_CUR);//if mine next charcter '/' or '*' not found then shift pf to '/' again and print it
				ch=fgetc(pf);
				fputc(ch,of);//here / will be printed original
				goto l;

			}


		}
		else// if no '/' found then print data as it is 
		{
			fputc(ch,of);
		}

	}

}
