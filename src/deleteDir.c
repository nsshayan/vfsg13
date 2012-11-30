#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"

void deleteDir(char P1[])
{
	char **token;	
	char prevFileName[50],currFileName[50];
	int count;
	char *parentP1,*parentP2;
	int n,i;
	struct nAryTree *currPtr;
	struct nAryTree *prevPtr;
	struct nAryTree *temproot;
	char tempP1[100];
	parentP1=(char *)malloc(sizeof(char)*50);
	parentP2=(char *)malloc(sizeof(char)*50);
	
	
	strcpy(tempP1,P1);
	count=countSlash(tempP1);
	token=stringtok(tempP1);

	printf("\nStarting of the delete directory\n");
	printf("\nroot file name=%s\n",root->fd_tree->fileName);
	printf("\nroot file path=%s\n",root->fd_tree->fullPathName );
	
	for(i=0;i<=count;i++)	
		printf("\n tokens are %s\n",token[i]);

	n=strlen(P1)-(strlen(token[count])+1);
	//l2=strlen(token[count-1])+1;
	printf("\npath %s\n",P1);
	//printf("lengths %d %d %d",strlen(P1),strlen(token[count])+1,n);
	
	//copying the parent path
		for(i=0;i<n;i++)
			parentP1[i]=P1[i];
	//strncpy(parentP1,P1,n);
	//strcat(parentP1,'\0');
	parentP1[n]='\0';
	printf("\ntoken[0] %s\n",token[0]);
	printf("\nparent p1 %s\n",parentP1);
	printf("\nP1 %s\n",P1);
	strcpy(currFileName,token[count]);
		
	strcpy(prevFileName,token[count-1]);
		
	temproot=root;
	currPtr=curPtrFunc(parentP1,temproot);
	currPtr=temp2;//fetching the current ptr
	
	while(currPtr->rightSibling!=NULL) //moving to the correct position
	{
		if(strcmp(currPtr->fd_tree->fileName,token[count])==0) 
		break;
		currPtr=currPtr->rightSibling;
	}

	printf("\n currptr name %s\n",currPtr->fd_tree->fileName);
	
	
	if (strcmp(parentP1,"root")!=0) 
	{
		if(count!=1)
		n=strlen(parentP1)-(strlen(token[count-1])+1);
		else 
		n=strlen(parentP1);
		printf("\npath %s\n",parentP1);
	
		printf("token-1  %s",token[count-1]);
		//printf("length of token-1  %d",strlen(token[count-1]));
		//printf("lengths %d %d %d",strlen(parentP1),strlen(token[count-1])+1,n);
		printf("\n n=%d\n",n);
		//printf("\nl2=%d\n",l2);
		/*for(i=0;i<(n);i++)
		parentP2[i]=parentP1[i];*/
		strcpy(parentP2,parentP1);
		//strcat(parentP2,"\0");
		parentP2[n]='\0';
		printf("\n parent 2%s\n",parentP2);
		
			if(strcmp(parentP2,"root")!=0)
			{	
				prevPtr=curPtrFunc(parentP2,temproot);
				prevPtr=temp2;
				printf("\n tokens %s\n", prevPtr->fd_tree->fileName);
	
				while(prevPtr->rightSibling!=NULL)
				{
					if(strcmp(prevPtr->fd_tree->fileName,prevFileName)==0) 
					break;
					prevPtr=prevPtr->rightSibling;
				}
	
	
				if(prevPtr->rightSibling!=NULL)
					if(strcmp(prevPtr->leftChild->fd_tree->fileName,currFileName)!=0)
					{
						prevPtr=prevPtr->leftChild;
						while(strcmp(prevPtr->rightSibling->fd_tree->fileName,token[count])!=0)
							prevPtr=prevPtr->rightSibling;
					}
		
			}

			else
			{
				prevPtr=root;
				if(count==2)
				{		
					prevPtr=prevPtr->leftChild;
					while(strcmp(prevPtr->fd_tree->fileName,token[1])!=0)
							prevPtr=prevPtr->rightSibling;
				}
	
				if(prevPtr->leftChild!=currPtr)
				{
						prevPtr=prevPtr->leftChild;
					while(prevPtr->rightSibling!=currPtr)
						prevPtr=prevPtr->rightSibling;
				}
			}
	}
	else 
	{
	printf("\n in else statement ");
	printf("\n root add: %p\n",root);
	printf("\nroot name =%s\n",root->fd_tree->fileName);
	printf("\nroot path=%s\n",root->fd_tree->fullPathName);
	prevPtr=root;
		if(prevPtr->leftChild!=currPtr)
		{
		prevPtr=prevPtr->leftChild;
		while(strcmp(prevPtr->fd_tree->fileName,token[1])!=0)
				prevPtr=prevPtr->rightSibling;
		}
	
	}
	printf("\n previous ptr %s\n", prevPtr->fd_tree->fileName);

	if(currPtr->leftChild!=NULL)
		printf("cannot be deleted");// error code to be used
	
	else
	{

		deletebst(currFileName,bstroot,P1);
		delhash(bstroot,P1);		

		if(prevPtr->leftChild==currPtr)
			prevPtr->leftChild=currPtr->rightSibling;
		else if(prevPtr->rightSibling==currPtr)
			prevPtr->rightSibling=currPtr->rightSibling;		

	free(currPtr);
	}	

}

