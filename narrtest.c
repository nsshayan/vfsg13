#include "../include/mainHeader.h"

struct nAryTree nNode;
struct nAryTree *nNodePtr;

struct nAryTree createRoot() {

	struct nAryTree *root;
	nNodePtr= (struct nAryTree *) malloc (sizeof(struct nAryTree));

	nNodePtr->fdp->fileName="Root";
	nNodePtr->fdp->filePath="Root";
	nNodePtr->fdp->fileType='D';
	nNodePtr->fdp->fieSize=NULL;
	nNodePtr->leftChild=NULL;
	nNodePtr->rightSibling=NULL;

	root=nNodePtr;

return root;

}

struct nAryTree createChild(struct nAryTree root) {
	
	struct nAryTree *leftchild, *rightsibling;

	if(root==NULL) {
		printf("Directory not found");
	}

	
	

return root;
}
