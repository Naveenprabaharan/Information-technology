#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void put_sem_val(int val,char ope)
{
FILE *fptr=fopen("sem_val.txt","w");
fprintf(fptr,"%d %c",val,ope);
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
void read()
{
char c,ch;
int semaphore,key;
FILE *fptr1=fopen("sem_val.txt","r"),*fptr2;
fscanf(fptr1,"%d",&semaphore);
fseek(fptr1,2,SEEK_SET);
fscanf(fptr1,"%c",&c);
if(semaphore==1&&c=='w')
printf("\nWait writing process takes place...\n");
else if(semaphore==1&&c=='r')
printf("\nSince reader is inside,you can join...\n");
fseek(fptr1,0,SEEK_SET);
while(semaphore==1&&c=='w')
{
sleep(1);
semaphore = get_sem_val();
}
put_sem_val(1,'r');
printf("Go ahead:\n");
fptr2=fopen("file.txt","r");
fseek(fptr2,8,SEEK_SET);
ch=fgetc(fptr2);
while(ch!=EOF)
{
if(ch=="")
{
printf("\npress any key to continue. ");
scanf("%d",&key);
}
else
printf("%c",ch);
ch=fgetc(fptr2);
}
fclose(fptr1);
fclose(fptr2);
put_sem_val(0,"");
}
void write()
{
char c,str[100];
int semaphore;
FILE *fptr1 = fopen("sem_val.txt","r"),*fptr2;
fscanf(fptr1,"%d",&semaphore);
fseek(fptr1,2,SEEK_SET);
fscanf(fptr1,"%c",&c);
if(semaphore==1&&c=='r')
printf("\nWait reading process takes place...\n");
else if(semaphore==1&&c=='w')
printf("\nWait writing process takes place...\n");
fseek(fptr1,0,SEEK_SET);
while(semaphore==1)
{
sleep(1);
semaphore = get_sem_val();
}
put_sem_val(1,'w');
printf("Go ahead:\n");
fptr2=fopen("file.txt","a");
printf("Enter a line.\n");
scanf("\n");
scanf("%[^\n]%*c",str);
fprintf(fptr2,"%s",str);
fclose(fptr1);
fclose(fptr2);
put_sem_val(0,"");
}
int main()
{
int c,sem;
FILE *fptr=fopen("file.txt","w");
fprintf(fptr,"%s","content:");
fclose(fptr);
put_sem_val(0,"");
do{
printf("\n\n1)write\t2)read\t3)exit\n\n");
scanf("%d",&c);
switch(c)
{
case 1: write();
break;
case 2: read();
break;
case 3: exit(1);
}
} while(1);
return 0;
}