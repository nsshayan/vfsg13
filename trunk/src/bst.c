#include "../include/bst.h"

struct tree {
	int block_no;
	struct tree *left;
	struct tree *right;
};

struct tree * create() {
	struct tree *p, *root;
	int x,flag,y,z;
	
	root=(struct tree *) malloc(sizeof(struct tree));
	printf("Enter the block_no to be put in root node\t");	
	scanf("%d",&z);
	root->block_no=z;
	root->left=NULL;
	root->right=NULL;
	
	printf("\n");
	printf("Enter -1 if you want to terminate else press any key\t");
	scanf("%d",&y);
	
	while(y!=-1) {
		flag=1; 
		p=root;
		printf("\n");
		printf("Enter the block_no to be put in next node\t");		
		scanf("%d",&x);
		
		while(flag) {
			if(x<p->block_no) {	
				if(p->left==NULL) {				
					p->left=(struct tree *)malloc(sizeof(struct tree));
					p=p->left;
					p->block_no=x;
					p->left=NULL;
					p->right=NULL;
					flag=0;
				}
				else
					p=p->left;
			}
			else {
				if(p->right==NULL) {				
					p->right=(struct tree *)malloc(sizeof(struct tree));
					p=p->right;
					p->block_no=x;
					p->left=NULL;
					p->right=NULL;
					flag=0;
				}
				else
					p=p->right;
			}
		}
		printf("\nEnter -1 if you want to terminate else press any key\t");
		scanf("%d",&y);
	}
	return root;
}

struct tree * insert(struct tree *root, int nblock_no) {
	struct tree *p,*q;
	q=NULL;
	p=root;
	while(p!=NULL) {
		q=p;		
		if(nblock_no>p->block_no) {
			//p->right=(struct tree *)malloc(sizeof(struct tree));
			p=p->right;
		}
		else {
			//p->left=(struct tree *)malloc(sizeof(struct tree));		
			p=p->left;
		}
	}
	q=p;
	q=(struct tree *)malloc(sizeof(struct tree));		
	q->block_no=nblock_no;
	q->left=NULL;
	q->right=NULL;

return root;
}

struct tree * delete(struct tree *root, int a) {
	return root;
}

int main() {

	struct tree *root;
	int m,a,flag=1;

	while(flag) {
		printf("\n--Enter 1 to create a BST--");		
		printf("\n--Enter 2 to inser a node in BST--");	
		printf("\n--Enter 3 to delete a node from BST--");	
		printf("\n--Enter 4 to exit--");	

		printf("\n\nEnter the choice\t");
		scanf("%d",&m);

		switch(m) {
			case 1: root=create();
				printf("\n%d\n",root->block_no);
				break;

			case 2: printf("\n\nEnter the block_no to be inserted\t");
				scanf("%d",&a);
				root=insert(root, a);
				printf("\n%d\n",root->block_no);
				printf("\n%d\n",root->right->block_no);
				break;

			case 3: printf("\n\nEnter the block_no to be deleted\t");
				scanf("%d",&a);
				root=delete(root, a);
				break;

			case 4: flag=0;
				break;

			default: printf("\n\nYou have entered a wrong choice");
		}
	}
		
}
