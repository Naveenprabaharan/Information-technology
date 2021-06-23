#include<stdio.h>
#include<stdlib.h>
int arr[32];
struct node{
  int blocks[50];
  int data;
  struct node*next;
};

struct node*head[30];
int count=1;

void init()
{
   for (int i=0;i<30;i++)
   	head[i]=NULL;
}


void allocate_process()
{
   int value,length,data;
   printf("\nEnter the process number:");
   scanf("%d",&value);
   printf("\nEnter the length:");
   scanf("%d",&length);
   for(int i=1;i<=length;i++){
   for(int j=1;j<=32;j++)
   {
   	if(arr[j]==0){
   	arr[j] = 1;
   	count = j;
   	break;
   	}
   }
   struct node*newNode=malloc(sizeof(struct node));
   newNode->data=count;
   newNode->next=NULL;

   if(head[value]==NULL)
   	head[value]=newNode;
   else
   {
 	struct node*temp=head[value];
 	while(temp->next)
 	{
   	temp=temp->next;
 	}
 	temp->next=newNode;
   }
  }
   
}

void print()
{
  for(int i=1;i<=30  ;i++)
  {
	if(head[i]!=NULL){
	struct node*temp=head[i];
	printf("process[%d]--->",i);
	while(temp)
	{
  	printf("%d--->",temp->data);
  	temp=temp->next;
	}
	printf("NULL\n");
  }
 }
}

void deallocate_process()
{
	int n;
	printf("Enter the process number\n");
	scanf("%d",&n);
	struct node* temp=head[n];
	head[n]=NULL;
	while(temp)
	{
    	arr[temp->data] = 0;
    	temp = temp->next;
	}
}

void print_free()
{
   for(int i=1;i<=32;i++)
   {
  	if(arr[i]==0)
     	printf("\t\t%d",i);
  	if(i%5==0)
     	printf("\n");
   }
}

int main()
{
   int choice,exit=0;
   for(int i=0;i<50;i++)
	arr[i]=0;
   init();
   do{
 	printf("\n1.Allocate the process \n2.Deallocate the process \n3.print the process \n4.print the free space \nEnter choice:");
 	scanf("%d",&choice);
 	switch(choice)
 	{
   	case 1:
       	allocate_process();break;
   	case 2:
       	deallocate_process();break;
   	case 3:
       	print();break;
   	case 4:
       	print_free();break;
   	default:
      	printf("\nEnter the correct choice");
 	}
 	printf("\nDo u want to continue (1/0):");
 	scanf("%d",&exit);
   }while(exit!=0);

	return 0;
}
