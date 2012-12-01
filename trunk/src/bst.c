#include "mainHeader.h"
#include "funcPrototype.h"

/* typedef struct filedescripter{	
	char filename[20];
	char filepath[50];
	char filetype; // stores the type of the file
	int filesize;
}fd;  */


/* typedef struct node{
	fd  *file;
	struct node *leftchild;
	struct node *rightchild;
}node; */


char filename[20],filepath[50],filetype,filename2[20];
int filesize;


/* void main(){
	int a,b;
	
	while(1){
	printf("Enter your choice \n 1: Add file \n 2: Search file \n");
	scanf("%d",&a);
	
	switch(a){
		case 1:
			do{
				printf("Enter the filename or Exit to abort\n");
				scanf("%s", filename);
				if(strcmp(filename,"Exit"))
				{				
				printf("Enter the filepath\n");
				scanf("%s",filepath);
				printf("Enter the filesize\n");
				scanf("%d",&filesize);
				//printf("Enter the filetype\n");
				//scanf("%c",&filetype);
				filetype='d';
				bstroot = insert(bstroot);
				}
				else
					break;	
			}while(1);	
			break;
		case 2:
			printf("Enter the filepath u want to search\n");
			scanf("%s", filepath);
			b=search(filepath,bstroot);
			break;
		default:
			break;
		}
	}
	
} */


node* add(struct fileDescriptor *fdtemp){
	node *temp;
		
	temp=(node*)malloc(sizeof(node));     
	temp->rightchild=NULL;
	temp->leftchild=NULL;

	temp->file=fdtemp;

	return temp;


}

node* insert(node* temp,struct fileDescriptor *fd){
	if(bstroot==NULL){		
		bstroot= add(fd);
		return bstroot;
	}	
	if(bstroot->leftchild == NULL && strcmp(bstroot->file->fileName,fd->fileName)<0){
		bstroot->leftchild = add(fd);
		return bstroot;
	}
	if(bstroot->rightchild==NULL && strcmp(bstroot->file->fileName,fd->fileName)>=0){
		bstroot->rightchild = add(fd);
		return bstroot;
	}


	if(temp->leftchild == NULL && strcmp(temp->file->fileName,fd->fileName)<0){
		temp->leftchild = add(fd);
		return bstroot;
	}		
	else if	(strcmp(temp->file->fileName,fd->fileName)<0){
		temp=temp->leftchild; 
		bstroot=insert(temp,fd);
		return bstroot;
	}


	if(temp->rightchild==NULL && strcmp(temp->file->fileName,fd->fileName)>=0){
		temp->rightchild = add(fd);
		return bstroot; 
	}
	else if	(strcmp(temp->file->fileName,fd->fileName)>=0){
		temp=temp->rightchild; 
		bstroot=insert(temp,fd);
		return bstroot;
	}

}


 int searchBstPath(char filepath[],node *temp){
	//node *temp2=temp;	
	if(temp != NULL){
	searchBstPath(filepath,temp->leftchild);
	if(!(strcmp(filepath,temp->file->fullPathName))){
		//printf("\nsearch bst using pathname %s\n%s\n%d\n",temp->file->fullPathName,temp->file->fileName,temp->file->fileSize);
		return 0;
	}
	searchBstPath(filepath,temp->rightchild);
	}
} 

void display(node *temp){	
	
	if(temp != NULL){		
		//printf("\n%s\n%s\n%d\n",temp->file->fullPathName,temp->file->fileName,temp->file->fileSize);
//		printf("\nfile Name=%s",temp->file->fileName);
//		printf("\nleft child of %s",temp->file->fileName);
		display(temp->leftchild);	
//		printf("\n right child of %s",temp->file->fileName);			
		display(temp->rightchild);
	}
} 








