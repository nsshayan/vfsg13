#include "mainHeader.h"
#include "funcPrototype.h"


/*void main(){
    int a,b;
 
    while(1){
    printf("Enter your choice \n 1: Add file \n 2: Search file \n 3: Delete file\n");
    scanf("%d",&a);
 
    switch(a){
        case 1:
            do{
                printf("Enter the filename or Exit to abort\n");
                scanf("%s", filename);
                if(strcmp(filename,"Exit"))
                {             
                printf("Enter the filepath\n");
                scanf("%s", filepath);
                printf("Enter the fdno.\n");
                scanf("%d",& fdno);
             
                bstroot = insert(bstroot);
                }
                else
                    break; 
            }while(1); 
            break;
        case 2:
            printf("Enter the filepath u want to search\n");
            scanf("%s", filepath);
            b=search(filepath,bstroot);
            break;
        case 3:
            printf("Enter the filepath u want to delete\n");
            scanf("%s", filepath);
            deletebst(bstroot,filepath);
            break;
        default:
            break;
        }
    }
 
}*/


node* add(struct fileDescriptor *fdtemp){
    node *temp;
    char catpath[120];
    strcpy(catpath,fdtemp->fullPathName);
    strcat(catpath,"/");
    strcat(catpath,fdtemp->fileName);

    temp=(node*)malloc(sizeof(node));  
    temp->rightchild=NULL;
    temp->leftchild=NULL;
    strcpy(temp->path,catpath);
    temp->file=fdtemp;

    return temp;


}

node* bstinsert(node* temp,struct fileDescriptor *fd){
    node *temp1;
    char catpath[120];
    strcpy(catpath,fd->fullPathName);
    strcat(catpath,"/");
    strcat(catpath,fd->fileName);
    if(bstroot==NULL){
        bstroot= add(fd);
        return bstroot;
    } 
    else if(bstroot->leftchild == NULL && strcmp(catpath,bstroot->path)<0){
        bstroot->leftchild = add(fd);
        return bstroot;
    }
    else if(bstroot->rightchild==NULL && strcmp(catpath,bstroot->path)>=0){
        bstroot->rightchild = add(fd);
        return bstroot;
    }

    while(temp)
    {
       if(strcmp(catpath,temp->path)>=0)
        {
            temp1=temp;
            temp=temp->rightchild;
            }
         else
        {
            temp1=temp;
            temp=temp->leftchild;
        }
        }
        if(strcmp(catpath,temp1->path)>0){
            temp1->rightchild=add(fd);
        }
        else{
            temp1->leftchild=add(fd);
        }
    return bstroot;
     

    /*if(temp->leftchild == NULL && strcmp(temp->file->fullPathName,fd->fullPathName)<0){
        temp->leftchild = add(fd);
        return bstroot;
    }     
    else if(strcmp(temp->file->fullPathName,fd->fullPathName)<0){
        temp=temp->leftchild;
        bstroot=bstinsert(temp,fd);
        return bstroot;
    }


    if(temp->rightchild==NULL && strcmp(temp->file->fullPathName,fd->fullPathName)>0){
        temp->rightchild = add(fd);
        return bstroot;
    }
    else if(strcmp(temp->file->fullPathName,fd->fullPathName)>0){
        temp=temp->rightchild;
        bstroot=bstinsert(temp,fd);
        return bstroot;
    }*/
     
}

int searchbst(char filename[],char filepath[],node *temp,char outfile[]){
    FILE *fp;
    fp=fopen(outfile,"a+");
    char catpath[120];
    strcpy(catpath,filepath);
    strcat(catpath,"/");
    strcat(catpath,filename);  
    if(strcmp(catpath,temp->path)<0){
        if(temp->leftchild != NULL){     
            temp=temp->leftchild;
            searchbst(filename,filepath,temp,outfile);
        }
    }
    else if(!(strcmp(catpath,temp->path))){
    printf("%s\n%s\n%c\n%d\n",temp->file->fileName,temp->file->fullPathName,temp->file->fileType,temp->file->fileSize);
    fprintf(fp,"%s",temp->file->fileName);
    fprintf(fp,"%c",'\n');	
    return 0;
    }
    else if(strcmp(catpath,temp->path)>=0){
        if(temp->rightchild != NULL){     
            temp=temp->rightchild;
            searchbst(filename,filepath,temp,outfile);
        }
    }

    else{
        printf("Filepath doesnot exist\n");
        return 0;
    }
fclose(fp);
return 1;
}

