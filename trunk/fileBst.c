#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mainheader.h>
struct tree
{
//char str[50];
struct fileDescriptor *fd_bst;
struct tree *right;
struct tree *left;
};
//typedef struct tree *node;

char string[50];
node insert(char[],node);
node delete(char[],node);
void makempty();
node findmin(node);
node find(char[], node);
void display(node);

/*void main()
{
	 int ch;
	node temp;
	makempty();
	while(1)
	{ 
		printf("\n1. Insert\n2. Delete\n3. Find\n4. Display\n5. Exit\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch) {
				case 1: 
			
					printf("Enter an String : ");
					scanf("%s", string);
					root = insert(string,root); 
                                        strcpy(string," ");
				break;
				case 2: 
				
					printf("\nEnter the string to delete : ");
					scanf("%s",string);
					root = delete(string, root); 
					 strcpy(string," ");
				break;
				case 3: 
					printf("\nEnter the string to search : ");
					scanf("%s",string);
					temp = find(string, root);
					if (temp != NULL) 
						printf("Element found");
					else 
						printf("Element not found");
					 strcpy(string," "); 
				break;
				case 4:
					if(root==NULL) 
						printf("\nEmpty tree");
					else
						display(root); 
				break;
				case 5:
					exit(0);
				default: 
					printf("Invalid Choice");
				}
	}
}*/

struct tree *insertroot(struct fileDescriptor *fd )
{

	struct tree *nodeinsertptr;
	struct tree *bstrootptr;	

	

		nodeinsertptr = (struct tree *)malloc(sizeof(struct tree));
		nodeinsertptr->fd_bst=fd;
		nodeinsertptr->left=NULL;
		nodeinsertptr->right=NULL;
			
		bstrootptr=nodeinsertptr;	
		
		return bstrootptr;

		//strcpy(info->str,x);
		//info->left = info->right = NULL;
	
	}

	struct tree *insertchild(struct tree *fdroot,struct fileDescriptor *fd){

	struct fileDescriptor *fd_temp=fd;
	struct tree *current_node=fdroot;
	//struct tree *current_node1=fdroot->right;	
	//nodeinsertptr = (struct tree *)malloc(sizeof(struct tree));

	//nodeinsertptr->fd_bst=fdroot;

	//nodeinsertptr->fd->filename = "Ghi";
	

	
	if(current_node->left == NULL && strcmp(fdroot->fd_bst->filename,fd_temp->filename)<0)
		{
		nodeinsertptr = (struct tree *)malloc(sizeof(struct tree));
		current_node->left = nodeinsertptr;
		}		
	else if	(strcmp(fdroot->fd_bst->filename,fd_temp->filename)<0)
		nodeinsertptr->left = insertchild(nodeinsertptr->fd_bst, nodeinsertptr->left);
	else if(current_node->right==NULL && strcmp(fdroot->fd_bst->filename,fd_temp->filename)>0)
		{
		nodeinsertptr = (struct tree *)malloc(sizeof(struct tree));
		current_node->right = nodeinsertptr ; 
		}
	else if	(strcmp(fdroot->fd_bst->filename,fd_temp->filename)>0)
		nodeinsertptr->right = insertchild(nodeinsertptr->fd_bst, nodeinsertptr->right);
	
		
	}
	display(fdroot);
	return fdroot;
}

/*node delete(char x[],node info)
{
	node temp;
	if(info == NULL) 
		printf("\nElement not found");
	else
	{
	if(strcmp(x,info->str)<0)
		info->left = delete(x, info->left);
	else if(strcmp(x,info->str)>0)
		info->right = delete(x, info->right);
	else
	{
		if(info->left && info->right)
		{
			temp = findmin(info->right);
			strcpy(info->str,temp->str);
			info->right = delete(info->str,info->right);
		}
		else if(info->left == NULL)
			info=info->right;
		else
			info=info->left;
	}
	}
	return info;
}

node findmin(node temp)
{
	if(temp == NULL || temp->left == NULL)
		return temp;
        else
	      return findmin(temp->left);
}

void makempty()
{
 root=NULL;
}

node find(char x[], node info)
{
	char *fullpath[100];
	char stringresult;
	int j;	
	
	static int i = 0;
	if(i==0)
	{
	strcpy(fullpath[i],info->str);
	i++;
	}
	if(info==NULL) 
		return NULL;
	if(strcmp(x,info->str)<0)
		{
		strcpy(fullpath[i],(info->left)->str);
		i++;
		return find(x,info->left);
		}
	if(strcmp(x,info->str)>0) 
		{
		fullpath[i] = (info->right)->str);
		i++;
		return find(x,info->right);
		}
	fullpath[i] =info->str;
	//stringresult = fullpath[i].Join("/",fullpath[i]);
	//printf("%s",stringresult);
	
	while(fullpath[j]!='\0')
	{
	printf("%s",fullpath[j]);
	printf("/");
	j++;
	
	}
	return info;
}*/
void display(struct tree *info)
{	
	
	
	
	if(info!=NULL)
	{
           display(info->left);
	   printf("  %s  ",info->str);
           display(info->right);
        } 
}

