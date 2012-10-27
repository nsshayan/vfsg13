#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct filedescripter{
	int fdno;	
	char filename[20];
	char filepath[50];
}fd;


typedef struct node{
	fd  *file;
	struct node *leftchild;
	struct node *rightchild;
}node; 


char filename[20],filepath[50];
int fdno;
node *root;

int search(char *filepath,node *root);
node* insert(node * root);
node* add(char *filename,char *filepath,int fdno);

void main(){
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
				scanf("%s", filepath);
				printf("Enter the fdno.\n");
				scanf("%d",& fdno);
				
				root = insert(root);
				}
				else
					break;	
			}while(1);	
			break;
		case 2:
			printf("Enter the filepath u want to search\n");
			scanf("%s", filepath);
			b=search(filepath,root);
			break;
		default:
			break;
		}
	}
	
}


node* add(char filename[],char filepath[], int fdno){
	node *temp;
	fd *tempfile;
	

	temp=(node*)malloc(sizeof(node));     
	temp->rightchild=NULL;
	temp->leftchild=NULL;
	tempfile = (fd*)malloc(sizeof(fd));
	strcpy(tempfile->filename,filename);
	strcpy(tempfile->filepath,filepath);
	tempfile->fdno=fdno;
	temp->file= tempfile;
	return temp;


}

node* insert(node* temp){
	if(root==NULL){
		root= add(filename,filepath,fdno);
		return root;
	}	
	if(root->leftchild == NULL && strcmp(root->file->filename,filename)<0){
		root->leftchild = add(filename,filepath,fdno);
		return root;
	}
	if(root->rightchild==NULL && strcmp(root->file->filename,filename)>0){
		root->rightchild = add(filename,filepath,fdno);
		return root;
	}


	if(temp->leftchild == NULL && strcmp(temp->file->filename,filename)<0){
		temp->leftchild = add(filename,filepath,fdno);
		return root;
	}		
	else if	(strcmp(temp->file->filename,filename)<0){
		temp=temp->leftchild; 
		root=insert(temp);
		return root;
	}


	if(temp->rightchild==NULL && strcmp(temp->file->filename,filename)>0){
		temp->rightchild = add(filename,filepath,fdno);
		return root; 
	}
	else if	(strcmp(temp->file->filename,filename)>0){
		temp=temp->rightchild; 
		root=insert(temp);
		return root;
	}
		
}


int search(char filepath[],node *temp){
	//node *temp2=temp;	
	if(temp != NULL){
	search(filepath,temp->leftchild);
	if(!(strcmp(filepath,temp->file->filepath))){
		printf("%s\n%s\n%d\n",temp->file->filepath,temp->file->filename,temp->file->fdno);
		return 0;
	}
	search(filepath,temp->rightchild);
	}
}









