//#include<stdio.h>
#include "../include/mainHeader.h"
//#include"../test/narrtest.c"
#define blockNo 1024
//#include<string.h>
#include<stdlib.h>
struct mainHeader metaHeader;
struct nAryTree node;

extern struct nAryTree *createRoot(struct fileDescriptor *);

void create_vfs(char *,int );

void mount_vfs(char *);

int main(int argc,char *argv[])
{
	char a[30];
	strcpy(a,argv[1]);	
	int blocksize=1024;
	
	printf("enter 1 for creating and 2 for mounting and 3 to quit\n");	
	int choice, flag=1;
	
	while (flag) {
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				create_vfs(a, blocksize);				
				break;
	
			case 2: 
				mount_vfs(a);
				break;
		
			case 3: flag=0;
				break;

			default: printf("enter a valid choice");
		}
	}


return 0;
}

void create_vfs(char *a, int blocksize) {
	
	FILE *fp;
	
	fp=fopen("prog6.dat","wb");

	int i;

	//printf("%d",fp);
	for(i=0;i<blockNo;i++) {
		fseek(fp, i*blockNo, SEEK_SET);
		fwrite("0",1,blocksize,fp);
	}
	rewind(fp);
	//printf("%d",fp);
	
	strcpy(metaHeader.fileLabel,a);
	metaHeader.maxFileDescriptor=9;
	metaHeader.noUsedDescriptor=0;
	struct fileDescriptor fd[9];
	//fseek(fp,sizeof(struct mainHeader),SEEK_SET);
	metaHeader.fDescriptor=fd;//sizeof(struct mainHeader);
	//rewind(fp);
	struct freeList fl[10];
	metaHeader.fList=fl;

	fseek(fp, 0, SEEK_SET);
	fwrite(&metaHeader,sizeof(struct mainHeader),1,fp);
	
	//printf("%d",sizeof(struct mainHeader));
	
	//new lines added from here
	
	//initialising the first descriptor

	/*strcpy(fd[0].fileName,"ROOT");
	strcpy(fd[0].fullPathName,"ROOT");
	fd[0].fileType='D';
	fd[0].fileSize=0;
	fwrite(fd,sizeof(struct fileDescriptor),1,fp);*/
	//int j=ftell(fp);----- used to get the current location of where  fp is pointing
	//printf("\n%d\n",j);----- Checking current location of the pointer
	//fseek(fp,0,SEEK_CUR);

	/*int k;
	for( k=0;k<9;k++)
	{
		strcpy(fd[k].fileName,"NULL");
		strcpy(fd[k].fullPathName,"NULL");
		fd[k].fileType=' ';
		fd[k].fileSize=0;
		fwrite((fd+k),sizeof(struct fileDescriptor),1,fp);
	}*/
	
	/*strcpy(fd[0].fileName,"root");
	strcpy(fd[0].fullPathName,"root");
	fd[0].fileType='D';
	fd[0].fileSize=0;

	fwrite((fd+0),sizeof(struct fileDescriptor),1,fp);	
	
	fseek(fp,0,SEEK_CUR);
	
	strcpy(fd[1].fileName,"a");
	strcpy(fd[1].fullPathName,"root/a");
	fd[1].fileType='D';
	fd[1].fileSize=0;

	fwrite((fd+1),sizeof(struct fileDescriptor),1,fp);	

	fseek(fp,0,SEEK_CUR);
	
	strcpy(fd[2].fileName,"b");
	strcpy(fd[2].fullPathName,"root/b");
	fd[2].fileType='F';
	fd[2].fileSize=0;

	fwrite((fd+2),sizeof(struct fileDescriptor),1,fp);

	fseek(fp,0,SEEK_CUR);
	
	strcpy(fd[3].fileName,"c");
	strcpy(fd[3].fullPathName,"root/a/c");
	fd[3].fileType='D';
	fd[3].fileSize=0;

	fwrite((fd+3),sizeof(struct fileDescriptor),1,fp);			

	fseek(fp,0,SEEK_CUR);
	
	strcpy(fd[3].fileName,"d");
	strcpy(fd[3].fullPathName,"root/a/d");
	fd[1].fileType='F';
	fd[1].fileSize=0;

	fwrite((fd+4),sizeof(struct fileDescriptor),1,fp);	

	*/

	/*char freelist[10]={0};
	
	fseek(fp, 31, SEEK_SET);
	fwrite(freelist,10,1,fp);

	int nofd=9;

	fseek(fp, 41, SEEK_SET);
	fwrite(&nofd,4,1,fp);
	
	struct fileDescriptor fd[9];

	fseek(fp, 45, SEEK_SET);
	fwrite(fd,159,1,fp);*/
fclose(fp);
}


void mount_vfs(char *a)
{

	FILE *fp;

	fp=fopen("prog6.dat","rb+");

	struct mainHeader mh;
	struct fileDescriptor *fd;
	
	//printing the meta header part
	fread(&mh,sizeof(struct mainHeader),1,fp);
	printf("filelabel=%s",mh.fileLabel);
	printf("\n");
	
	
	
	
	struct nAryTree *node;

	if(mh.noUsedDescriptors==0)
	{	 
	node=createRoot(fd);
	mh.noUsedDescriptors=1;
	
	fd=(struct fileDescriptor *) malloc(sizeof(struct fileDescriptor));	
	fd=node->fd_tree;
		printf("\n Written into the descriptor");
		printf("\n%s",fd->fileName);
		printf("\n%s",fd->fullPathName);
		printf("\n%c",fd->fileType);
		printf("\n%d",fd->fileSize);
		printf("\nWritten in to the file");
	fseek(fp,0,SEEK_CUR);
	fwrite(fd,sizeof(struct fileDescriptor),1,fp);
		printf("\n%s\n",node->fd_tree->fileName);
		printf("\n After writing into the file");
	}

		
	 if(mh.noUsedDescriptors > 0)
		{
				
			
		}
	
		fclose(fp);
	

}





