#include "mainHeader.h"
#include "funcPrototype.h"
#include  "funcPrototype2.h"
#include  "funcPrototype3.h"
#include "vfs_errorcodes.h"

int error_createvfs(char *P1,int P2)
{
FILE *mainfp,*fp;
int i,flag=0;

fp=fopen("../test/SUCCESS.txt","a");
    if(P1==NULL || P2==0)
    {
    flag=1;
    fprintf(fp,"%s",ERR_VFS_CREATE_00);
    fprintf(fp,"%s","\n");
    goto exit;
    }
   
    mainfp=fopen(P1,"rb");
    if(mainfp!=NULL)
    {
        fprintf(fp,"%s",ERR_VFS_CREATE_01);
        fprintf(fp,"%s","\n");
        flag=1;   
        fclose(mainfp);
        goto exit;
    }

    for(i=0;i<strlen(P1);i++)
    {
        if((P1[i]=='/') || (P1[i]=='\\'))
        {
            fprintf(fp,"%s",ERR_VFS_CREATE_03);
            fprintf(fp,"%s","\n");
            flag=3;
            goto exit;
        }
    }   
   
      if(P2<1 || P2>1024)
    {
        fprintf(fp,"%s",ERR_VFS_CREATE_04);
        fprintf(fp,"%s","\n");
        flag=5;
        goto exit;
    }

    if(strlen(P1)>30)
    {
        fprintf(fp,"%s",ERR_VFS_CREATE_05);
        fprintf(fp,"%s","\n");
        goto exit;
    }

    mainfp=fopen(P1,"wb");
    if(mainfp==NULL)
    {
        fprintf(fp,"%s",ERR_VFS_CREATE_02);
        fprintf(fp,"%s","\n");
        flag=2;
        goto exit;
    }
    if(mainfp!=NULL)
    fclose(mainfp);
       
exit:fclose(fp);   
return flag;
}

int error_mountvfs(char *P1) {

    int flag=0;
    FILE *mainfp,*fp;
    //char ch;

    fp=fopen("../test/SUCCESS.txt","a");
   
    if(strlen(P1)==0)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_MOUNT_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
   
    mainfp=fopen(P1,"rb");   
    if(mainfp==NULL) {
        fprintf(fp,"%s",ERR_VFS_MOUNT_01);
        fprintf(fp,"%s","\n");
        flag=1;
        fclose(fp);
        goto exit;
    }
   
    /*else if(mainfp!=NULL){
    // this for error code ERR_VFS_MOUNT_02
    #define ERR_VFS_MOUNT_02 "CANNOT_READ_FROM_FILE"
    }*/
   
    //ERR_VFS_MOUNT_03 "VFS_ALREADY_MOUNTED"
    else if(mainfp!=NULL && root!=NULL)
    {
        fprintf(fp,"%s",ERR_VFS_MOUNT_03);
        fprintf(fp,"%s","\n");
        flag=3;
        fclose(fp);
        goto exit;
    }
   

exit:
if(mainfp!=NULL && root!=NULL)
    fclose(fp);
return flag;
}


int error_unmountvfs(char *P1) {

    int flag=0;
    FILE *mainfp,*fp;
    //char ch;

    fp=fopen("../test/SUCCESS.txt","a");
    mainfp=fopen(P1,"rb");
       
    if(P1==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_UNMOUNT_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }

    //#define ERR_VFS_UNMOUNT_01 "DATA_FILE_NOT_FOUND"
    if(mainfp==NULL) {
        fprintf(fp,"%s",ERR_VFS_UNMOUNT_01);
        fprintf(fp,"%s","\n");
        flag=1;
        goto exit;
    }
    if(mainfp!=NULL)
        fclose(mainfp);

    //#define ERR_VFS_UNMOUNT_02 "CANNOT_WRITE_TO_FILE"
   
    //#define ERR_VFS_UNMOUNT_03 "VFS_NOT_MOUNTED"
    if(root==NULL){
        fprintf(fp,"%s",ERR_VFS_UNMOUNT_03);
        fprintf(fp,"%s","\n");
        flag=3;
        goto exit;
    }
exit:fclose(fp);
return flag;
}

