//PRIORITY SCHEDULING(PRE-EMPTIVE)
#include<stdio.h>
int main()
{ int n,i;
  printf("enter the no.of processes\n");
  scanf("%d",&n);
  int at[n];
  int bt[n];
  int priority[n];
  int end,k,time,m;
  int count=0;
  int temp[n];
  int total_tat=0;
  int total_wt=0;
  float avg_tat,avg_wt;
  printf("enter the arrival time, burst time and priority of the process\n");
  for(i=0;i<n;++i)
  { scanf("%d%d%d",&at[i],&bt[i],&priority[i]);
    temp[i]=bt[i];
  }
 for(time=0;count!=n;++time)
 { m=n-1;
   for(i=0;i<n;++i)
   { if(at[i]<=time && priority[i]<priority[m] && bt[i]>0)
     { m=i;
     }
   }
   --bt[m];
   if(bt[m]==0)
   { count++;
     end=time+1;
     total_wt=total_wt+end-at[m]+temp[m];
     total_tat=total_tat+end-at[m];
   }
  }
 avg_tat=total_tat/n;
 avg_wt=total_wt/n;
 printf("\nAVERAGE TURN AROUNT TIME = %f",avg_tat);
 printf("\nAVERAGE WAITING TIME = %f",avg_wt);
 return 0;
}
  
