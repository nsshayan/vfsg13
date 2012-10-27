#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mainHeader.h"

typedef struct filedescripter{
	char filename[20];
	char filepath[50];
}fd;


typedef struct node{
	fd  *file;
	struct node *next;
}list; 



void search(char *filename);
void hashing(char *filename,char *filepath);
list* add(char *filename,char *filepath, list *start);





char filename[20],filepath[50];
list *a[52]={};



int main(){
	int a;
	while(1){
	printf("Enter your choice \n 1: Add file \n 2: Search file \n");
	scanf("%d",&a);
	
	switch(a){
		case 1:
			mount_vfs();				
			break;
		case 2:
			printf("Enter the filename u want to search\n");
			scanf("%s", filename);
			search(filename);
			break;
		default:
			break;
		}
	}
	return 0;

}

list* add(char filename[],char filepath[], list *start){
	list *temp,*llist;
	fd *tempfile;
	llist= start;

	temp=(list*)malloc(sizeof(list));     
	temp->next=NULL;
	tempfile = (fd*)malloc(sizeof(fd));
	strcpy(tempfile->filename,filename);
	strcpy(tempfile->filepath,filepath);
	temp->file= tempfile;

	if(llist==NULL){
		start=temp;
	}
	else{
		while(llist->next != NULL){
				llist=llist->next;	
		}
		llist->next=temp;
		
	}
	return start;
}


void hashing(struct fileDescriptor *temp){
	int y,x=65,i=0;
	char c[100];
	strcpy(a,temp->fd_tree->fileName);
	char b[100];
	strcpy(b,temp->fd_tree->filePath);
	y=c[0];
	while(i!=52){
		if(y==x){
			a[i]=add(c,b,a[i]);
			break;
		}
		x++;
		i++;
	}

}


void search(char filename[]){
	list *search;
	int y,x=65,i=0;
	y=filename[0];
	while(i!=52){
		if(y==x){
			search=a[i];
			break;
		}
		x++;
		i++;
	}

	while(search !=NULL){
			if(!(strncmp(filename,search->file->filename,strlen(filename)))){
			printf("Filename=%s\nFilepath=%s\n",search->file->filename,search->file->filepath);
			}
			search=search->next;
		}



}

void mount_vfs()
{
	int i=0;
	FILE *fp;
	fp=fopen("prog6.dat","rb+");

	struct mainHeader mh;
	struct fileDescriptor *temp;

	//printing the meta header part
	fread(&mh,sizeof(struct mainHeader),1,fp);
	printf("\n%s",mh.fileLabel);
	printf("\n%d",mh.maxFileDescriptor);
	printf("\n%d",mh.noUsedDescriptor);

	//printf("filelabel=%s",mh.fileLabel);
	printf("\n");

	//fd=mh.fDescriptor;

	root=(struct nAryTree *)malloc(sizeof(struct nAryTree));


		while(i<mh.noUsedDescriptor)
		{
			temp=(struct fileDescriptor *) malloc (sizeof(struct fileDescriptor));
			fseek(fp,sizeof(struct mainHeader)+i*sizeof(struct fileDescriptor),SEEK_SET);
			fread(temp,sizeof(struct fileDescriptor),1,fp);

			if(i==0)
			{				
				/*fseek(fp,sizeof(struct mainHeader),SEEK_SET);
				fread(temp,sizeof(struct fileDescriptor),1,fp);*/
				printf("\n%d",i);
				printf("\n%s",temp->fileName);
				printf("\n%s",temp->fullPathName);
				printf("\n%c",temp->fileType);
				printf("\n%d\n",temp->fileSize);

				root=createRoot(temp);
				
			}
				
		i=i+1;
		}
		
		fclose(fp);


}



