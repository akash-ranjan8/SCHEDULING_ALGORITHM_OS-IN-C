//FCFS SCHEDULING(NON PRE-EMPTIVE)
#include<stdio.h>
int main()
{ int n,i,j,k;
  printf("enter the number of process\n");
  scanf("%d",&n);
  int at[n];
  int bt[n];
  int ct[n];
  int sum=0;
  int tat[n];
  int wt[n];
  printf("enter the process arrival time and burst  time\n");
  for(i=0;i<n;++i)
  {  scanf("%d",&at[i]);
   }
  for(i=0;i<n;++i)
  { scanf("%d",&bt[i]);
  }
  //CALCULATION OF COMPLETION TIME FOR PROCESSES
  for(j=0;j<n;++j)
  { sum=sum+bt[j];
    ct[j]=ct[j]+sum;
  }
  //CALCULATION OF TURNAROUND TIME 
  for(k=0;k<n;++k)
  { tat[k]=ct[k]-at[k];
  }
  //CALCULATION OF WAITING TIME
  for(i=0;i<n;++i)
  { wt[i]=tat[i]-bt[i];
  }
  //CALCULATION OF AVERAGE TURN AROUND TIME
  float total_tat,avg_tat;
  total_tat=0;
  for(j=0;j<n;++j)
  { total_tat+=tat[j];
  }
  avg_tat=total_tat/n;
  //CALCULATION OF AVERAGE WAITING TIME
  float total_wt,avg_wt;
  total_wt=0;
  for(k=0;k<n;++k)
  { total_wt+=wt[k];
  }
  avg_wt=total_wt/n;
  printf("solution\n");
  printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");
  for(i=0;i<n;++i)
  { printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
  }
  printf("average turn around time is =%f\n",avg_tat);
  printf("average waiting time is =%f\n",avg_wt);
  return 0;
}
