#include<stdio.h>
 
int main()
{
      int frames[10], temp[10], pages[10];
      int total_pages, m, n, position, k, l, total_frames,set=0;
      int a = 0, b = 0, page_fault=0,page;
      printf("\nEnter Total Number of Frames:\t");
      scanf("%d", &total_frames);
      for(m = 0; m < total_frames; m++)
      {
            frames[m] = -1;
      }
      printf("Enter Total Number of Pages:\t");
      scanf("%d", &total_pages);
      page=total_pages;
      printf("Enter Values for Reference String:\n");
      for(m = 0; m < total_pages; m++)
      {
            scanf("%d", &pages[m]);
      }
      for(n = 0; n < total_pages; n++)
      {
       printf("reference string [%d] : ",pages[n]);
       set=0;
       for(m=0;m<total_frames;m++){
       if(pages[n]==frames[m])
       set=1;
     }
       if(set==1)
       {
         printf("\n");
         page-=1;
         continue;
}
         a = 0, b = 0;
         for(m = 0; m < total_frames; m++)
          {
                if(frames[m] == pages[n])
                {
                        a = 1;
                        b = 1;
                        break;
                  }
           }
            if(a == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        if(frames[m] == -1)
                        {
                              frames[m] = pages[n];
                              b = 1;
                              break;
                        }
                  }
            }
            if(b == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        temp[m] = 0;
                  }
                  for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
                  {
                        for(m = 0; m < total_frames; m++)
                        {
                              if(frames[m] == pages[k])
                              {
                                    temp[m] = 1;
                              }
                        }
                  }
                  for(m = 0; m < total_frames; m++)
                  {
                        if(temp[m] == 0)
                        position = m;
                  }
                  frames[position] = pages[n];
                  page_fault++;
            }

            for(m = 0; m < total_frames; m++)
            {
            	  if(frames[m]==-1){
            	  printf("| ");
            	  continue;
            }
                  printf("|%d", frames[m]);
            }
            printf("|\n");
      }
      printf("\nTotal Number of Page Faults:\t%d\n", page);
      return 0;
}
