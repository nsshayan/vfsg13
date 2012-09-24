#include "../include/mainHeader.h"
//#include<stdlib.h>

//struct nAryTree nNode;


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
//free(nRootPtr);
return nRootPtr;

}


struct nAryTree *nTreeChild(struct fileDescriptor *fd,struct nAryTree *root) {
	
	struct nAryTree *currPtr,*rightNode,*leftNode;	
	char cfilepath[100];//specifies the current file path of the node to be placed 
	char delimiter[]="/";
	char *token[50];
	int i,count=0;

	printf("\nIn nary tree creating child\n");
	
	if(root == NULL) {
		printf("Directory not found");
	return NULL;
	}


printf("\nhi\n");
printf("\nFile Path Name=%s\n",fd->fullPathName);
	strcpy(cfilepath,fd->fullPathName);
		for(i=0;cfilepath[i]!='\0';i++)  //Counts the number of '/' in the file path of the received file descriptor
			if(cfilepath[i]=='/')
				count++;

	token[0]= strtok(cfilepath,delimiter);
		for(i=1;i<count+1;i++)
			token[i]=strtok(NULL,delimiter);
	
	currPtr=root;
	i=0;
printf("\nCount=%d\n",count);
	printf("\n%s\n",currPtr->fd_tree->fileName);
	
	printf("\nafter malloc\n");
			rightNode=(struct nAryTree *)calloc(1,sizeof(struct nAryTree));
			leftNode=(struct nAryTree *)calloc(1,sizeof(struct nAryTree));
	
	//Logic for traversing through left  child
		while(i<count)			 
		{
							
			printf("\n token[1]=%s \t file Name=%s",token[1],currPtr->fd_tree->fileName);
			
			if(strcasecmp(token[1],currPtr->fd_tree->fileName)==0)
			{
				printf("\nIn if part of N-AryTree Child creation\n");
				while(currPtr->rightSibling!=NULL)
					currPtr=currPtr->rightSibling;

				/*strcpy(rightNode->fd_tree->fileName,fd->fileName);
				printf("\nIn n are child\n");
				strcpy(rightNode->fd_tree->fullPathName,fd->fullPathName);
				rightNode->fd_tree->fileType=fd->fileType;
				rightNode->fd_tree->fileSize=fd->fileSize;*/
				rightNode->fd_tree=fd;
				rightNode->leftChild=NULL;
				rightNode->rightSibling=NULL;
				currPtr->rightSibling=rightNode;
				
				//printf("rightNode not created");	
			}
			else
			{
								printf("\nIn else part of N-AryTree Child creation\n");
				while(currPtr->leftChild!=NULL)
					currPtr=currPtr->leftChild;
				
				printf("\n\n");
				printf("\nIn else part of N-AryTree Child creation\n");
				printf("\nfile name=%s\n",fd->fileName);
				printf("\nfile name=%s\n",fd->fullPathName);
				printf("\nfile type=%c\n",fd->fileType);
				printf("\n%d\n",sizeof(leftNode->fd_tree->fileName));	
				//leftNode->fd_tree->fileName=fd->fileName;
				/*strcpy(leftNode->fd_tree->fileName,fd->fileName);
				printf("\nfile name=%s\n",leftNode->fd_tree->fileName);
				strcpy(leftNode->fd_tree->fullPathName,fd->fullPathName);
				printf("\nfile name=%s\n",leftNode->fd_tree->fileName);
				leftNode->fd_tree->fileType=fd->fileType;
				printf("\nfile name=%s\n",leftNode->fd_tree->fileName);
				leftNode->fd_tree->fileSize=fd->fileSize;
				printf("\nfile name=%s\n",leftNode->fd_tree->fileName);*/
				leftNode->fd_tree=fd;
				leftNode->leftChild=NULL;
				printf("\nfile name=%s\n",leftNode->fd_tree->fileName);
				leftNode->rightSibling=NULL;
				printf("\nfile name=%s\n",leftNode->fd_tree->fileName);
				printf("\nfile name=%s\n",leftNode->fd_tree->fullPathName);
				printf("\nfile type=%c\n",leftNode->fd_tree->fileType);
				//printf("\n%u\n",leftNode);			
				currPtr->leftChild=leftNode;
			}
		i++;
		}



return root;
}


void print(struct nAryTree *root)
{
//struct nAryTree *currPtr;

//currPtr=root;
printf("\n root file name=%s\n",root->fd_tree->fileName);
	//printf("\nThe left child created are::");
	if(root->leftChild!=NULL)
	{
		//printf("\n%s",currPtr->fd_tree->fileName);
		//printf("\n%s",currPtr->fd_tree->fullPathName);
		//printf("\n%c",currPtr->fd_tree->fileType);
		//printf("\n%d",currPtr->fd_tree->fileSize);
			print(root->leftChild);

		
	}

printf("%s\n",root->fd_tree->fileName);
	
	if(root->rightSibling!=NULL)
	{
		//printf("\n%s",currPtr->fd_tree->fileName);
		//printf("\n%s",currPtr->fd_tree->fullPathName);
		//printf("\n%c",currPtr->fd_tree->fileType);
		//printf("\n%d",currPtr->fd_tree->fileSize);
			print(root->rightSibling);

		
	}
printf("\n");
}
