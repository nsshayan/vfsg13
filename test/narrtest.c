#include "../include/mainHeader.h"
#include<stdlib.h>

struct nAryTree nNode;


//struct fileDescriptor fd;

struct nAryTree *createRoot(struct fileDescriptor *fd) {

	struct nAryTree *nRootPtr;
	struct nAryTree *root;
	nRootPtr= (struct nAryTree *) malloc (sizeof(struct nAryTree));
	//char name[]="RO3OT";
	/*strcpy(fd->fileName,"ROOT");
	strcpy(fd->fullPathName,"ROOT");
	fd->fileType='D';
	fd->fileSize=0;*/
	nRootPtr->fd_tree=fd;
	nRootPtr->leftChild=NULL;
	nRootPtr->rightSibling=NULL;		
	root=nRootPtr;	
free(nRootPtr);
return root;

}


struct nAryTree *nTreeChild(struct fileDescriptor *fd,struct nAryTree *root) {
	
	struct nAryTree *currPtr,*rightNode,*leftNode;	
	char cfilepath[100];//specifies the current file path of the node to be placed 
	char delimiter[]="/";
	char *token[50];
	int i,count=0;

	printf("\nIn n are child\n");
	
	if(root == NULL) {
		printf("Directory not found");
	return NULL;
	}
	strcpy(cfilepath,fd->fullPathName);
		for(i=0;cfilepath[i]!='\0';i++)  //Counts the number of '/' in the file path of the received file descriptor
			if(cfilepath[i]=='/')
				count++;
	token[0]= strtok(cfilepath,delimiter);
		for(i=1;i<count+1;i++)
			token[i]=strtok(NULL,delimiter);
	
currPtr=root;i=0;
rightNode=calloc(1,sizeof(struct nAryTree));
leftNode=calloc(1,sizeof(struct nAryTree));
printf("after malloc");
//Logic for traversing through left  child
		while(i<count)			 
		{
			
			if(token[1]!=currPtr->fd_tree->fileName)
			{
				
				while(currPtr->rightSibling!=NULL)

				currPtr=currPtr->rightSibling;
				strcpy(rightNode->fd_tree->fileName,fd->fileName);
				printf("\nIn n are child\n");
				strcpy(rightNode->fd_tree->fullPathName,fd->fullPathName);
				rightNode->fd_tree->fileType=fd->fileType;
				rightNode->fd_tree->fileSize=fd->fileSize;
				rightNode->leftChild=NULL;
				rightNode->rightSibling=NULL;
				currPtr->rightSibling=rightNode;
				
				//printf("rightNode not created");	
			}
			else
			{
				while(currPtr->leftChild!=NULL)
					currPtr=currPtr->leftChild;

				
				strcpy(leftNode->fd_tree->fileName,fd->fileName);
				strcpy(leftNode->fd_tree->fullPathName,fd->fullPathName);
				leftNode->fd_tree->fileType=fd->fileType;
				leftNode->fd_tree->fileSize=fd->fileSize;
				leftNode->leftChild=NULL;
				leftNode->rightSibling=NULL;
				currPtr->leftChild=leftNode;
			}
		}

return root;
}
