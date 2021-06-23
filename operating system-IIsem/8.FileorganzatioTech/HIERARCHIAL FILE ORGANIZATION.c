#include<stdio.h>
#include<stdlib.h>
struct node
{
char N[25];
int df;
struct node *pc;
struct node *ps;
};
struct node *A[20];
int in=0,c=0;
void create(struct node *P, int N,int n)
{  int i;
struct node *Tmp, *T;
Tmp=P;
for(i=0;i<N;i++)
{
T=malloc(sizeof(struct node));
if(n!=1)
{
printf("Enter dir(1) or file(0):");
scanf("%d",&T->df);
printf("Enter name:");
scanf("%s",&T->N);
}
else
{
printf("Enter root directory name:");
scanf("%s",&T->N);
T->df=1;
}
if(T->df==1)
{
A[c]=T;
c++;
}

T->pc=NULL;
T->ps=NULL;

if(i==0)
{
Tmp->pc=T;
Tmp=T;
}
else
{
Tmp->ps=T;
Tmp=T;
}
}
}
void display(struct node *P)
{
int i;
P=P->pc;
int m=0;
do
{
printf("%s(%d)",P->N,P->df);
if(P->df==1 && P->pc!=NULL)
display(P);
P=P->ps;
printf("\n");
}while(P!=NULL);
}
main()
{
int nu,nc,n=1;
int i,j,k;
 struct node *Hdr;
Hdr=malloc(sizeof(struct node));
Hdr->df=1;
Hdr->pc=NULL;
Hdr->ps=NULL;
nu=1;
create(Hdr,nu,n);
n++;
for(in=0;in<c;in++)
{
printf("ENTER NUMBER OF CHILD NODES for %s:",A[in]->N);
scanf("%d",&nc);
create(A[in],nc,n);
}
printf("\n HIERARCHIAL\n");
display(Hdr);
}
