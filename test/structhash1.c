#include "mainHeader.h"
#include "funcPrototype.h"

struct fileDescripter *fd;

char filename[20],filepath[50];
list *a[52];


/* int main(){
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

} */

list* hashadd(char filename[],char filepath[], list *start){
	list *temp,*llist;
	struct fileDescriptor *tempfile;
	llist= start;

	temp=(list*)malloc(sizeof(list));     
	temp->next=NULL;
	tempfile = (struct fileDescriptor *)malloc(sizeof(struct fileDescriptor));
	strcpy(tempfile->fileName,filename);
	strcpy(tempfile->fullPathName,filepath);
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
	strcpy(c,temp->fileName);
	char b[100];
	strcpy(b,temp->fullPathName);
	y=c[0];
	while(i!=52){
		if(y==x){
			a[i]=hashadd(c,b,a[i]);
			break;
		}
		x++;
		i++;
	}

}


llist * searchHash(char filename[]){
	list *search;
	int y,x=65,i=0,j=0;
	y=filename[0];
	llist *start=NULL;
	char path[100];
	while(i!=52){
		if(y==x){
			search=a[i];
			break;
		}
		x++;
		i++;
	}

	while(search != NULL){
		if(!(strncmp(filename,search->file->fileName,strlen(filename)))){
			printf("Filename=%s\nFilepath=%s\n",search->file->fileName,search->file->fullPathName);
			strcpy(path,search->file->fullPathName);
			start=listinsert(start,path);
		}
		search=search->next;
	}
	return start;
}


llist *listinsert(llist *start, char path[])
{	
	llist *temp,*temp2;
	temp2=start;
	temp=(llist *)malloc(sizeof(llist));
	strcpy(temp->paths,path);
	temp->next=NULL;

	if(start==NULL)
	{	start=temp;
		return start;
	}
	else
	{	while(temp2->next!=NULL)
		{	temp2=temp2->next;
		}
		temp2->next=temp;
		return start;
	}
}


