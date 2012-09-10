#include<stdio.h>
#include "include/mainHeader.h"
int main() {

FILE *fp;

fp=fopen("prog4.dat","rb");

printf("%lu",fp);

	//fread(nodf, 4, 1, fp);

	//printf("%d",*nodf);

struct mainHeader *mh;

fread(mh,sizeof(struct mainHeader),1,fp);

printf("%lu",mh);

//printf("filelabel=%d",mh->maxFileDescriptor);
	/*int i; char a[30];

	for(i=0;i<20;i++) {
		a[i]=fgetc(fp);
		printf("%c",a[i]);
	}*/

}
