#include<stdio.h>
#include<stdlib.h>


void search(int val);
void hashing(int val);

typedef struct node{
	int num;
	struct node *next;
}list; 


list* add(int val, list *start);

int val;
list *a[7]={};



int main(){
	int a;
	while(1){
	printf("Enter your choice \n 1: Add element \n 2: Search \n");
	scanf("%d",&a);
	
	switch(a){
		case 1:
			do{
				printf("Enter the value u want to add or -1 to abort\n");
				scanf("%d",&val);
				if(val!= -1)
				{
					hashing(val);
				}
				else
					break;	
			}while(1);	
			break;
		case 2:
			printf("Enter the value u want to search\n");
			scanf("%d",&val);
			search(val);
			break;
		default:
			break;
		}
	}
	return 0;

}

list* add(int val, list *start){
	list *temp,*llist;
	llist= start;

	temp=(list*)malloc(sizeof(list));     
	temp->num=val;
	temp->next=NULL;

	if(llist==NULL){
		start=temp;
	}
	else{
		while(llist->next != NULL){
				llist=llist->next;	
		}
		llist->next=temp;
		
	}
	return start;
}



void hashing(int val){
	int hash,b;
	b=val;
	hash=(b%7);
	if(hash==0){
		a[0]=add(val,a[0]);
	}
	else if(hash==1){
		a[1]=add(val,a[1]);
	}
	else if(hash==2){
		a[2]=add(val,a[2]);
	}
	else if(hash==3){
		a[3]=add(val,a[3]);
	}
	else if(hash==4){
		a[4]=add(val,a[4]);
	}
	else if(hash==5){
		a[5]=add(val,a[5]);
	}
	else{
		a[6]=add(val,a[6]);
	}
	

}

void search(int val){
	list *search;
	int rem,i=1,b;
	b=val;
	rem=(b%7);
	if(rem==0){
		search=a[0];
		while(search !=NULL){
			if(val==search->num){
			printf("Element Found at index 0, %d loc of list\n",i);
			break;}
			search=search->next;
			i++;
		}
	}
	else if(rem==1){
		search=a[1];
		while(search !=NULL){
			if(val==search->num){
			printf("Element Found at index 1, %d loc of list\n",i);
			break;}
			search=search->next;
			i++;
		}

	}
	else if(rem==2){
		search=a[2];
		while(search !=NULL){
			if(val==search->num){
			printf("Element Found at index 2, %d loc of list\n",i);
			break;}
			search=search->next;
			i++;
		}

	}
	else if(rem==3){
		search=a[3];
		while(search !=NULL){
			if(val==search->num){
			printf("Element Found at index 3, %d loc of list\n",i);
			break;}
			search=search->next;
			i++;
		}

	}
	else if(rem==4){
		search=a[4];
		while(search !=NULL){
			if(val==search->num){
			printf("Element Found at index 4, %d loc of list\n",i);
			break;}
			search=search->next;
			i++;
		}

	}
	else if(rem==5){
		search=a[5];
		while(search !=NULL){
			if(val==search->num){
			printf("Element Found at index 5, %d loc of list\n",i);
			break;}
			search=search->next;
			i++;
		}

	}
	else{
		search=a[6];
		while(search !=NULL){
			if(val==search->num){
			printf("Element Found at index 6, %d loc of list\n",i);
			break;}
			search=search->next;
			i++;
		}
	}
	
	
	
}

