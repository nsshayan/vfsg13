#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"
#include "vfs_errorcodes.h"

struct fileDescriptor fd[1024];
int i=0;
void clear_memory(struct nAryTree *);

void unmount_vfs(char *P1) {
	int j;

	FILE *mainfp;
	
	traverse(root);

	printf("file names in unmount::");
	for(j=0; j<i; j++) {
		printf("\n%s\n",fd[j].fileName);
	}	
	printf("\nused fd count::%d\n",i);

	mainfp=fopen(P1,"rb+");

	if(mainfp==NULL)
		printf(ERR_VFS_UNMOUNT_01);

	else {
		for(j=0; j<i; j++) {
			metaHeader.fDescriptor[j]=fd[j];
		}
		metaHeader.noUsedDescriptor=i;
		fwrite(&metaHeader,sizeof(struct mainHeader),1,mainfp);
	}
	fclose(mainfp);
		
	clear_memory(root->leftChild);
	
	free(root);
	free(bstroot);
	free(hashnode);
}

void traverse(struct nAryTree *temp)
{
	if(temp != NULL)
	{		
		fd[i++]=*(temp->fd_tree);
		traverse(temp->rightSibling);		
		traverse(temp->leftChild);				
	}	
}

void clear_memory(struct nAryTree *temp)
{

	if(temp != NULL)
	{		
		traverse(temp->rightSibling);		
		traverse(temp->leftChild);				
		free(temp);
	}
}

