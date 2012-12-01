#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"
#include "vfs_errorcodes.h"

struct fileDescriptor fd[1024];
int i;
void clear_memory(struct nAryTree *);
void clear_bst(node *);
//void initialize();

void unmount_vfs(char *P1) {
//	printf("\nroot name in unmount::%s\n",root->fd_tree->fileName);	
	
	int j;
	
	FILE *mainfp;
		
	i=0;
	//initialize();
	struct nAryTree *tempVar;
	tempVar=root;
	traverse(tempVar);

	
//	printf("\nfile names in unmount::\n");	
//	for(j=0; j<i; j++) {
//		printf("\n%s\n",fd[j].fileName);
//	}	
//	printf("\nused fd count::%d\n",i);

	mainfp=fopen(P1,"rb+");
	
	if(mainfp==NULL)
//		printf("file not found\n");				

	else {
		for(j=0; j<i; j++) {
			metaHeader.fDescriptor[j]=fd[j];
		}
		metaHeader.noUsedDescriptor=i;
		fwrite(&metaHeader,sizeof(struct mainHeader),1,mainfp);
	}
	fclose(mainfp);
		
	clear_memory(root->leftChild);
	
	root=NULL;
	bstroot=NULL;
	hashnode=NULL;
	free(root);
	clear_bst(bstroot);
	free(bstroot);
	free(hashnode);

//	printf("\nroot address%p\n",root);

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
		clear_memory(temp->rightSibling);		
		clear_memory(temp->leftChild);				
		free(temp);
		//temp=NULL;
	}
}


void clear_bst(node *temp)
{
	if(temp != NULL)
	{		
		clear_bst(temp->rightchild);		
		clear_bst(temp->leftchild);				
		free(temp);
		//temp=NULL;
	}
}
/*void initialize()
{
int i;
for(i=0;i<1024;i++)
	fd[]=NULL;
}*/

