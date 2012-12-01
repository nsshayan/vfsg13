#include "mainHeader.h"
#include "funcPrototype.h"

char addName[50];
FILE *fp;
void listDir(char P1[], int P2, char P3[]) {
	
	struct nAryTree *temp; 	
	//temp=(struct nAryTree *) malloc(sizeof(struct nAryTree));
	int flag;
	fp=fopen(P3,"w");
	//printf("\n fp %p\n",fp);		
	
	if(root==NULL || root->leftChild==NULL) 
		flag=0;
	//	printf("\nNo list exists\n");
	
	else {
	//	printf("\n root %p\n",root);	

		temp=curPtrFunc(P1,root);
		temp=temp2;
	//	printf("\n after returning temp %p\n",temp);						
		//printf("\nreq path name%s\n",temp->fd_tree->fullPathName);			
	
	//	printf("==========Listing the directories=============");	

		if( P2 == 0) {
			listNonRec(temp);		
		}

		if( P2 == 1) {
			listRec(temp);
		}
	}

fclose(fp);

}

/* struct nAryTree *curPtrFunc(char P1[],struct nAryTree *temp) {				

	if(temp != NULL) {
		if (strcmp(temp->fd_tree->fullPathName,P1)==0) 	{	
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

void listNonRec(struct nAryTree *temp) {		
	
	if( temp != NULL ) {
	//	printf("\n%s\n", temp->fd_tree->fileName);
		while( temp->rightSibling != NULL ) {
			temp=temp->rightSibling;			
	//		printf("\n%s\n", temp->fd_tree->fileName);
			strcpy(addName,temp->fd_tree->fileName);
			addToFile(addName);
		}
	}
}

void listRec(struct nAryTree *temp) {
			
	if(temp != NULL) {
	//	printf("\n fileName=%s",temp->fd_tree->fileName);
		strcpy(addName,temp->fd_tree->fileName);				
		addToFile(addName);
		listRec(temp->rightSibling);
		listRec(temp->leftChild);
		//printf("\n fileName=%s",temp->fd_tree->fileName);
	}		
}

void addToFile(char addName[]) {

	fprintf(fp,"%s %c",addName,'\n');
	
}
