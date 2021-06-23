#include<stdio.h>
#include<stdlib.h>
struct free{
    int start;
    int length;
};
struct allocate{
    int start;
    int length;
    int pno;
};
int mem[32][8];
struct free f[20];
struct allocate a[20];
int n = -1,k = 0;
void ordering(){
	for(int i=0;i<k;i++){
    	if(f[i].start+f[i].length == f[i+1].start){
        	f[i].length += f[i+1].length;
        	int j = i+1;
        	while(j<k){
            	f[j] = f[j+1];
            	j++;
        	}
        	k--;
    	}
	}
}
void sort(){
	struct free temp;
	for(int i=0;i<=k;i++){
    	for(int j=0;j<k;j++){
        	if(f[j].start>f[j+1].start){
            	temp = f[j];
            	f[j] = f[j+1];
            	f[j+1] = temp;
        	}
    	}
	}
}
int main(){
	int b=0,ch,p,y,flag =0;
    f[0].start = 0;
    f[0].length = 32;
    printf("The Total Memory Available is 32.");
	while(1){
    	printf("\n1 for Allocate, 2 for Deallocate,\n3 for Displaying in Free List and Allocate List,\n4 for print the Process Elements, 5 for Exit\nEnter Your Choice:");
    	scanf("%d",&ch);
    	switch(ch){
    	case 1:
        	n++;
        	printf("Enter Process number:");
        	scanf("%d",&a[n].pno);
        	printf("Enter Length:");
        	scanf("%d",&a[n].length);
   		 a[n].length++;
        	for(int i=0;i<=k;i++){
            	if(f[i].length>a[n].length){
                	a[n].start = f[i].start;
                	f[i].start += a[n].length;
                	f[i].length -= a[n].length;
                	b++;
                	printf("Process Allocated.");
                	break;
            	}
        	}
   		 for(int i=1;i<=8;i++){
   			 if(i<a[n].length)
   				 mem[a[n].start][i-1] = a[n].start+i;
   			 else
   				 mem[a[n].start][i-1] = -1;
   		 }
        	if(b==0){
            	printf("Can't be Allocated.Insufficient continuous Memory.");
        	}
        	b=0;
        	break;
    	case 2:
        	printf("Enter the process number:");
        	scanf("%d",&p);
        	int i;
        	for(i=0;i<=n;i++){
            	if(a[i].pno == p){
                	k++;
                	f[k].start = a[i].start;
                	f[k].length = a[i].length;
                	b++;
                	sort();
                	ordering();
                	break;
            	}
        	}
   		 for(int j=0;j<8;j++)
   			 mem[a[i].start][j] = 0;
        	if(b==0){
            	printf("Process not found.");
            	n++;
        	}
        	b=0;
        	while(i<=n){
            	a[i] = a[i+1];
            	i++;
        	}
        	n--;
        	break;
    	case 3:
        	printf("The Allocated List:\n");
        	for(int i=0;i<=n;i++){
            	printf("%d\t%d\t%d\n",a[i].pno,a[i].start,a[i].length-1);
        	}
        	printf("The Free List:\n");
        	for(int i=0;i<=k;i++){
            	printf("%d\t%d\n",f[i].start,f[i].length);
        	}
        	break;
    	case 4:
   		 printf("Enter the Process Number:");
   		 scanf("%d",&y);
   		 for(int i=0;i<=n;i++){
   			 if(a[i].pno == y){
   				 for(int j=0;j<8;j++)
   					 printf("%d ",mem[a[i].start][j]);
   					 flag++;
   			 }
   		 }
   		 if(flag == 0)
   			 printf("Process not Found.");
   		 flag = 0;
   		 break;
   	 case 5:
        	goto end;
    	default:
        	printf("Invalid Input.Re-Enter Your Choice....");
        	break;
    	}
	}
	end:
	return 0;
}
