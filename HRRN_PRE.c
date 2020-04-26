//HRRN SCHEDULING(PRE-EMPTIVE)
//end is for the maintaing of time taken for completion of the process
//time is used for maining in gantt chart
//hrrn[n] used to calculate highest response ratio next for each process
#include<stdio.h>
int main()
{ int n,i,j,total_wt,total_tat,end,time,count,pos,t,m;
  printf("enter the number of processes\n");
  scanf("%d",&n);
  int at[n];
  int bt[n];
  int temp[n];
  float hrrn[n];
  int p[n];
  total_wt=0;
  total_tat=0;
  count=0;
  int wt[n];
  float avg_tat,avg_wt;
  printf("enter the arrival time and burst time of the process\n");
  for(i=0;i<n;++i)
  { scanf("%d%d",&at[i],&bt[i]);
    temp[i]=bt[i];
    p[i]=i+1;
  }
//SORTING OF PROCESS AS PER THERE ARRIVAL TIME
  for(i=0;i<n;++i)
  { pos=i;
    for(j=i+1;j<n;++j)
    { if(at[i]>at[j])
      { pos=j;
      }
    }
    t=at[i];
    at[i]=at[pos];
    at[pos]=t;
    
    t=p[i];
    p[i]=p[pos];
    p[pos]=t;

   t=bt[i];
   bt[i]=bt[pos];
   bt[pos]=t;
   }
  wt[0]=0;
  for(time=0;count!=n;++time)
  { m=n-1;
    for(i=0;i<n;++i)
    { 
      wt[i]=end-bt[i];
      hrrn[i]=(wt[i]+bt[i])/bt[i];
      if(at[i]<=time && hrrn[m]<hrrn[i] && bt[i]>0)
       { m=i;
       }
    }
    --bt[m];
    if(bt[m]==0)
    { end=time+1;
      ++count;
      total_wt=total_wt+end-at[m]+temp[m];
      total_tat=total_tat+end-at[m];
    }
   }
  avg_tat=total_tat/n;
  avg_wt=total_wt/n;
  printf("AVERAGE TURN AROUND TIME = %f",avg_tat);
  printf("AVERAGE WAITING TIME = %f",avg_wt);
  return 0;
}
    
    
  
  
