#include<string.h>
#include<stdio.h>

void main()
{


char cfilepath[]="ROOT/A/B/C";//specifies the current file path of the node to be placed 
	char delimiter[]="/";
	char *token[50];
	//char str[][20];

/*token[0]= strtok(cfilepath,delimiter);
token[1]=strtok(NULL,delimiter);
token[2]=strtok(NULL,delimiter);
token[3]=strtok(NULL,delimiter);

printf("%s\n",token[0]);
printf("%s\n",token[1]);
printf("%s\n",token[2]);
printf("%s\n",token[3]); */

int i;
i=strspn(cfilepath,"/");
printf("%d",i);

}

//commands
createvfs shayan 1024
mountvfs shayan
makedir root vehicle
makedir root transport
makedir root/vehicle 4wheeler
makedir root/vehicle 2wheeler 
makedir root/vehicle/2wheeler hero 
makedir root/transport road
makedir root/transport rail
makedir root/transport air
makedir root/transport/rail platform
makedir root/vehicle/4wheeler benz
listdir root/vehicle 0 file.text

movedir root/transport root/vehicle/2wheeler


mountvfs shayan
makedir root vehicle
makedir root transport
makedir root/vehicle 4wheeler
makedir root/vehicle 2wheeler 
makedir root/vehicle/2wheeler hero 
makedir root/transport road
makedir root/transport rail
makedir root/transport air
makedir root/transport/rail platform
makedir root/vehicle/4wheeler benz
listdir root/transport 1 file.txt
listdir root 1 file1.txt
deletedir root/vehicle
listdir root/vehicle/2wheeler 1 file2.txt
listdir root 1 file3.txt

addfile root/vehicle abc.txt addDemo.txt
listdir root/transport 1 file.txt
listfile root/vehicle/abc.txt list_addDemo.txt
updatefile root/vehicle/abc.txt update_addDemo.txt
listfile root/vehicle/abc.txt list_addDemo2.txt


char **token;	
	char prevFileName[50],currFileName[50];
	int count;
	char *parentP1,*parentP2;
	int n,i,l2;
	struct nAryTree *currPtr;
	struct nAryTree *prevPtr;
	struct nAryTree *temproot;
	char tempP1[100];
	parentP1=(char *)malloc(sizeof(char)*50);
	parentP2=(char *)malloc(sizeof(char)*50);



char **token;
	char destPath[100];
	char prevFileName[50],currFileName[50];
	int count;
	char *parentP1,*parentP2,*destParent;
	int n,i,l2;
	struct nAryTree *currPtr;
	struct nAryTree *prevPtr,*destPtr,*duplicatecurrPtr;
	char tempP1[100];
	parentP1=(char *)malloc(sizeof(char)*50);
	parentP2=(char *)malloc(sizeof(char)*50);
	destParent=(char *)malloc(sizeof(char)*50);
	duplicatecurrPtr=(struct nAryTree *)malloc(sizeof(struct nAryTree));
	strcpy(tempP1,P1);
	count=countSlash(tempP1);
	token=stringtok(tempP1);	
	
	for(i=0;i<=count;i++)	
		printf("\n tokens are %s\n",token[i]);

	n=strlen(P1)-(strlen(token[count])+1);
	l2=strlen(token[count-1])+1;
	//printf("\npath %s\n",P1);
	//printf("lengths %d %d %d",strlen(P1),strlen(token[count])+1,n);
	
	//copying the parent path
		for(i=0;i<n;i++)
			parentP1[i]=P1[i];
	
		strcat(parentP1,"\0");
	strcpy(currFileName,token[count]);
	strcpy(prevFileName,token[count-1]);

	currPtr=curPtrFunc(parentP1,root);
	currPtr=temp2;//fetching the current ptr
	
	while(currPtr->rightSibling!=NULL) //moving to the correct position
	{
		if(strcmp(currPtr->fd_tree->fileName,token[count])==0) 
		break;
		currPtr=currPtr->rightSibling;
	}

	printf("\n currptr name %s\n",currPtr->fd_tree->fileName);
	if(count!=1)
	n=strlen(parentP1)-(strlen(token[count-1])+1);
	else 
	n=strlen(parentP1);
	printf("\npath %s\n",parentP1);
	
	printf("token-1  %s",token[count-1]);
	printf("length of token-1  %d",strlen(token[count-1]));
	printf("lengths %d %d %d",strlen(parentP1),strlen(token[count-1])+1,n);
	printf("\n n=%d\n",n);
	printf("\nl2=%d\n",l2);
/*	for(i=0;i<(n-l2);i++)
	parentP2[i]=parentP1[i];*/
	strncpy(parentP2,parentP1,n);
	strcat(parentP2,"\0");
	printf("\n parent 2%s\n",parentP2);
		
	if(strcmp(parentP2,"root")!=0)
	{	
		prevPtr=curPtrFunc(parentP2,root);
		prevPtr=temp2;
		printf("\n tokens %s\n", prevPtr->fd_tree->fileName);
	
		while(prevPtr->rightSibling!=NULL) {
			if(strcmp(prevPtr->fd_tree->fileName,prevFileName)==0) 
			break;
			prevPtr=prevPtr->rightSibling;
		}
	
	
		if(prevPtr->rightSibling!=NULL)
		if(strcmp(prevPtr->leftChild->fd_tree->fileName,currFileName)!=0)
			{
				prevPtr=prevPtr->leftChild;
				while(strcmp(prevPtr->rightSibling->fd_tree->fileName,token[count])!=0)
					prevPtr=prevPtr->rightSibling;
			}
		
	}

	else
	{
		prevPtr=root;
	if(prevPtr->leftChild!=currPtr)
		{	
			prevPtr=prevPtr->leftChild;
			while(prevPtr->rightSibling!=currPtr)
				prevPtr=prevPtr->rightSibling;
		}
	}
	printf("\n previous ptr %s\n", prevPtr->fd_tree->fileName);

	


//code for substring check
if(strstr(fileName,".txt"))
	printf("\n This is a text file");
else 
printf("\nThis is not a text file");



//commands
addfile root/vehicle abc.txt addDemo.txt
listdir root/transport 1 file.txt
listfile root/vehicle/abc.txt list_addDemo1.txt
updatefile root/vehicle/abc.txt update_addDemo.txt
listfile root/vehicle/abc.txt list_addDemo2.txt
deletedir root/vehicle
exportfile root/vehicle/abc.txt export_addDemo.txt
movefile root/vehicle/abc.txt root/transport
copyfile root/transport/abc.txt root/vehicle
