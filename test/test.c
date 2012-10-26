//#include<stdio.h>
#include "../include/mainHeader.h"
//#include"../test/narrtest.c"
#define blockNo 2048
//#include<string.h>
#include<stdlib.h>
struct mainHeader metaHeader;
struct nAryTree node;
struct nAryTree *root;

extern struct nAryTree *createRoot(struct fileDescriptor *);

extern struct nAryTree *nTreeChild(struct fileDescriptor *,struct nAryTree * );

extern void print(struct nAryTree *);

void create_vfs(char *,int );

void mount_vfs(char *);

int main(int argc,char *argv[])
{
	char a[30];
	strcpy(a,argv[1]);
	int blocksize=1024;
	printf("\nI am in main function\n");
	printf("enter 1 for creating and 2 for mounting and 3 to quit\n");
	int choice, flag=1;

	while(flag) {
		printf("\nenter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				create_vfs(a, blocksize);
				break;

			case 2:
				mount_vfs(a);
				break;

			case 3: print(root);
				break;
			
			case 4:flag=0;
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

	strcpy(fd[0].fileName,"ROOT");
	strcpy(fd[0].fullPathName,"ROOT");
	fd[0].fileType='D';
	fd[0].fileSize=0;

	fseek(fp,sizeof(struct mainHeader),SEEK_SET);
	fwrite(&fd[0],sizeof(struct fileDescriptor),1,fp);

	//fseek(fp,0,SEEK_CUR);

	strcpy(fd[1].fileName,"A");
	strcpy(fd[1].fullPathName,"ROOT/A");
	fd[1].fileType='D';
	fd[1].fileSize=0;

	fseek(fp,(sizeof(struct mainHeader)+sizeof(struct fileDescriptor)),SEEK_SET);
	fwrite((fd+1),sizeof(struct fileDescriptor),1,fp);

	/*rewind(fp);
	fread(&metaHeader,sizeof(struct mainHeader),1,fp);

	metaHeader.noUsedDescriptor=0;
	rewind(fp);
	fwrite(&metaHeader,sizeof(struct mainHeader),1,fp);*/


//	fseek(fp,0,SEEK_CUR);

	strcpy(fd[2].fileName,"b");
	strcpy(fd[2].fullPathName,"ROOT/B");
	fd[2].fileType='F';
	fd[2].fileSize=0;

	fseek(fp,(sizeof(struct mainHeader)+2*sizeof(struct fileDescriptor)),SEEK_SET);
	fwrite((fd+2),sizeof(struct fileDescriptor),1,fp);

//	fseek(fp,0,SEEK_CUR);

	strcpy(fd[3].fileName,"c");
	strcpy(fd[3].fullPathName,"ROOT/A/C");
	fd[3].fileType='D';
	fd[3].fileSize=0;

	fseek(fp,(sizeof(struct mainHeader)+3*sizeof(struct fileDescriptor)),SEEK_SET);
	fwrite((fd+3),sizeof(struct fileDescriptor),1,fp);

	rewind(fp);
	fread(&metaHeader,sizeof(struct mainHeader),1,fp);
	metaHeader.noUsedDescriptor=4;
	rewind(fp);
	fwrite(&metaHeader,sizeof(struct mainHeader),1,fp);
	rewind(fp);
	/*fseek(fp,0,SEEK_CUR);

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

				printf("\n%s",root->fd_tree->fileName);
				printf("\n%s",root->fd_tree->fullPathName);
				printf("\n%c",root->fd_tree->fileType);
				printf("\n%d",root->fd_tree->fileSize);
				printf("\n");
				i=i+1;
				continue;
			}

				printf("\n%d",i);
				printf("\n%s",temp->fileName);
				printf("\n%s",root->fd_tree->fileName);
				printf("\n%s",root->fd_tree->fullPathName);
				printf("\n%c",root->fd_tree->fileType);
				printf("\n%d",root->fd_tree->fileSize);
				root=nTreeChild(temp,root);
				printf("\nend in %s\n",root->leftChild->fd_tree->fileName);
			
		i=i+1;
		}
		
		fclose(fp);


}





