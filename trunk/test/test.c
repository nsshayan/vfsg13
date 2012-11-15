#include "mainHeader.h"
#include "funcPrototype.h"


void create_vfs(char *fileLabel, int blockNo) {

	int blocksize=1024;	

	FILE *fp;

	fp=fopen(fileLabel,"wb");

	int i;
	
	for(i=0;i<(blockNo+160);i++) {
		fseek(fp, i*blockNo, SEEK_SET);
		fwrite("0",1,blocksize,fp);
	}
	rewind(fp);

	strcpy(metaHeader.fileLabel,fileLabel);
	metaHeader.maxFileDescriptor=1024;
	
	strcpy(metaHeader.fDescriptor[0].fileName,"ROOT");
	strcpy(metaHeader.fDescriptor[0].fullPathName,"ROOT");
	metaHeader.fDescriptor[0].fileType='D';
	metaHeader.fDescriptor[0].fileSize=0;
	
	metaHeader.noUsedDescriptor=1;
	for(i=0;i<1023;i++)
		metaHeader.freeList[i]=0;
	fwrite(&metaHeader,sizeof(struct mainHeader),1,fp);
		

fclose(fp);
}


struct nAryTree *mount_vfs(char *fileLabel)
{
	int i=0;
	FILE *fp;
	fp=fopen(fileLabel,"rb+");

	struct mainHeader mh;
	struct fileDescriptor *temp;	
	
	//printing the meta header part
	fread(&mh,sizeof(struct mainHeader),1,fp);
	printf("\n%s",mh.fileLabel);
	printf("\n%d",mh.maxFileDescriptor);
	printf("\n%d",mh.noUsedDescriptor);

	//printf("filelabel=%s",mh.fileLabel);
	//printf("\n");

	//fd=mh.fDescriptor;

	root=(struct nAryTree *)malloc(sizeof(struct nAryTree));
	//bstroot=(node *)malloc(sizeof(node));

		while(i<mh.noUsedDescriptor)
		{
			temp=(struct fileDescriptor *) malloc (sizeof(struct fileDescriptor));
			//fseek(fp,sizeof(struct mainHeader)+i*sizeof(struct fileDescriptor),SEEK_SET);
			temp=&(mh.fDescriptor[i]);
			//fread(temp,sizeof(struct fileDescriptor),1,fp);

			if(i==0)
			{				
				
				//printf("\n%d",i);
				printf("\n%s",temp->fileName);
				printf("\n%s",temp->fullPathName);
				printf("\n%c",temp->fileType);
				printf("\n%d\n",temp->fileSize);
				printf("\ncall for nary\n");
				
				root=createRoot(temp);
				printf("\ncall for bst\n");

				bstroot=bstinsert(bstroot,temp);
				printf("\ncall for hashtable\n");
				hashing(temp);

				printf("\naft all call\n");				

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
				
				printf("\n inserting the child into the n arry tree");
				nTreeChild(temp);
				printf("\n inserting the bst tree");
				bstroot=bstinsert(bstroot,temp);
				printf("inserting the hashtable nodes");
				//hashing(temp);

				printf("\n displaying the bst tree");
				//display(bstroot);
				printf("\nend in %s\n",root->leftChild->fd_tree->fileName);
			
		i=i+1;
		}
		
		fclose(fp);
return root;

}





