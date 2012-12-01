#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"
#include "funcPrototype3.h"
#include "vfs_errorcodes.h"

int error_addfile(char *P1, char *P2, char *P3)
{
    FILE *mainfp,*fp;
    int i,flag=0,size;
    struct nAryTree *currPtr;
    currPtr=(struct nAryTree *)	malloc(sizeof(struct nAryTree));
    fp=fopen("../test/SUCCESS.txt","a");

//#define ERR_VFS_ADDFILE_07 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=7;
        fprintf(fp,"%s",ERR_VFS_ADDFILE_07);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_ADDFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if(P1==NULL||P2==NULL||P3==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_ADDFILE_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_ADDFILE_02 "INVALID_CHARACTER_IN_FILENAME"
    for(i=0;i<strlen(P2);i++)
        if( (P2[i]=='\\') || (P2[i]=='/') )
        {
            flag=2;
            fprintf(fp,"%s",ERR_VFS_ADDFILE_02);
            fprintf(fp,"%s","\n");
            goto exit;       
        }
//#define ERR_VFS_ADDFILE_03 "FILE_ALREADY_EXISTS"
    currPtr=curPtrFunc1(P1,root); 
    if(currPtr==NULL) {
	flag=10;
        fprintf(fp,"%s","addfile_FAILURE SOURCE_DIRECTORY_NOT_FOUND");
        fprintf(fp,"%s","\n");
        goto exit;

    }		   
    if(currPtr!=NULL && currPtr->leftChild!=NULL && strcasecmp(currPtr->leftChild->fd_tree->fileName,P2)==0)
    {
        flag=3;
        fprintf(fp,"%s",ERR_VFS_ADDFILE_03);
        fprintf(fp,"%s","\n");
        goto exit;
    }

    if(currPtr!=NULL && currPtr->leftChild!=NULL)	
	    currPtr=currPtr->leftChild;
    while(currPtr!=NULL)
    {
        if(strcasecmp(currPtr->fd_tree->fileName,P2)==0)
        {
            flag=3;
            fprintf(fp,"%s",ERR_VFS_ADDFILE_03);
            fprintf(fp,"%s","\n");
            goto exit;
        }
    currPtr=currPtr->rightSibling;
    }
//#define ERR_VFS_ADDFILE_04 "FILE_SYSTEM_FULL"
    if(metaHeader.noUsedDescriptor==1024)
    {
        flag=4;
        fprintf(fp,"%s",ERR_VFS_ADDFILE_04);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_ADDFILE_05 "CANNOT_WRITE_TO_DATAFILE"
    //mainfp=fopen();
//#define ERR_VFS_ADDFILE_06 "FILE_TOO_LARGE"

    mainfp=fopen(P3,"r");
    if(mainfp==NULL) {
	flag=8;
        fprintf(fp,"%s",ERR_VFS_ADDFILE_08);
        fprintf(fp,"%s","\n");        
        goto exit;
    }
    fclose(mainfp);

    mainfp=fopen(P3,"r");
    fseek(mainfp,0,2);
   
    size=ftell(mainfp);
    if(size>1024)
    {
        flag=6;
        fprintf(fp,"%s",ERR_VFS_ADDFILE_06);
        fprintf(fp,"%s","\n");
        fclose(mainfp);
        goto exit;
    }
    fclose(mainfp);

exit:fclose(fp);
return flag;
}

int error_listfile(char *P1, char *P2)
{
    FILE *mainfp,*fp;
    int flag=0;
    struct nAryTree *currPtr;
   
    fp=fopen("../test/SUCCESS.txt","a");
//#define ERR_VFS_LISTFILE_04 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=4;
        fprintf(fp,"%s",ERR_VFS_LISTFILE_04);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_LISTFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if((P1==NULL)||(P2==NULL))
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_LISTFILE_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_LISTFILE_01 "SOURCE_FILE_PATH_NOT_FOUND"
    currPtr=curPtrFunc1(P1,root);  
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_LISTFILE_01);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_LISTFILE_02 "NOT_A_TEXT_FILE"
    if(strstr(currPtr->fd_tree->fileName,".txt")==NULL)
    {
        flag=2;
        fprintf(fp,"%s",ERR_VFS_LISTFILE_02);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_LISTFILE_03 "CANNOT_CREATE_OUTPUTFILE"
    mainfp=fopen(P2,"w");
    if(mainfp==NULL)
    {
        flag=3;
        fprintf(fp,"%s",ERR_VFS_LISTFILE_03);
        fprintf(fp,"%s","\n");
        goto exit;
    }
    fclose(mainfp);

exit:fclose(fp);
return flag;
}

int error_updatefile(char *P1, char *P2)
{
    FILE *mainfp,*fp;
    int flag=0;
    struct nAryTree *currPtr;

    fp=fopen("../test/SUCCESS.txt","a");
//#define ERR_VFS_UPDATEFILE_04 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=4;
        fprintf(fp,"%s",ERR_VFS_UPDATEFILE_04);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_UPDATEFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if((P1==NULL)||(P2==NULL))
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_UPDATEFILE_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_UPDATEFILE_01 "INTERNAL_FILE_NOT_FOUND"
    currPtr=curPtrFunc1(P1,root); 
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_UPDATEFILE_01);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_UPDATEFILE_02 "EXTERNAL_FILE_NOT_FOUND"
    mainfp=fopen(P2,"r");
    if(mainfp==NULL)
    {
        flag=2;
        fprintf(fp,"%s",ERR_VFS_UPDATEFILE_02);
        fprintf(fp,"%s","\n");
        goto exit;
    }
    if(mainfp!=NULL)
        fclose(mainfp);
//#define ERR_VFS_UPDATEFILE_03 "EXTERNAL_FILE_TOO_LARGE"
exit:fclose(fp);
return flag;
}

int error_removefile(char *P1)
{
    FILE *fp;
    int flag=0;
    struct nAryTree *currPtr;

    fp=fopen("../test/SUCCESS.txt","a");
//#define ERR_VFS_REMOVEFILE_02 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=4;
        fprintf(fp,"%s",ERR_VFS_REMOVEFILE_02);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_REMOVEFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
// Use this error even when the given argument is a directory and not a file
    if(P1==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_REMOVEFILE_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
    currPtr=curPtrFunc1(P1,root);   
    //#define ERR_VFS_REMOVEFILE_01 "CANNOT_FIND_SPECIFIED_FILE"
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_REMOVEFILE_01);
        fprintf(fp,"%s","\n");
        goto exit;
    }   

    if((currPtr->fd_tree->fileType!='F')||(currPtr->fd_tree->fileType!='f'))
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_REMOVEFILE_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }

