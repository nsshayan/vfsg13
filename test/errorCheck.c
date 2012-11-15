#include "mainHeader.h"
#include "funcPrototype.h"
#include  "funcPrototype2.h"
#include "vfs_errorcodes.h"

int error_createvfs(char *P1,int P2)
{
FILE *mainfp,*fp;
int i,flag=0;

fp=fopen("../text_files/crestevfs_out.txt","w");
	for(i=0;i<strlen(P1);i++)
		if(!(isalnum(P1[i])))
		{
			fprintf(fp,"%s",ERR_VFS_CREATE_04);
			fprintf(fp,"%s","\n");
			flag=4;
		}

	if(P2<1024)
	{
		fprintf(fp,"%s",ERR_VFS_CREATE_05);
		fprintf(fp,"%s","\n");
		flag=5;
	}

	else if(P2>(1024*1024))
	{
		fprintf(fp,"%s",ERR_VFS_CREATE_03);
		fprintf(fp,"%s","\n");
		flag=3;
	}

	mainfp=fopen(P1,"rb");
	if(mainfp!=NULL)
	{
		fprintf(fp,"%s",ERR_VFS_CREATE_01);
		fprintf(fp,"%s","\n");
		flag=1;	
		fclose(mainfp);		
	}

	if(mainfp==NULL)
	{
		fprintf(fp,"%s",ERR_VFS_CREATE_02);
		fprintf(fp,"%s","\n");
		flag=2;
	}
	
fclose(fp);	
return flag;
}

int error_mountvfs(char *P1) {

	int flag=0;
	FILE *mainfp,*fp;
	char ch;

	fp=fopen("../text_files/mountvfs_out.txt","w");
	mainfp=fopen(P1,"rb");
		
	if(mainfp==NULL) {
		fprintf(fp,"%s",ERR_VFS_MOUNT_01);
		fprintf(fp,"%s","\n");
		flag=1;
	}

	else {
		ch=fgetc(mainfp);
		if(ch=='\0') {
			fprintf(fp,"%s",ERR_VFS_MOUNT_02);
			fprintf(fp,"%s","\n");
			flag=2;
		}
	
		fread(&metaHeader,sizeof(struct mainHeader),1,mainfp);
		if(strcasecmp(metaHeader.fDescriptor[0].fileName,"ROOT")!=0) {
			fprintf(fp,"%s",ERR_VFS_MOUNT_03);
			fprintf(fp,"%s","\n");
			flag=3;
		}
	fclose(mainfp);
	}

fclose(fp);
return flag;
}


int error_unmountvfs(char *P1) {

	int flag=0;
	FILE *mainfp,*fp;
	char ch;

	fp=fopen("../text_files/unmountvfs_out.txt","w");
	mainfp=fopen(P1,"rb");
		
	if(mainfp==NULL) {
		fprintf(fp,"%s",ERR_VFS_UNMOUNT_01);
		fprintf(fp,"%s","\n");
		flag=1;
	}


fclose(fp);
return flag;
}