int error_makedir(char *P1,char *P2) {

    int flag=0,i;
    FILE *fp;
    struct nAryTree *currPtr;
   
    fp=fopen("../test/SUCCESS.txt","a");
    //mainfp=fopen(metaHeader.fileLabel,"rb");

	//#define ERR_VFS_MAKEDIR_05 "VFS_NOT_MOUNTED"
     if(root==NULL)
    {
	flag=1;
	fprintf(fp,"%s",ERR_VFS_MAKEDIR_05);
	fprintf(fp,"%s","\n");
	goto exit;
    }

//#define ERR_VFS_MAKEDIR_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if(P1==NULL || P2==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_MAKEDIR_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//changed to FILESYSTEM_FULL from UNABLE_TO_CREATE_NEWDIR
//#define ERR_VFS_MAKEDIR_01 "FILESYSTEM_FULL"
    if(metaHeader.noUsedDescriptor==1024)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_MAKEDIR_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_MAKEDIR_02 "INVALID_CHARACTER_IN_DIRNAME"
     if(strlen(P2)>30)
    {
        flag=2;
        fprintf(fp,"%s","Directory Name too long");
        fprintf(fp,"%s","\n");
        goto exit;
    }
       
	for(i=0;i<strlen(P2);i++)
		if((P2[i]=='\\')||(P2[i]=='/'))
		{
			flag=2;
			fprintf(fp,"%s",ERR_VFS_MAKEDIR_02);
			fprintf(fp,"%s","\n");
			goto exit;
		}
//#define ERR_VFS_MAKEDIR_03 "DIRECTORY_ALREADY_EXISTS"
	currPtr=currPtrReturn(P1,P2);
	//exist=searchbst(P2,P1,bstroot,"../test/success.txt");
	if(currPtr!=NULL)
	{
	flag=3;
        fprintf(fp,"%s",ERR_VFS_MAKEDIR_03);
        fprintf(fp,"%s","\n");
        goto exit;
	}


exit:fclose(fp);
return flag;
}

int error_deletedir(char *P1) {
    int flag=0;
    FILE *fp;
    struct nAryTree *currPtr;
   
    fp=fopen("../test/SUCCESS.txt","a");
//#define ERR_VFS_DELETEDIR_04 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=4;
        fprintf(fp,"%s",ERR_VFS_DELETEDIR_04);
        fprintf(fp,"%s","\n");
        goto exit;
    }

    currPtr=curPtrFunc(P1,root);
//#define ERR_VFS_DELETEDIR_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if(P1==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_DELETEDIR_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
   
   
//#define ERR_VFS_DELETEDIR_01 "CANNOT_FIND_SPECIFIED_DIR"
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_DELETEDIR_01);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_DELETEDIR_02 "DIRECTORY_IS_NOT_EMPTY"
   
    if(currPtr->leftChild!=NULL)
    {
        flag=2;
        fprintf(fp,"%s",ERR_VFS_DELETEDIR_02);
        fprintf(fp,"%s","\n");
        goto exit;
    }

exit:fclose(fp);
return flag;
}

int error_movedir(char *P1, char *P2)
{
    int flag=0;
    FILE *fp;
    struct nAryTree *currPtr,*destPtr;   

    fp=fopen("../test/SUCCESS.txt","a");

//#define ERR_VFS_MOVEDIR_08 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=8;
        fprintf(fp,"%s",ERR_VFS_MOVEDIR_08);
        fprintf(fp,"%s","\n");
        goto exit;
    }

