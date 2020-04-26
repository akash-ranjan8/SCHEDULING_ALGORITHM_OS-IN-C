//SJF SCHEDULING (PRE-EMPTIVE)
//temp array is used to assign orignal value of burst time so that original burst time of process is not lost
/*count is used to update the process when its execution is complete*/
//time is used to updation of time in gantt chart
//end is used to assign time of the process completion
//smallest is used for the process with smallest burst time
//we had assigned a random value to bt[n-1] in order for just to compare it with other processes burst time
#include<stdio.h>
int main()
{ int n,i,end,smallest,time,count,total_wt,total_tat;
  count=0;
  total_tat=0;
  total_wt=0;
  float avg_tat;
  float avg_wt;
  printf("enter the number of processes\n");
  scanf("%d",&n);
  int at[n];
  int bt[n];
  int temp[n];
  printf("enter the processes details\n");
  for(i=0;i<n;++i)
  { printf("enter the process arrival time:\n");
    scanf("%d",&at[i]);
    printf("enter the process burst time:\n");
    scanf("%d",&bt[i]);
    temp[i]=bt[i];
  }
  bt[n-1]=9999;
  for(time=0;count!=n;++time)
  { smallest=n-1;
    for(i=0;i<n;++i)
    { if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0)
      { smallest=i;
      }
    }
    --bt[smallest];
    if(bt[smallest]==0)
    { count++;
      end=time+1;
      total_wt=total_wt+end-at[smallest]+temp[smallest];
      total_tat=total_tat+end-at[smallest];
    }
   }
 avg_tat=total_tat/n;
 avg_wt=total_wt/n;
 printf("TOTAL TURN AROUND TIME = %f",avg_tat);
 printf("\nTOTAL WAITING TIME = %f",avg_wt);
 return 0;
}
 
