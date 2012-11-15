#include "../include/mainHeader.h"
int searchbst(char [], node *);
int main() {
/*
FILE *fp;
char ch;
char fileName[]="shravan.txt";
struct fileDescriptor *fd;
int i,blockno;

fp=fopen("shayan","rb");
if(fp==NULL)
printf("fp null pointer");
//printf("%lu",fp);

	//fread(nodf, 4, 1, fp);

	//printf("%d",*nodf);

struct mainHeader mh;

fread(&mh,sizeof(struct mainHeader),1,fp);
fd=&(mh.fDescriptor[0]);

printf("\nDisplaying the contents of the first file descriptor\n");
printf("\nfile name=%s\n",fd->fileName);
printf("\nfile path=%s\n",fd->fullPathName);
printf("\nfile type=%c\n",fd->fileType);

	printf("\nPrinting the details of metaheader\n");
	for (i=0; i<1024; i++) {
		printf("%d",mh.freeList[i]);
		printf("%s",mh.fDescriptor[i].fileName);				
	}


//printing the meta header part
fread(&mh,sizeof(struct mainHeader),1,fp);
printf("filelabel=%s",mh.fileLabel);
printf("\n");

//fd=mh.fDescriptor;
//printing the first file descriptor part
fseek(fp,sizeof(struct mainHeader),SEEK_SET);
fread(&fd,sizeof(struct fileDescriptor),1,fp);
printf("\nfileName=%s",fd.fileName);
printf("\nfullPathName=%s",fd.fullPathName);
printf("\nfileType=%c",fd.fileType);
printf("\nfileSize=%d\n",fd.fileSize);
//printf();
blockno=mh.fDescriptor[0].blockNo;
fseek(fp,(sizeof(struct mainHeader)+blockno*1024),0);
printf("\nprinting th data in the data block\n");
while((ch=fgetc(fp))!='\0')
{
	printf("%c",ch);
}

*/

char a[]="root";
searchbst(a,bstroot);

return 0;
}


int searchbst(char filename[], node *temp){

	if(temp != NULL){
		searchbst(filename,temp->leftchild);
		if(strstr(temp->file->fileName,filename)){
			printf("%s\n%s\n%c\n",temp->file->fileName,temp->file->fullPathName,temp->file->fileType);            
			return 0;
		}
		searchbst(filename,temp->rightchild);
	}

return 0;
}