//#define ERR_VFS_MOVEDIR_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if(P1==NULL||P2==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_MOVEDIR_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_MOVEDIR_01 "CANNOT_FIND_SPECIFIED_SOURCEDIR"
//(if specified dir is not there, it is not created in this case unlike in add dir)
    currPtr=curPtrFunc(P2,root);
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_MOVEDIR_01);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_MOVEDIR_02 "CANNOT_FIND_SPECIFIED_DESTINATIONDIR"
    currPtr=curPtrFunc(P1,root);
    if(currPtr==NULL)
    {
        flag=2;
        fprintf(fp,"%s",ERR_VFS_MOVEDIR_02);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_MOVEDIR_04 "SOURCE_CANNOT_BE_FILE"   
    if((currPtr->fd_tree->fileType=='F')||(currPtr->fd_tree->fileType=='f'))
    {
        flag=4;
        fprintf(fp,"%s",ERR_VFS_MOVEDIR_04);
        fprintf(fp,"%s","\n");
        goto exit;
    }
   
    currPtr=curPtrFunc(P2,root);
    destPtr=curPtrFunc(P1,root);
//#define ERR_VFS_MOVEDIR_05 "DESTINATION_ALREADY_HAVE_SOURCE_DIR"
    destPtr=destPtr->leftChild;
    while(destPtr!=NULL)
    {
        if(strcasecmp(destPtr->leftChild->fd_tree->fileName,currPtr->fd_tree->fileName)==0)
        {
            flag=5;
            fprintf(fp,"%s",ERR_VFS_MOVEDIR_05);
            fprintf(fp,"%s","\n");
            goto exit;
        }
    destPtr=destPtr->rightSibling;
    }
//#define ERR_VFS_MOVEDIR_06 "CANNOT_MOVE_PARENT_TO_CHILD_DIR"
    destPtr=curPtrFunc(P1,root);
    currPtr=curPtrFunc(P2,root);
        if(currPtr->leftChild==destPtr)
        {
            flag=6;
            fprintf(fp,"%s",ERR_VFS_MOVEDIR_06);
            fprintf(fp,"%s","\n");
            goto exit;
        }
       
    currPtr=currPtr->leftChild;
    while(currPtr!=NULL)
    {
        if(strcasecmp(currPtr->leftChild->fd_tree->fileName,destPtr->fd_tree->fileName)==0)
        {
            flag=6;
            fprintf(fp,"%s",ERR_VFS_MOVEDIR_06);
            fprintf(fp,"%s","\n");
            goto exit;
        }
    }
//#define ERR_VFS_MOVEDIR_07 "DESTINATION_CANNOT_BE_FILE"
    destPtr=curPtrFunc(P1,root);
    if((destPtr->fd_tree->fileType=='F')||(destPtr->fd_tree->fileType=='f'))
    {
        flag=6;
        fprintf(fp,"%s",ERR_VFS_MOVEDIR_06);
        fprintf(fp,"%s","\n");
        goto exit;
    }


exit:fclose(fp);
return flag;
}

int error_listdir(char *P1, int P2, char *P3 )
{
    int flag=0;
    FILE *mainfp,*fp;
    struct nAryTree *currPtr;   

    fp=fopen("../test/SUCCESS.txt","a");

//#define ERR_VFS_LISTDIR_03 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=3;
        fprintf(fp,"%s",ERR_VFS_LISTDIR_03);
        fprintf(fp,"%s","\n");
        goto exit;

    }
//#define ERR_VFS_LISTDIR_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if(P1==NULL||P2==0||P3==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_LISTDIR_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_LISTDIR_01 "CANNOT_FIND_SPECIFIED_PATH_OR_DIR"
    currPtr=curPtrFunc(P1,root);
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_LISTDIR_01);
        fprintf(fp,"%s","\n");
        goto exit;   
    }
//#define ERR_VFS_LISTDIR_02 "INVALID_FLAG"
    if((P2!=0)||(P2!=1))
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_LISTDIR_02);
        fprintf(fp,"%s","\n");
        goto exit;   
    }
//#define ERR_VFS_LISTDIR_04 "CANNOT_CREATE_OUTPUTFILE"
    mainfp=fopen(P3,"w");
    if(mainfp==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_LISTDIR_04);
        fprintf(fp,"%s","\n");
        goto exit;   
    }
    fclose(mainfp);

exit:fclose(fp);
return flag;
}
