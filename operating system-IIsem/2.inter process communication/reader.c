#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10
int l=0;
void write();
struct mesg_buffer {
long mesg_type;
char mesg_text[100];
} message;
void write()
{
  l++;
key_t key;
int msgid;
key = ftok("File", 90);
msgid = msgget(key, 0666 | IPC_CREAT);
message.mesg_type = 1;
if(l<=1)
printf("WRITE MESSAGE : ");
else
printf("\nREPLY : ");
scanf("\n");
gets(message.mesg_text);
msgsnd(msgid, &message, sizeof(message), 0);
printf("\nData send is : %s \n", message.mesg_text);
}
void read()
{
struct mesg_buffer {
long mesg_type;
char mesg_text[100];
} message;
key_t key;
int msgid;
key = ftok("progfile", 65);
msgid = msgget(key, 0666 | IPC_CREAT);
msgrcv(msgid, &message, sizeof(message), 1, 0);
printf("\nData Received is : %s \n",
message.mesg_text);
msgctl(msgid, IPC_RMID, NULL);
}
int main()
{
fflush(stdin);
int a,b;
printf("*PRESS -3 -FOR EXIT*\n");
while(1)
{
printf(" \n1.Send Message to Terminal 1 \n\n 2.Read Message form Terminal 1 :");
scanf("%d",&a);
switch(a)
{
case 1:
{
write();
a=0;
break;
}
case 2:
{
read();
write();
break;
}
default :
{
exit(1);
}
}
}
}