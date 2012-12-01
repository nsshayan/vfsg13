#include "mainHeader.h"
char *token[50];

char **stringtok(char *P1)
{
	int i;
	int count=0;

//	printf("\nCounting the number of '/'");
			//Counts the number of '/' in the file path of the received file descriptor
		for(i=0;P1[i]!='\0';i++) 
			if(P1[i]=='/')
				count++;
//	printf("\nTokenizing the path with '/'");

	token[0]= strtok(P1,"/");

	strcat(token[0],"\0");
//	printf("\n0.%s",token[0]);
		for(i=1;i<count+1;i++)
		{
			token[i]=strtok(NULL,"/");
			strcat(token[i],"\0");
//			printf("\n%d.%s",i,token[i]);
		}

return token;
}

int countSlash(char *P1)
{
int i;
int count=0;
//printf("\nCounting the number of '/'");
		//Counts the number of '/' in the file path of the received file descriptor
		for(i=0;P1[i]!='\0';i++) 
			if(P1[i]=='/')
				count++;
	
return count;
}
