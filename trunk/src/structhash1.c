#include "mainHeader.h"
#include "funcPrototype.h"

struct fileDescripter *fd;

char filename[20],filepath[50];
list *a[52],*result[10];

void search_file(char *P1,char *P2) {	
	int i=0;
	searchHash(P1);
	while(result[i]!=NULL) {
		searchbst(result[i]->file->fileName,result[i]->file->fullPathName,bstroot,P2);
		i++;
	}	
	
}

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


list * searchHash(char filename[]){
	list *search;
	int y,x=65,i=0,j=0;
	y=filename[0];
	list *start=NULL;
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
			result[j]=search;
			strcpy(path,search->file->fullPathName);
			start=listinsert(start,path);
		}
		search=search->next;
		j++;
	}
	return start;
}


list *listinsert(list *start, char path[])
{	
	list *temp,*temp2;
	temp2=start;
	temp=(list *)malloc(sizeof(list));
	strcpy(temp->paths,path);
	temp->next=NULL;

	if(start==NULL)
	{	start=temp;		
	}
	else
	{	while(temp2->next!=NULL)
		{	temp2=temp2->next;
		}
		temp2->next=temp;		
	}
return start;
}


void delhash(node *temp,char filepathname[]){
	char filename[100];
	node *temp1=NULL;
	list *index,*temp2;
	while(temp)
	{
	   if(strcmp(temp->file->fullPathName,filepathname)>0)
	    {
		    temp1=temp;
		    temp=temp->rightchild;
    		}
 		else
    	{
    		temp1=temp;
    		temp=temp->leftchild;
    	}
    	}
    	strcpy(filename,temp1->file->fileName);
	int y,x=65,i=0;
	y=filename[0];
	while(i!=52){
		if(y==x){
			index=a[i];
			break;
		}
		x++;
		i++;
	}
		while(index->next!=NULL)
		{	
			if(!(strcmp(filename,index->file->fileName))){
				break;
			}
			temp2=index;
			index=index->next;
		}
	if(index->next == NULL){
		temp2->next=NULL;
	}
	else{
		temp2->next=index->next;
		index->next=NULL;
		free(index);
	}
}







