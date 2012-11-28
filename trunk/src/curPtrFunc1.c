#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"

struct nAryTree *curPtrFunc1(char P1[],struct nAryTree *temp) {

	char tempP1[100],tempP2[100],orgP1[100];
	struct nAryTree *curPtr;
	curPtr=(struct nAryTree *)malloc(sizeof(struct nAryTree));

	char **token;
	int count,n;	

	strcpy(orgP1,P1);
	count=countSlash(P1);
	token=stringtok(P1);

	if (count>0) {
		n=strlen(orgP1)-(strlen(token[count])+1);
		strcpy(tempP2,token[count]);
		strncpy(tempP1,orgP1,n);	
		curPtr=currPtrReturn(tempP1,tempP2);
		printf("in if");	
	}
	else {
		printf("in else");	
		curPtr=root;	
	}

	

return curPtr;

}
