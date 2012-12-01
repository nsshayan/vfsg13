#include "mainHeader.h"
#include "funcPrototype2.h"
#include "funcPrototype.h"

void add_file ( char *P1, char *P2, char *P3) {
	
	//struct mainHeader mh;
	FILE *fp,*mainfp;
	int count=0;
	int blkloc;// to identify which block is free
	char ch;	
	struct fileDescriptor *fd1;
	//struct nAryTree *curDir;
	fd1=(struct fileDescriptor *) malloc (sizeof(struct fileDescriptor));
	
	/*printf("\nroot=%p",root);
	printf("\nroot filename=%s",root->fd_tree->fileName);
	printf("\nroot file name=%s\n",metaHeader.fDescriptor[0].fileName);
	printf("\nP1=%s",P1);
	printf("\nP2=%s\n",P2);*/
	
	//creating file descriptor
	strcpy(fd1->fileName,P2);	
	//printf("\n%s\n",fd1->fileName);
	strcpy(fd1->fullPathName,P1);
	//printf("\n%s\n",fd1->fullPathName);
	fd1->fileType='F';
	fd1->fileSize=1024;
	
	
	//opening the main vfs file
	mainfp=fopen(vfsName,"rb+");
	//fread(&mh,sizeof(struct mainHeader),1,mainfp);//copying the updated metaheader to the variable mh
	
	for( blkloc=0;blkloc<1023;blkloc++)
		if(metaHeader.freeList[blkloc]==0)
			break;

	fseek(mainfp,(sizeof(struct mainHeader)+blkloc*1024),0);//moving the main file pointer to the first location of the data block
	
	//reading from file
	fp=fopen(P3,"r");
	
	while((ch=fgetc(fp))!=EOF && count<1024) 
	{
		printf("%c",ch);
		count++;
		fputc(ch,mainfp);
		//fseek(mainfp,1,1);
	}
	fputc('\0',mainfp);
	fd1->blockNo=blkloc;
	metaHeader.freeList[blkloc]=1;
	//add the code to write the fd's into the vfs file
	//printf("\nroot file Name=%s\n",root->fd_tree->fileName);
	
	memmove(&metaHeader.fDescriptor[metaHeader.noUsedDescriptor], fd1, sizeof (struct fileDescriptor));
	/*strcpy(metaHeader.fDescriptor[mh.noUsedDescriptor].fileName,fd1->fileName);
	strcpy(metaHeader.fDescriptor[mh.noUsedDescriptor].fullPathName,fd1->fullPathName);
	metaHeader.fDescriptor[mh.noUsedDescriptor].fileType=fd1->fileType;
	metaHeader.fDescriptor[mh.noUsedDescriptor].fileSize=fd1->fileSize;
	metaHeader.fDescriptor[mh.noUsedDescriptor].blockNo=fd1->blockNo;*/
	//metaHeader.fDescriptor[metaHeader.noUsedDescriptor]=mh.fDescriptor[mh.noUsedDescriptor];
	metaHeader.noUsedDescriptor++;
	//metaHeader.noUsedDescriptor=mh.noUsedDescriptor;
	
	rewind(mainfp);
	fwrite(&metaHeader,sizeof(struct mainHeader),1,mainfp);
	fclose(fp);
	fclose(mainfp);
	//passing the file descriptor to all the data structures
	//printf("\nroot filename=%s",root->fd_tree->fileName);
	nTreeChild(fd1);
	
	bstinsert(bstroot,fd1);
	hashing(fd1);
	//printf("\nroot filename=%s",root->fd_tree->fileName);

}
