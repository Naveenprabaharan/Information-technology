// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10
int j=0;
void write();
// structure for message queue
struct mesg_buffer {
long mesg_type;
char mesg_text[100];
} message;
void write()
{
j++;
key_t key;
int msgid;
key = ftok("progfile", 65);
msgid = msgget(key, 0666 | IPC_CREAT);
message.mesg_type = 1;
if(j<=1)
printf("\nWrite Data : ");
else
printf("\nREPLY :");
scanf("\n");
gets(message.mesg_text);
msgsnd(msgid, &message, sizeof(message), 0);
printf("\nData send is : %s \n", message.mesg_text);
}
void read()
{
struct mesg_buffer
{
  long mesg_type;
char mesg_text[100];
} message;
key_t key;
int msgid;
key = ftok("File", 90);
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
printf(" \n1.Send Messsage To terminal 2 \n\n 2.Read Message From terminal 2 :");
scanf("%d",&a);
switch(a)
{
case 1:
{
write();
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