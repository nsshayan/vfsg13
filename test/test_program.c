#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int  main()
{
char *P1="/";
char ch[100]="root";

printf("\nThe string %s before rewriting\n",P1);


if(strlen(ch)==1)
printf("\n the path is root only");

else if(strlen(P1)>1)
strcat(ch,P1);
//NP1=strcat(ch,P1);
printf("\n the new path is:: %s\n",ch);

return 0;
}