exit:fclose(fp);
return flag;       
}

int error_movefile(char *P1,char *P2)
{
    FILE *fp;
    int flag=0;
    struct nAryTree *currPtr;

    fp=fopen("../test/SUCCESS.txt","a");
//#define ERR_VFS_MOVEFILE_06 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=4;
        fprintf(fp,"%s",ERR_VFS_MOVEFILE_06);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_MOVEFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if((P1==NULL)||(P2==NULL))
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_MOVEFILE_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_MOVEFILE_01 "CANNOT_FIND_SOURCEFILE"
    currPtr=curPtrFunc1(P1,root);
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_MOVEFILE_01);
        fprintf(fp,"%s","\n");
        goto exit;   
    }
//#define ERR_VFS_MOVEFILE_02 "CANNOT_FIND_DESTINATION_PATH"
    currPtr=curPtrFunc1(P2,root);
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_MOVEFILE_02);
        fprintf(fp,"%s","\n");
        goto exit;   
    }

exit:fclose(fp);
return flag;
}

int error_copyfile(char *P1,char *P2)
{
    FILE *fp;
    int flag=0;
    struct nAryTree *currPtr,*destPtr;

    fp=fopen("../test/SUCCESS.txt","a");
//#define ERR_VFS_COPYFILE_05 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=5;
        fprintf(fp,"%s",ERR_VFS_COPYFILE_05);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_COPYFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if((P1==NULL)||(P2==NULL))
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_COPYFILE_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_COPYFILE_01 "CANNOT_FIND_SOURCEFILE"
    currPtr=curPtrFunc1(P1,root);   
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_COPYFILE_01);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_COPYFILE_02 "CANNOT_FIND_DESTINATIONPATH"
    destPtr=curPtrFunc1(P2,root);  
    if(destPtr==NULL)
    {
        flag=2;
        fprintf(fp,"%s",ERR_VFS_COPYFILE_02);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_COPYFILE_03 "CANNOT_COPY_DIR_TO_FILE"
    if((strcmp(currPtr->fd_tree->fileName,destPtr->fd_tree->fileName)==0)||(currPtr->fd_tree->fileType=='D')
	||(currPtr->fd_tree->fileType=='d'))
    {
        flag=3;
        fprintf(fp,"%s",ERR_VFS_COPYFILE_03);
        fprintf(fp,"%s","\n");
        goto exit;   
    }
//#define ERR_VFS_COPYFILE_04 "FILE_SYSTEM_FULL"
    if(metaHeader.noUsedDescriptor==1024)
    {
        flag=4;
        fprintf(fp,"%s",ERR_VFS_COPYFILE_04);
        fprintf(fp,"%s","\n");
        goto exit;
    }

exit:fclose(fp);
return flag;
}

