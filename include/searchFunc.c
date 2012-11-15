#include "mainHeader.h"
#include "funcPrototype.h"


int searchbst(char filename[], node *temp){
    
    printf("\n This inside searchbst function\n");
    if(temp != NULL){
        searchbst(filename,temp->leftchild);
        if(strstr(temp->file->fileName,filename)){
            printf("\nsearch func in  bst %s\n%s\n%c\n",temp->file->fileName,temp->file->fullPathName,temp->file->fileType);            
		return 0;
        }
        searchbst(filename,temp->rightchild);
}
    
}

