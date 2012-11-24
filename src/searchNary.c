#include "mainHeader.h"
#include "funcPrototype.h"

struct nAryTree *curPtrFunc(char P1[],struct nAryTree *temp) {				

	if(temp != NULL) {
		if (strcmp(temp->fd_tree->fullPathName,P1)==0) 	{	
			printf("\n temp %p\n",temp);						
			printf("\nreq path name%s\n",temp->fd_tree->fullPathName);	
			temp2=temp;		
			return temp2;		
		}			
		curPtrFunc(P1,temp->rightSibling);				
		curPtrFunc(P1,temp->leftChild);										
	}
	else 
	return NULL;
return temp2;
}

/*struct nAryTree *curPtrFuncName(char parentPath[],char fileName[],struct nAryTree *temp) {				

	if(temp != NULL) {
		if (strcmp(temp->fd_tree->fileName,parentPath)==0) {	
			printf("\n temp %p\n",temp);						
			printf("\nreq path name%s\n",temp->fd_tree->fullPathName);	
			temp2=temp;		
			return temp;		
		}			
		curPtrFunc(P1,temp->rightSibling);				
		curPtrFunc(P1,temp->leftChild);										
	}
	else return NULL; 
} */