int error_exportfile(char *P1,char *P2)
{
    FILE *mainfp,*fp;
    int flag=0;
    struct nAryTree *currPtr;

    fp=fopen("../test/SUCCESS.txt","a");
//#define ERR_VFS_EXPORTFILE_04 "VFS_NOT_MOUNTED"
    if(root==NULL)
    {
        flag=4;
        fprintf(fp,"%s",ERR_VFS_EXPORTFILE_04);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_EXPORTFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if((P1==NULL)||(P2==NULL))
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_EXPORTFILE_00);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_EXPORTFILE_01 "CANNOT_FIND_SOURCEFILE"
    currPtr=curPtrFunc1(P1,root);    
    if(currPtr==NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_EXPORTFILE_01);
        fprintf(fp,"%s","\n");
        goto exit;
    }
//#define ERR_VFS_EXPORTFILE_02 "CANNOT_CREATE_OUTPUTFILE"
    mainfp=fopen(P2,"w");
    if(mainfp==NULL)
    {
        flag=2;
        fprintf(fp,"%s",ERR_VFS_EXPORTFILE_02);
        fprintf(fp,"%s","\n");
        goto exit;
    }
    if(mainfp!=NULL)
        fclose(mainfp);
//#define ERR_VFS_EXPORTFILE_03 "CANNOT_EXPORT_DIR"
    if((currPtr->fd_tree->fileType=='D')||(currPtr->fd_tree->fileType=='d'))
    {
        flag=3;
        fprintf(fp,"%s",ERR_VFS_EXPORTFILE_03);
        fprintf(fp,"%s","\n");
        goto exit;
    }

exit:fclose(fp);
return flag;
}

int error_searchfile(char *P1,char *P2)
{
    int flag=0;
    FILE *fp;
    fp=fopen("../test/SUCCESS.txt","a");

//#define ERR_VFS_SEARCHFILE_00 "VFS_INSUFFICIENT_ARGUMENTS"
    if(P1==NULL || P2== NULL)
    {
        flag=1;
        fprintf(fp,"%s",ERR_VFS_SEARCHFILE_00);
        fprintf(fp,"%c",'\n');
        goto exit;
    }	

//#define ERR_VFS_SEARCHFILE_02 "VFS_NOT_MOUNTED"

    if(bstroot== NULL)
    {
        flag=2;
        fprintf(fp,"%s",ERR_VFS_SEARCHFILE_02);
        fprintf(fp,"%c",'\n');
        goto exit;
    }
exit:fclose(fp);
return flag;   

}

