#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define buffer 3

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

void consumer()
{
int semaphore,cnt;
}

int main()
{
int c,semaphore;
sem_val(0);
key_t key = ftok("shmfile",65);
int shmid = shmget(key,1024,0666|IPC_CREAT);
int *que = (int*) shmat(shmid,(void*)0,0);

do
{
  
  FILE *fptr1=fopen("sem_val.txt","r");
  fscanf(fptr1,"%d",&semaphore);
  if(semaphore==1)
  printf("\nWait...\n");
  while(semaphore==1)
  {
  sleep(1);
  semaphore = get_sem_val();
  }
  sem_val(1);
  int size=0;
  for(int i=0;i<4;i++)
  {
   if(que[i]==-1)
     break;
   else
     size++;
  }
  if(size>0)
  {
  int temp = que[0];
  for(int i=1;i<size;i++)
  {
   que[i-1]=que[i];
  }
  que[size-1]=-1;
  printf("%d item is consumed\n",temp);
  }
  else{
  printf("buffer is empty.\n");
  }
  sem_val(0);
  printf("Press 1 to continue...\n");
  scanf("%d",&c);
}while(c==1);

return 0;
}
