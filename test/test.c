#include<stdio.h>
#include "./include/mainHeader.h"
#define blockNo 1024

struct mainHeader metaHeader;

void create_vfs(char *,int );

int main(int argc,char *argv[])
{
	char *a;
	a=argv[1];	
	int blocksize=1024;

	create_vfs(a, blocksize);
	

}

void create_vfs(char *a, int blocksize) {
	
	FILE *fp;
	
	fp=fopen("prog4.dat","wb");

	int i;

	//printf("%d",fp);

	for(i=0;i<blockNo;i++) {
		fseek(fp, i*blockNo, SEEK_SET);
		fwrite("0",1,blocksize,fp);
	}
	rewind(fp);
	//printf("%d",fp);
	metaHeader.fileLabel=a;
	metaHeader.maxFileDescriptor=9;
	metaHeader.noUsedDescriptor=0;
	struct fileDescriptor fd[9];
	metaHeader.fDescriptor=fd;
	struct freeList fl[10];
	metaHeader.fList=fl;

	fseek(fp, 0, SEEK_SET);
	fwrite(&metaHeader,sizeof(struct mainHeader),1,fp);

	/*char freelist[10]={0};
	
	fseek(fp, 31, SEEK_SET);
	fwrite(freelist,10,1,fp);

	int nofd=9;

	fseek(fp, 41, SEEK_SET);
	fwrite(&nofd,4,1,fp);
	
	struct fileDescriptor fd[9];

	fseek(fp, 45, SEEK_SET);
	fwrite(fd,159,1,fp);*/
}
