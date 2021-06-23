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
int memory[32];
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
    int b=0,ch,p;
	f[0].start = 0;
	f[0].length = 32;
	for(int i=0;i<32;i++){
        memory[i] = -1;
	}
	printf("The Total Memory Available is 32.");
    while(1){
        printf("\n1 for Allocate, 2 for Deallocate,\n3 for Displaying in Free List and Allocate List, 4 for Exit\nEnter Your Choice:");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            n++;
            printf("Enter Process number:");
            scanf("%d",&a[n].pno);
            printf("Enter Length:");
            scanf("%d",&a[n].length);
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
            for(int i=a[n].start;i<a[n].length+a[n].start;i++){
                memory[i]=a[n].pno;
            }
            if(b==0){
                printf("Can't be Allocated.Insufficient contiguous Memory.");
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
                    for(int y=a[i].start;y<a[i].start+a[i].length;y++)
                        memory[y] = -1;
                    f[k].start = a[i].start;
                    f[k].length = a[i].length;
                    b++;
                    sort();
                    ordering();
                    break;
                }
            }
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
                printf("%d\t%d\t%d\n",a[i].pno,a[i].start,a[i].length);
            }
            printf("The Free List:\n");
            for(int i=0;i<=k;i++){
                printf("%d\t%d\n",f[i].start,f[i].length);
            }
            break;
        case 4:
            goto end;
        default:
            printf("Invalid Input.Re-Enter Your Choice....");
            break;
        }
    }
    end:
    return 0;
}
