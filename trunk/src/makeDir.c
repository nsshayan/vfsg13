#include "mainHeader.h"
#include "funcPrototype.h"
#include "vfs_errorcodes.h"


void makeDir(char *P1,char *P2) {
	
	
	struct fileDescriptor *fd1;
	fd1=(struct fileDescriptor *) malloc (sizeof(struct fileDescriptor));
	printf("\nroot=%p",root);
	printf("\nP1=%s",P1);
	printf("\nP2=%s\n",P2);
	strcpy(fd1->fileName,P2);
	//strcat(fd1->fileName,"\0");
	printf("\n%s\n",fd1->fileName);
	strcpy(fd1->fullPathName,P1);
	//strcat(fd1->fullPathName,"\0");
	printf("\n%s\n",fd1->fullPathName);
	fd1->fileType='D';
	fd1->fileSize=0;
	
	
	nTreeChild(fd1);
	bstroot=bstinsert(bstroot,fd1);
	hashing(fd1);
	
}
