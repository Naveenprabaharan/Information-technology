#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef int Array[MAX];
int main()	
{
	int size, head, catch, i, j, index, seek = 0;
	float avg;
	Array queue, track, dist, flag = {0};
	printf("\n SSTF ( Shortest Seek Time First ) Algorithm : \n");
	printf("\nEnter Queue Size : ");	scanf("%d", &size);
	printf("\n\tEnter Track Numbers : ");	
             for(i = 0; i < size; i++)	
                      scanf("%d", &queue[i]);
	    printf("\n\tEnter Head Position : ");	
                       scanf("%d", &head);
                 track[0] = head;
	for(j = 0; j < size; j++)	
	   {
                    catch = 999;
		 for(i = 0; i < size; i++)	
			dist[i] = abs(head - queue[i]);
		  for(i = 0; i < size; i++)
			if(dist[i] < catch && flag[i] != 1)
				catch = dist[i], index = i;
		     seek += catch;
		     head = queue[index];
		      flag[index]++;
		       track[j+1] = head; 
	     }
	         printf("\n\n");
                        for(i = 0; i < size + 1; i++)	
                                printf(" %d -> ", track[i]);
	                       printf("\b\b\b   .");
	                   avg = seek/(float)size;
	      printf("\n\nTotal Seek Time   : %d\n\nAverage Seek Time : %.4f\n", seek, avg);
	        }
