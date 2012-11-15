#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct fileDescriptor{
	char fileName[50]; //name of the file
	char fullPathName[100]; //full path of the file
	char fileType; // stores the type of the file
	int fileSize; //stores the size of the file
	int blockNo; //Location of the block
};

struct mainHeader{
	char fileLabel[30]; //label to the file system
	int maxFileDescriptor; // maximum number of available file descriptors
	int noUsedDescriptor; // number of used file descriptors
	struct fileDescriptor fDescriptor[1024];  //fDescriptor is a pointer to structure of type fileDescriptor
	int freeList[1024]; //fList is a pointer to structure of type freeList
};


/*struct freeList{
	int blockNo; //index of the block
	struct freeList *nextblock; // points to the next free block in the freeList
};

struct block{
	int bufferSize; //stores the size of the buffer
}; */

struct nAryTree {
	struct fileDescriptor *fd_tree;
	struct nAryTree *leftChild;
	struct nAryTree *rightSibling;
};

//strcuture for bstnode
typedef struct node{
	struct fileDescriptor *file;
	struct node *leftchild;
	struct node *rightchild;
}node; 


//structure for hash table
typedef struct hashnode{
	struct fileDescriptor  *file;
	struct hashnode *next;
}list;
typedef struct llistnode
{	char paths[100];
	struct node *next;
}llist;


struct mainHeader metaHeader;
struct nAryTree *root,*temp2;
node *bstroot;
list *hashnode;
int errorCheck;

