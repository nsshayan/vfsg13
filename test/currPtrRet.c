#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"

struct nAryTree * currPtrReturn(char P1[],char P2[])
{
	char **token;	
	char prevFileName[50],currFileName[50];
	int count;
	char *parentP1;	//*parentP2;
	int n,i;
	struct nAryTree *currPtr,*temproot;
	
	char tempP1[100];
	parentP1=(char *)malloc(sizeof(char)*50);
	
	
	if(strcmp(P1,"root")==0)
	{
	currPtr=root;
	currPtr=currPtr->leftChild;
	}
	
	else
	{		
		temproot=root;
		currPtr=curPtrFunc(P1,temproot);
		currPtr=temp2;//fetching the current ptr
		//printf("\n currptr name %s\n",currPtr->fd_tree->fileName);
		//currPtr=currPtr->leftChild;
	}	

	while(currPtr!=NULL) //moving to the correct position
	{
		if(strcmp(currPtr->fd_tree->fileName,P2)==0) 
		break;
		currPtr=currPtr->rightSibling;
	}
	
	

	//printf("\n currptr name %s\n",currPtr->fd_tree->fileName);
	
return currPtr;
}

