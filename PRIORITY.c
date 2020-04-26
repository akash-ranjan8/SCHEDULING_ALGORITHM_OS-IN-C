//PRIORITY SCHEDULING(NON PRE-EMPTIVE)
//p[n] is array of process used for swapping the process with priority
#include<stdio.h>
int main()
{ int n,i,temp,pos,j;
  printf("enter the number of processes\n");
  scanf("%d",&n);
  int bt[n];
  int wt[n];
  int tat[n];
  int p[n];
  int priority[n];
  int total_tat=0;
  int total_wt=0;
  float avg_tat,avg_wt;
  printf("enter the burst time of the processes and its priority number\n");
  for(i=0;i<n;++i)
  { scanf("%d%d",&bt[i],&priority[i]);
    p[i]=i+1;
  } 
  //SORTING OF PROCESS WITH THERE PRIORITY
  for(i=0;i<n;++i)
  { pos=i;
    for(j=i+1;j<n;++j)
    { if(priority[pos]<priority[j])
      { pos=j;
      }
    }
   temp=priority[i];
   priority[i]=priority[pos];
   priority[pos]=temp;
   
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
   printf("\n AVERAGE TURN AROUND TIME = %f",avg_tat);
   printf("\n AVERAGE WAITING TIME = %f",avg_wt);
   return 0;
}

  
