#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"

void copy_file(char *P1,char *P2)
{
	
	FILE *fp,*mainfp;
	char **token;
	char destPath[100],ch;
	char prevFileName[50],currFileName[50];
	int count,blkloc,blockno;
	char *parentP1,*destParent;
	int n,i;
	struct nAryTree *currPtr,*temproot;
	struct nAryTree *destPtr,*destcurrPtr;
	char tempP1[100];
	parentP1=(char *)malloc(sizeof(char)*50);
	destParent=(char *)malloc(sizeof(char)*50);
	destcurrPtr=(struct nAryTree *)malloc(sizeof(struct nAryTree));
	
	strcpy(tempP1,P1);
	count=countSlash(tempP1);
	token=stringtok(tempP1);

	//printf("\nStarting of the delete directory\n");
	//printf("\nroot file name=%s\n",root->fd_tree->fileName);
	//printf("\nroot file path=%s\n",root->fd_tree->fullPathName );
	
	/*for(i=0;i<=count;i++)	
		printf("\n tokens are %s\n",token[i]);*/

	n=strlen(P1)-(strlen(token[count])+1);
	
	//printf("\npath %s\n",P1);
	//printf("lengths %d %d %d",strlen(P1),strlen(token[count])+1,n);
	
	//copying the parent path
		for(i=0;i<n;i++)
			parentP1[i]=P1[i];
	//strncpy(parentP1,P1,n);
	//strcat(parentP1,'\0');
	parentP1[n]='\0';
	//printf("\ntoken[0] %s\n",token[0]);
	//printf("\nparent p1 %s\n",parentP1);
	//printf("\nP1 %s\n",P1);
	strcpy(currFileName,token[count]);
	strcpy(prevFileName,token[count-1]);
		
	temproot=root;
	currPtr=curPtrFunc(parentP1,temproot);
	currPtr=temp2;//fetching the current ptr
	
	while(currPtr->rightSibling!=NULL) //moving to the correct position
	{
		if(strcmp(currPtr->fd_tree->fileName,token[count])==0) 
		break;
		currPtr=currPtr->rightSibling;
	}

	//printf("\n currptr name %s\n",currPtr->fd_tree->fileName);
	
	
	strcpy(tempP1,P2);
	count=countSlash(tempP1);
	token=stringtok(tempP1);	
	
	//for(i=0;i<=count;i++)	
	//	printf("\n tokens are %s\n",token[i]);

	n=strlen(P2)-(strlen(token[count])+1); // taking the length of the root path from the destination path

	for(i=0;i<n;i++)
		destParent[i]=P2[i];
	strcat(destParent,"\0");
	
	destPtr=curPtrFunc(destParent,root);
	destPtr=temp2;

	while(destPtr->rightSibling!=NULL) //moving to the correct position
	{
		if(strcmp(destPtr->fd_tree->fileName,token[count])==0) 
		break;
		destPtr=destPtr->rightSibling;
	}

		//printf("\n destptr name %s\n",destPtr->fd_tree->fileName);

	strcpy(destPath,destPtr->fd_tree->fullPathName);
	strcat(destPath,"/");
	strcat(destPath,destPtr->fd_tree->fileName);

	//printf("\n destPath %s\n",destPath);

//--------------------------------------------------------------------------------------------
	destcurrPtr->fd_tree=currPtr->fd_tree;
	strcpy(destcurrPtr->fd_tree->fullPathName,destPath);
	destcurrPtr->fd_tree->fileSize=0;
	destcurrPtr->fd_tree->fileType='F';
	destcurrPtr->fd_tree->blockNo=0;
	destcurrPtr->leftChild=NULL;
	destcurrPtr->rightSibling=NULL;

	if(destPtr->leftChild==NULL)
		destPtr->leftChild=destcurrPtr;
	else
	{
		destPtr=destPtr->leftChild;
		while(destPtr->rightSibling != NULL)
			destPtr=destPtr->rightSibling;
		destPtr->rightSibling=destcurrPtr;
	}	
	
		fp=fopen("temp","w");
		mainfp=fopen(metaHeader.fileLabel,"rb");
		blockno=currPtr->fd_tree->blockNo;
		fseek(mainfp,(sizeof(struct mainHeader)+blockno*1024),0);
	
		while((ch=fgetc(mainfp))!='\0')
		 fputc(ch,fp);
		fclose(mainfp);
		fclose(fp);

		mainfp=fopen(metaHeader.fileLabel,"rb+");
		fp=fopen("temp","r");
		
		for( blkloc=0;blkloc<1023;blkloc++)
			if(metaHeader.freeList[blkloc]==0)
				break;

		fseek(mainfp,(sizeof(struct mainHeader)+blkloc*1024),0);
		
		while((ch=fgetc(fp))!=EOF && count<1024) 
		{
		//	printf("%c",ch);
			count++;
			fputc(ch,mainfp);
			//fseek(mainfp,1,1);
		}
		fputc('\0',mainfp);
		destcurrPtr->fd_tree->blockNo=blkloc;
		metaHeader.freeList[blkloc]=1;
		
		metaHeader.fDescriptor[metaHeader.noUsedDescriptor]=*(destcurrPtr->fd_tree);
		//metaHeader.fDescriptor[metaHeader.noUsedDescriptor]=mh.fDescriptor[mh.noUsedDescriptor];
		metaHeader.noUsedDescriptor++;
		//metaHeader.noUsedDescriptor=mh.noUsedDescriptor;

		fwrite(&metaHeader,sizeof(struct mainHeader),1,mainfp);
		fclose(fp);
		fclose(mainfp);
}
