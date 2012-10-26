#include<string.h>
#include<stdio.h>

void main()
{


char cfilepath[]="ROOT/A/B/C";//specifies the current file path of the node to be placed 
	char delimiter[]="/";
	char *token[50];
	//char str[][20];

/*token[0]= strtok(cfilepath,delimiter);
token[1]=strtok(NULL,delimiter);
token[2]=strtok(NULL,delimiter);
token[3]=strtok(NULL,delimiter);

printf("%s\n",token[0]);
printf("%s\n",token[1]);
printf("%s\n",token[2]);
printf("%s\n",token[3]); */

int i;
i=strspn(cfilepath,"/");
printf("%d",i);

}
