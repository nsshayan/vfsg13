struct mainHeader{
	char fileLabel[20]; //label to the file system
	int maxFileDescriptor; // maximum number of available file descriptors
	int noUsedDescriptor; // number of used file descriptors
	struct fileDescriptor *fDescriptor;  //fDescriptor is a pointer to structure of type fileDescriptor
	struct freeList *fList; //fList is a pointer to structure of type freeList
};

struct fileDescriptor{
	char fileName[50]; //name of the file
	char fullPathName[100]; //full path of the file
	char fileType; // stores the type of the file
	int fileSize; //stores the size of the file
	int blockLoc; //Location of the block
};

struct freeList{
	int blockNo; //index of the block
	struct freeList *nextblock; // points to the next free block in the freeList
};

struct block{
	int bufferSize; //stores the size of the buffer
};
