#include "../include/mainHeader.h"
#include<stdlib.h>

struct nAryTree nNode;
struct nAryTree *nNodePtr;

//struct fileDescriptor fd;

struct nAryTree *createRoot(struct fileDescriptor *fd) {

	struct nAryTree *root;
	nNodePtr= (struct nAryTree *) malloc (sizeof(struct nAryTree));
	//char name[]="RO3OT";
	strcpy(fd->fileName,"ROOT");
	strcpy(fd->fullPathName,"ROOT");
	fd->fileType='D';
	fd->fileSize=0;
	nNodePtr->fd_tree=fd;
	nNodePtr->leftChild=NULL;
	nNodePtr->rightSibling=NULL;		
	root=nNodePtr;	

return root;

}


/*struct nAryTree createChild(struct nAryTree root) {
	
	struct nAryTree *leftchild, *rightsibling;

	if(root == NULL) {
		printf("Directory not found");
	}

	
	

return root;
}*/
