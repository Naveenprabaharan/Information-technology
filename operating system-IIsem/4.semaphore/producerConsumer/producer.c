#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#define buffer 4


void sem_val(int n)
{
FILE *fptr=fopen("sem_val.txt","w");
fprintf(fptr,"%d",n);
fclose(fptr);
}

int get_sem_val()
{
int semaphore;
FILE *fptr=fopen("sem_val.txt","r");
fscanf(fptr,"%d",&semaphore);
fclose(fptr);
return semaphore;
}


int main()
{
int semaphore,c;
sem_val(0);
key_t key = ftok("shmfile",65);
int shmid = shmget(key,1024,0666|IPC_CREAT);
int *que = (int*) shmat(shmid,(void*)0,0);
que[0]=-1;
do 
{
   
 FILE *fptr1 = fopen("sem_val.txt","r");
 fscanf(fptr1,"%d",&semaphore);
 fseek(fptr1,2,SEEK_SET);
 if(semaphore==1)
 printf("\nWait...\n");
 while(semaphore==1)
 {
 sleep(1); 
 semaphore = get_sem_val();
 }

 int size=0;
 for(int i=0;i<4;i++)
  {
    if(que[i]==-1)
     break;
    else
     size++;
  }
 if(size>3)
 printf("Buffer is full...\n"); 
 else{
 int data;
 printf("Enter an value .\n");
 scanf("%d",&data);
 int i;
 for(i=0;i<size;i++);
 que[i]=data;
 que[i+1]=-1;
 printf("%d is produced",data);
 }
 fclose(fptr1);
 sem_val(0);   
 printf("\nPress 1 to continue.\n");
 scanf("%d",&c);

}while(c==1);
return 0;
}

