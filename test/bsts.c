#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree
{
char str[50];
struct tree *right;
struct tree *left;
}*root;
typedef struct tree *node;

char string[50];
node insert(char[],node);
node delete(char[],node);
void makempty();
node findmin(node);
node find(char[], node);
void display(node);

void main()
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
}

node insert(char x[],node info)
{
	if(info==NULL)
	{
		info = (node)malloc(sizeof(node));
		strcpy(info->str,x);
		info->left = info->right = NULL;
	}
	else
	{
	if(strcmp(x,info->str)<0)
		info->left = insert(x, info->left);
	else if(strcmp(x ,info->str)>0)
		info->right = insert(x, info->right);
	}
	return info;
}

node delete(char x[],node info)
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
	if(info==NULL) 
		return NULL;
	if(strcmp(x,info->str)<0) 
		return find(x,info->left);
	if(strcmp(x,info->str)>0) 
		return find(x,info->right);
	return info;
}
void display(node info)
{
	
	
	if(info!=NULL)
	{
           display(info->left);
	   printf("  %s  ",info->str);
           display(info->right);
        } 
}

