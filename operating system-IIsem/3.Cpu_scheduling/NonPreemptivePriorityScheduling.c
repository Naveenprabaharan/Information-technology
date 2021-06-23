#include<stdio.h>
void sort();
struct node
 {
 int P;
 int priori;
 };
struct node prior[20];
int limit;
int main()
{
    int min;
     int min_index;
     int burst_time[20], process[20], waiting_time[20], TAT[20], priority[20];
     int i, j, sum = 0, position, temp;
     float average_wait_time, average_TAT;
     printf("Enter Total Number of Processes:\t");
     scanf("%d", &limit);
     printf("\nEnter BT and Priority For %d Processes\n", limit);
     for(i = 0; i < limit; i++)
     {
           printf("\nProcess[%d]\n", i + 1);
           printf("Process BT:\t");
           scanf("%d", &burst_time[i]);
           printf("Process Priority:\t");
           scanf("%d", &priority[i]);
           prior[i].priori=priority[i];
           prior[i].P=i+1;
           process[i] = i + 1;
     }
     for(i = 0; i < limit; i++)
     {
           position = i;
           for(j = i + 1; j < limit; j++)
           {
                 if(priority[j] < priority[position])
                 {
                       position = j;
                 }
           }
           temp = priority[i];
           priority[i] = priority[position];
           priority[position] = temp;
           temp = burst_time[i];
           burst_time[i] = burst_time[position];
           burst_time[position] = temp;
           temp = process[i];
           process[i] = process[position];
           process[position] = temp;
     }
     waiting_time[0] = 0;
     for(i = 1; i < limit; i++)
     {
           waiting_time[i] = 0;
           for(j = 0; j < i; j++)
           {
                 waiting_time[i] = waiting_time[i] + burst_time[j];
           }
           sum = sum + waiting_time[i];
     }
     average_wait_time = sum / limit;
     sum = 0;
     printf("\nProcess ID\t\tBT\t WAT\t TAT\n");
     for(i = 0; i < limit; i++)
     {
           TAT[i] = burst_time[i] + waiting_time[i];
           sum = sum + TAT[i];
           printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], burst_time[i], waiting_time[i], TAT[i]);
     }
     average_TAT = sum / limit;
     printf("\nAverage WAT:\t%f", average_wait_time);
     printf("\nAverage TAT:\t%f\n", average_TAT);
     sort();
    
     for(int i=0;i<limit;i++)
     {
      
       printf("|");
       printf("P%d\t",prior[i].P);
     }
 
     printf("|");
     printf("\n");
     for(int i=0;i<limit;i++)
     {
     if(i==0)
       {
         printf("0  ");
       }
       printf("%d \t",TAT[i]);
     }
 return 0;
 
}
void sort()
{
for(int i=0;i<limit-1;i++)
{
for(int j=0;j<limit-i-1;j++)
{
 if(prior[j].priori>prior[j+1].priori)
 {
   struct node temp;
   temp=prior[j];
   prior[j]=prior[j+1];
   prior[j+1]=temp;
 
 }
}
}
}

