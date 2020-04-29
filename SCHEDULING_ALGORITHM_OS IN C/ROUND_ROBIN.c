//ROUND ROBIN SCHEDULING
//here time is the parameter for the measurement of the time in gantt chart
//x is used to check no. of processes executed
//here count is used to main a process is running or not if count is zeo means process is running and if count =1 means that process is executed
//temp[i] is used to store burst time so that original burst time is not get affected
#include<stdio.h>
int main()
{ int n,i,x,count,time,total_wt,total_tat,time_quantum;
  count=0;
  total_wt=0;
  total_tat=0;
  float avg_wt,avg_tat;
  printf("enter the number of processes\n");
  scanf("%d",&n);
  int at[n];
  int bt[n];
  int temp[n];
  printf("enter the time quantum\n");
  scanf("%d",&time_quantum);
  x=n;
  printf("enter the arrival time and burst time of process\n");
  for(i=0;i<n;++i)
  { scanf("%d%d",&at[i],&bt[i]);
    temp[i]=bt[i];
  }
//CALCULATION OF TURN AROUND TIME AND WAITING TIME
 for(time=0,i=0;x!=0;)
 { //this if checks for process having burst time less than time quantum
   if(temp[i]<time_quantum && temp[i]>0)
   { time=time+temp[i];
     temp[i]=0;
     count=1;
   }
   //this checks for process having burst time greater than time quantum
   else if(temp[i]>0)
   { temp[i]=temp[i]-time_quantum;
     time=time+time_quantum;
   }
   //this if is for the process getting completed and here we reduce x to show a process is completed and again intializing count with 1
   if(temp[i]==0 && count==1)
   { --x;
     total_wt=total_wt+time-at[i]-bt[i];
     total_tat=total_tat+time-at[i];
     count=0;
   }
   //here i has reached its maximum so intialized with 0
   if(i==n-1)
   { i=0;
   }
   //here we increment value of i when arrival time of next process is less than time in gantt chart
   else if(at[i+1]<=time)
   { ++i;
   }
   else
   { i=0;
   }
 }
 avg_wt=total_wt/n;
 avg_tat=total_tat/n;
 printf("\nAVERAGE TURN AROUND TIME IS = %f",avg_tat);
 printf("\nAVERAGE WAITING TIME IS = %f",avg_wt);
 return 0;
}
   
  
