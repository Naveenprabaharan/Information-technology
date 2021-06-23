#include<stdio.h>
#include<stdlib.h>

int main()
{
int i,j,sum=0,n;
int d[20];
int disk; //loc of head
int temp,max, seek = 0;
int dloc; //loc of disk in array
float avg;

printf("enter number of location\t");
scanf("%d",&n);
printf("enter position of head\t");
scanf("%d",&disk);
printf("enter elements of disk queue\n");
for(i=0;i<n;i++)
{
scanf("%d",&d[i]);
}
d[n]=disk;
n=n+1;
for(i=0;i<n;i++) // sorting disk locations
{
for(j=i;j<n;j++)
{
if(d[i]>d[j])
{
temp=d[i];
d[i]=d[j];
d[j]=temp;
}
}

}
max=d[n-1];
for(i=0;i<n;i++) // to find loc of disc in array
{
if(disk==d[i]) { dloc=i; break; }
}
for(i=dloc;i>=0;i--)
{
printf("%d -->",d[i]);
}
printf("0 -->");
for(i=dloc+1;i<n;i++)
{
printf("%d-->",d[i]);
}
printf("\b\b\b   \n\n");
for(i = 0; i < n ; i++) 
{
	printf("%5d", d[i]);
	if(i+1 != n)		seek += abs(d[i+1] - d[i]);
}
avg = (float)seek/(float)n;
printf("\nTotal Seek Time : %3d\nAverage Seek Time : %3.4f\n\n", seek, avg);

return 0;
}
