#include "mainHeader.h"
#include "funcPrototype.h"
#include "funcPrototype2.h"

struct nAryTree *curPtrFunc1(char P1[],struct nAryTree *temp) {

	char tempP1[100],tempP2[100];
	struct nAryTree *curPtr;
	curPtr=(struct nAryTree *)malloc(sizeof(struct nAryTree));

	char **token;
	int count,n;	

	count=countSlash(P1);
	token=stringtok(P1);

	if (count>0) {
		n=strlen(P1)-(strlen(token[count])+1);
		strcpy(tempP2,token[count]);
		strncpy(tempP1,P1,n);	
		curPtr=currPtrReturn(tempP1,tempP2);	
	}
	else {
		curPtr=root;	
	}

	

return curPtr;

}