void deletebst(char filename[],node *temp,char filepath[]){
    char catpath[120];
    strcpy(catpath,filepath);
    strcat(catpath,"/");
    strcat(catpath,filename);  
    node *temp1=NULL,*temp2=NULL,*temp3=NULL,*temp4=NULL;
    while(temp)
    {
        if(strcmp(catpath,temp->path)==0)
        {
            break;
        }
        else if(strcmp(catpath,temp->path)>0)
        {
            temp2=temp1;
            temp1=temp;
            temp=temp->rightchild;
            }
        else
        {
            temp2=temp1;
            temp1=temp;
            temp=temp->leftchild;
        }
        }
    if(temp1->leftchild == NULL && temp1->rightchild == NULL){
        if(temp1 == temp2->rightchild)
            {temp2->rightchild=NULL;}
        else
            {temp2->leftchild=NULL;}
    }
    else if(temp1->leftchild != NULL && temp1->rightchild == NULL){
        if(temp1 == temp2->rightchild)
            {temp2->rightchild=temp1->leftchild;}
        else
            {temp2->leftchild=temp1->leftchild;}
        //temp2->rightchild=temp1->leftchild;
    }
    else if(temp1->leftchild == NULL && temp1->rightchild != NULL){
        if(temp1 == temp2->rightchild)
            {temp2->rightchild=temp1->rightchild;}
        else
            {temp2->leftchild=temp1->rightchild;}
        //temp2->rightchild=temp1->rightchild;
    }
    else{
        if(temp1->rightchild->leftchild == NULL){
            temp1->rightchild->leftchild = temp1->leftchild;
            if(temp1 == temp2->rightchild)
                {temp1=temp1->rightchild;temp2->rightchild=temp1;}
            else
                {temp1=temp1->rightchild;temp2->leftchild=temp1;}
        }
        else{
            if(temp1 == temp2->rightchild)
            {
                temp3=temp1->rightchild;
                while(temp3->leftchild != NULL){
                    temp4= temp3;        //temp3= succesor, temp4=parent succesor
                    temp3=temp3->leftchild;
                }
                if(temp3->rightchild != NULL){
                    temp4->leftchild = temp3->rightchild;
                }
                else{
                    temp4->leftchild = NULL;
                }
                temp2->rightchild = temp3;
                temp3->rightchild = temp1->rightchild;
                temp3->leftchild = temp1->leftchild;
            }
            else
            {
                temp3=temp1->rightchild;
                while(temp3->leftchild != NULL){
                    temp4= temp3;        //temp3= succesor, temp4=parent succesor
                    temp3=temp3->leftchild;
                }
                if(temp3->rightchild != NULL){
                    temp4->leftchild = temp3->rightchild;
                }
                else{
                    temp4->leftchild = NULL;
                }
                temp2->leftchild = temp3;
                temp3->rightchild = temp1->rightchild;
                temp3->leftchild = temp1->leftchild;
            }
        }
    }
    printf("\nFile is deleted\n");
}

void display(node *temp){ 
 
    if(temp != NULL){     
        //printf("\n%s\n%s\n%d\n",temp->file->fullPathName,temp->file->fileName,temp->file->fileSize);
        printf("\nfile Name=%s",temp->file->fileName);
        printf("\nleft child of %s",temp->file->fileName);
        display(temp->leftchild); 
        printf("\n right child of %s",temp->file->fileName);         
        display(temp->rightchild);
    }
} 
