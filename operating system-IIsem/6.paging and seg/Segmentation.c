#include<stdio.h>
#include<stdlib.h>
#include <string.h>
void search(int ,int,int );
void allocate();
void reallocate();
void free_fr();
void seg_table();
int check(int);
struct info
{
  int p;
  int seg;
  int base;
  int limit;
  int end;
  char content;
}a[50];
 
int al;
int m=0;
int arr[50];
 
int main()
{
  printf("-----------Segmentation-------------\n");
  free_fr();
  while(1)
  {
  printf("Enter your choice\n1.Allocate\n2.Reallocate\n3.Searching\n4.Free Frames\n5.Exit\n");
  int c;
  scanf("%d",&c);
  switch(c)
  {
	int a,b,o;
	case 1:
  	allocate();
  	seg_table();
  	break;
	case 2:
  	reallocate();
  	seg_table();
  	break;
	case 3:
  	printf("Enter the Process : ");
  	scanf("%d",&a);
  	printf("Enter the segment Number : ");
  	scanf("%d",&b);
  	printf("Enter the offset value : ");
  	scanf("%d",&o);
  	search(a,b,o);
  	break;
	case 4:
  	free_fr();
  	break;
	case 5:
	exit(0);
  }
  }
}
void free_fr()
{
  printf("\n\n\t\t\t\tFREE FRAMES\n");
  for(int i=0;i<50;i++)
  {
	if(arr[i] == 0)
	{
  	printf("%d\n",i);
	}
  }
  printf("\n\n");
}
void allocate()
{
  int ns,ls;
  int pn;
  abc:
  printf("Enter the name of the process :: ");
  scanf("%d",&pn);
  for(int i=0;i<50;i++)
  {
	if(a[i].p == pn)
	{
  	printf("Process already exists\n Enter another process name\n");
  	goto abc;
	}
  }
  printf("Enter the number of Segments in process %d :: ",pn);
  scanf("%d",&ns);
  for(int i = 1; i<=ns ; i++)
  {
	printf("Enter the length of segment %d :: ",i);
	scanf("%d",&ls);
	m = check(ls);
 
	if(m == -1)
	{
  	printf("Segment %d is not allocate because the memory space not sufficient for this segment or the memory is full",i);
	}
	else
	{
  	printf("Enter your content\n");
	for(int j=0;j<ls;j++)
	{
  	scanf("%d",&al);
  	a[m+j].content=al;
	}
 
	a[m].p=pn;
	a[m].seg=i;
	a[m].base=m;
	a[m].limit=ls;
	a[m].end=(m+ls)-1;
	
	for(int k=m;k<m+ls;k++)
	{
  	arr[k] =1;
	}
  }
  }
}
int check(int c)
{
  int l=0,i=0;
  int key = i;
  for( i=0;i<50;i++)
  {
	if(arr[i] == 1)
	{
  	key=i;
  	l=0;
  	key = key+1;
  	continue;
	}
	l++;
	if(l == c)
	{
  	break;
	}
	if(i == 49 )
	{
  	key = -1;
	}
  }
  return key;
}
void seg_table()
{
  printf("\n\n\t\t\t\tSEGMENTATION TABLE\n");
  printf("Process | Segment | Base Address | Limit | End Address\n");
  for(int i=0; i<50; i++)
  {
	if(a[i].end == 0 )
	{
  	if(a[i].limit==1){
    	printf("   %d	|    %d	|  	%d       |	%d  |      %d	\n",a[i].p,a[i].seg,a[i].base,a[i].limit,a[i].end);
  	}
  	continue;
	}
	else
	{
 	printf("   %d    |	%d	|      %d       |	%d  |      %d	\n",a[i].p,a[i].seg,a[i].base,a[i].limit,a[i].end);
	}
  }
  printf("\n\n");
}
void reallocate()
{
  int j =0;
  for(int i=0;i<50;i++)
  {
	if(arr[i]==1)
	{
  	j++;
	}
  }
 
  if(j==0)
  {
	printf("Reallocation is not possible because Segments not allocate\n");
  }
  else
  {
  printf("Enter your choice\n");
  printf("1.Remove all process\n2.Remove any particular process\n3.Remove any segmentation\n");
  int c,pn,ls,k,s;
  scanf("%d",&c);
  switch(c)
  {
	case 1:
  	for(int i=0;i<50; i++)
  	{
    	a[i].p=0;
    	a[i].limit=0;
    	a[i].seg=0;
    	a[i].base = 0;
    	a[i].end =0;
    	a[i].content =' ';
    	arr[i]=0;
  
  	}
  	break;
	case 2:
  	printf("Enter the process name :: \n");
  	scanf("%d",&pn);
  	for(int i=0; i<50;i++ )
  	{
    	if(a[i].p == pn)
    	{
      	k = a[i].base;
      	ls = a[i].limit;
      	for(int i=k; i<k+ls;i++)
      	{
        	arr[i]=0;
  	      a[i].content=' ';
      	}
      	a[i].p=0;
      	a[i].seg=0;
      	a[i].base=0;
      	a[i].limit=0;
      	a[i].end=0;
      	
    	}
  	}
  	break;
	case 3:
  	printf("Enter the process :: ");
  	scanf("%d",&pn);
  	printf("Enter the Segmentation no. :: ");
  	scanf("%d",&s);
  	for(int i =0; i<50; i++)
  	{
    	if(a[i].p == pn &&  a[i].seg == s)
    	{
      	k = a[i].base;
      	ls = a[i].limit;
      	for(int i=k; i<k+ls;i++)
      	{
        	arr[i]=0;
        	a[i].content=' ';
      	}
      	a[i].p=0;
      	a[i].seg=0;
      	a[i].base=0;
      	a[i].limit=0;
      	a[i].end=0;
      	
      	break;
    	}
    	
  	}
  }
}
}
void search(int p,int b,int c)
{
  int ls,ba,flag=0;
  for(int i=0;i<50;i++)
  {
	if(p==a[i].p && b==a[i].seg)
	{
  	ls=a[i].limit;
  	ba=a[i].base;
  	flag += 1;
      	if(c>=ls)
      	{
        	printf("Addressing Error \n");  
	        break;
      	}
      	else
      	{
        	printf("The content is %d\n",a[ba+c].content);
        	break;
      	}
    	
	}
   	
  }
  if(flag ==0)
  {
	printf("Process or Segment Does not exist!!!\n");
  }
}
