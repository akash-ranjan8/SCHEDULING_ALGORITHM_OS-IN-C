//SJF SCHEDULING(NON PRE-EMPTIVE)
#include<stdio.h>
int main()
{ int n,i,j;
  printf("enter the number of process\n");
  scanf("%d",&n);
  int p[n];
  int bt[n];
  int tat[n];
  int wt[n];
  int temp,pos;
  float avg_tat,avg_wt;
  int total_tat, total_wt;
  total_tat=0;
  total_wt=0;
  printf("enter the burst time\n");
  for(i=0;i<n;++i)
  { scanf("%d",&bt[i]);
    p[i]=i+1;
  }
  //SORTING OF PROCESS WITH THERE BURST TIME
  for(i=0;i<n;++i)
  { pos=i;
    for(j=i+1;j<n;++j)
    {   if(bt[j]<bt[pos])
        {  pos=j;
        }
    }
    temp=bt[i];
    bt[i]=bt[pos];
    bt[pos]=temp;
    
    temp=p[i];
    p[i]=p[pos];
    p[pos]=temp;
  }
  wt[0]=0;
  for(i=1;i<n;++i)
  { wt[i]=0;
    for(j=1;j<n;++j)
    { wt[i]=wt[i]+bt[j];
    }
    total_wt+=wt[i];
   }
   avg_wt=total_wt/n;
   for(i=0;i<n;++i)
   { tat[i]=bt[i]+wt[i];
     total_tat+=tat[i];
   }
   avg_tat=total_tat/n;
printf("solution\n");
  printf("P#\t  BT\t CT\t TAT\t WT\t\n\n");
  for(i=0;i<n;++i)
  { printf("P%d\t  %d\t %d\t %d\t %d\n",i+1,bt[i],ct[i],tat[i],wt[i]);
  }
  printf("average turn around time is =%f\n",avg_tat);
  printf("average waiting time is =%f\n",avg_wt);
  return 0;
}
