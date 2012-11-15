#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"

void makeDirRec(char *P1,char *P2) {
	
	
	struct fileDescriptor *fd1;
	fd1=(struct fileDescriptor *) malloc (sizeof(struct fileDescriptor));
	struct nAryTree *currPtr;
	currPtr=(struct nAryTree *)malloc (sizeof(struct nAryTree));	

	char **token;
	int count,i=1,j;
	char createdPath[100];	

	count=countSlash(P1);
	token=stringtok(P1);
	
	for(j=0;j<=count;j++)
		printf("\nafter tokenising we get %s\n",token[j]);

	strcpy(createdPath,token[0]);

	//curPtr=currPtrReturn(createdPath,token[1]);
	while(i<=count) 
	{
	
		if(i==1) {
			currPtr=currPtrReturn(createdPath,token[i]);
			printf("\ncurrPtr of if::%p",currPtr);
		}
		else 
		{
			
			//for(j=1; j<i; j++) 
			//{
				strcat(createdPath,"/");
				strcat(createdPath,token[i-1]);				
				printf("\ncreatedPath of else::%s",createdPath);
				printf("\ntokeni of else::%s",token[i]);
				currPtr=currPtrReturn(createdPath,token[i]);
				printf("\ncurrPtr of else::%p",currPtr);
			//}

		}
		if(currPtr==NULL)
		{
		//putting the newly created directories into all the data structures
		makeDir(createdPath,token[i]);
		}
	i++;	
	}

	if(count>=1)
	{
	strcat(createdPath,"/");
	strcat(createdPath,token[count]);
	}
	
	printf("\nThis is the actual path\n");
	printf("\n%s\n",createdPath);
	
	makeDir(createdPath,P2);
}
