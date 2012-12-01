#include "mainHeader.h"

struct nAryTree *createRoot(struct fileDescriptor *fd) {

	struct nAryTree *nRootPtr;
	
	nRootPtr= (struct nAryTree *) malloc (sizeof(struct nAryTree));
	nRootPtr->fd_tree=fd;
	nRootPtr->leftChild=NULL;
	nRootPtr->rightSibling=NULL;		
		

return nRootPtr;

}

void nTreeChild(struct fileDescriptor *fd){
	
	struct nAryTree *currPtr,*rightNode,*leftNode;	
	char cfilepath[100];//specifies the current file path of the node to be placed 
	char delimiter[]="/";
	char *token[50];
	int i,count=0;
        i = 0;
//	printf("\n I am in nTreeChild creation\n");
	if(fd==NULL)
//	printf("fd is null");
//	else
//	printf("fd is not null"); 
	//printf("\nFile Path Name=%s\n",fd->fullPathName);
      	
	strcpy(cfilepath,fd->fullPathName);
//	printf("\nCounting the number of '/'");
		//Counts the number of '/' in the file path of the received file descriptor
		for(i=0;cfilepath[i]!='\0';i++) 
			if(cfilepath[i]=='/')
				count++;
//	printf("\nTokenizing the path with '/'");
	token[0]= strtok(cfilepath,delimiter);
	strcat(token[0],"\0");
//	printf("\n0.%s",token[0]);
		for(i=1;i<count+1;i++){
			token[i]=strtok(NULL,delimiter);
			strcat(token[i],"\0");
//			printf("\n%d.%s",i,token[i]);
		}
//	printf("\nInitializing the current pointer and counter i");
	currPtr=root;
	i=0;
//	printf("\nCount=%d\n",count);
//	printf("\n%s\n",currPtr->fd_tree->fileName);
	
			rightNode=(struct nAryTree *)calloc(1,sizeof(struct nAryTree));
			leftNode=(struct nAryTree *)calloc(1,sizeof(struct nAryTree));
	
//	printf("\n Travering to get to the right point");
	//Logic for traversing through left  child
			
		if(count==0 && root->leftChild==NULL)
			{
//				printf("\nInserting the first node");
				leftNode->fd_tree=fd;
				leftNode->leftChild=NULL;
				leftNode->rightSibling=NULL;
				root->leftChild=leftNode;
			}

		else 
		{
			currPtr=currPtr->leftChild;
			i=i+1;
			if(count==0 && root->leftChild!=NULL)
		  	{
//				printf("\n Inserting under the root node");
				while(currPtr->rightSibling!=NULL)
					currPtr=currPtr->rightSibling;
				rightNode->fd_tree=fd;
				rightNode->leftChild=NULL;
				rightNode->rightSibling=NULL;
				currPtr->rightSibling=rightNode;
			}
			else if(count>=1)
			{
//				printf("\n Inserting to the correct folder");
				while(i<=count)
				{	
//					printf("\ncurrPtr=%s",currPtr->fd_tree->fileName);
					while(strcasecmp(token[i],currPtr->fd_tree->fileName)!=0)
						currPtr=currPtr->rightSibling;
					if((i<=(count-1)) && (currPtr->leftChild!=NULL))
					currPtr=currPtr->leftChild;// adding after three levels getting segmentation fault at this point.
					i++;
				}
				if(currPtr->leftChild==NULL)
				{
					//add left node		
					leftNode->fd_tree=fd;
					leftNode->leftChild=NULL;
					leftNode->rightSibling=NULL;
					currPtr->leftChild=leftNode;
				}
				else
				{
					currPtr=currPtr->leftChild;
					//add right node after trversing towards extreme right
					while(currPtr->rightSibling!=NULL)
						currPtr=currPtr->rightSibling;
					rightNode->fd_tree=fd;
					rightNode->leftChild=NULL;
					rightNode->rightSibling=NULL;
					currPtr->rightSibling=rightNode;
				}
			}
		}

//printf("\n");
}



void print(struct nAryTree *temp)
{
	
	if(temp != NULL)
	{
//	printf("\n fileName=%s",temp->fd_tree->fileName);
//	printf("\n right Sibling of %s",temp->fd_tree->fileName);
//	print(temp->rightSibling);
//	printf("\nleftChild of %s",temp->fd_tree->fileName);
//	print(temp->leftChild);
	}
		
}
