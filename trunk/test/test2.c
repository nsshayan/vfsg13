#include "../include/mainHeader.h"
int main() {

FILE *fp;

struct fileDescriptor fd;

fp=fopen("prog6.dat","rb");
if(fp==NULL)
printf("fp null pointer");
//printf("%lu",fp);

	//fread(nodf, 4, 1, fp);

	//printf("%d",*nodf);

struct mainHeader mh;



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

//printf("%lu",mh);
//if(mh==NULL)
//printf("null pointer");
//else
	/*int i; char a[30];

	for(i=0;i<20;i++) {
		a[i]=fgetc(fp);
		printf("%c",a[i]);
	}*/

}
