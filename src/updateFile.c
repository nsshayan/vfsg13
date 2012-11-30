#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"

void update_file(char *P1,char *P2)
{
FILE *fp,*mainfp;

char ch;
char **token;
int count,i,n;
char *parentP1;
char tempP1[100];
char prevFileName[50],currFileName[50];
struct nAryTree *currPtr;
int blockno;
parentP1=(char *)malloc(sizeof(char)*50);

	strcpy(tempP1,P1);
	count=countSlash(tempP1);
	token=stringtok(tempP1);	
	
	for(i=0;i<=count;i++)	
		printf("\n tokens are %s\n",token[i]);

	n=strlen(P1)-(strlen(token[count])+1);
	//l2=strlen(token[count-1])+1;
	//printf("\npath %s\n",P1);
	//printf("lengths %d %d %d",strlen(P1),strlen(token[count])+1,n);
	
	//copying the parent path
		for(i=0;i<n;i++)
			parentP1[i]=P1[i];
	
		strcat(parentP1,"\0");
	strcpy(currFileName,token[count]);
	strcpy(prevFileName,token[count-1]);

	currPtr=curPtrFunc(parentP1,root);
	currPtr=temp2;//fetching the current ptr
	
	while(currPtr->rightSibling!=NULL) //moving to the correct position
	{
		if(strcmp(currPtr->fd_tree->fileName,token[count])==0) 
		break;
		currPtr=currPtr->rightSibling;
	}
	printf("\n currptr name %s\n",currPtr->fd_tree->fileName);
	
	fp=fopen(P2,"r");
	mainfp=fopen(vfsName,"rb+");
	blockno=currPtr->fd_tree->blockNo;
	fseek(mainfp,(sizeof(struct mainHeader)+blockno*1024),0);

	while((ch=fgetc(fp))!=EOF) 
	{
		fputc(ch,mainfp);
	}
fputc('\0',mainfp);

fclose(fp);
fclose(mainfp);
} 
