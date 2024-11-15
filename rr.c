#include<stdio.h>

int q[100],f=-1,r=-1;

struct process
{
  int id,at,bt,ct,tat,wt,rt,status,qstatus;
};
void enqueue(int item)
{
   
    if((f==-1) && (r==-1))
    {
       f=0;
       r=0;
       q[r]=item;
    }
    else{
      r++;
      q[r]=item;
    }
}

int dequeue()
{
  int item;
  item=q[f];
  if(f==r)
  {
    f=-1;
    r=-1;
  }
  else{
     f++;
     
  }
   return item;
}


void main()
{
  struct process p[100],temp;
  int i,j,n,current_time=0,completed=0,tq=0;
  float tot_wt,tot_tat,avg_wt,avg_tat;
 
  printf("\nEnter the no of process: ");
  scanf("%d",&n);
 
  printf("\nEnter the time quantum: ");
  scanf("%d",&tq);
 
  for(i=0;i<n;i++)
  {
    printf("Enter ID,AT,BT of p%d: ",i+1);
    scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
    p[i].status=0;
    p[i].rt=p[i].bt;
    p[i].qstatus=0;
  }
 
 
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
       if(p[j].at>p[j+1].at)
       {
          temp=p[j];
          p[j]=p[j+1];
          p[j+1]=temp;
       }
    }
  }
 
 
  current_time=p[0].at;
  enqueue(0);
  p[0].qstatus=1;
 
  while(completed!=n)
  {
      i=dequeue();
      if(p[i].rt<=tq)
      {
         current_time+=p[i].rt;
         p[i].ct=current_time;
         p[i].status=1;
         completed++;
         p[i].rt=0;
      }
      else{
         current_time+=tq;
         p[i].rt=p[i].rt-tq;
      }
     
      for(j=i+1;j<n;j++)
      {
           if((p[j].at<=current_time) && (p[j].status==0) && (p[j].qstatus==0))
           {
              enqueue(j);
              p[j].qstatus=1;
           
           }
      }
     
      if(p[i].rt!=0)
      {
          enqueue(i);
      }
 
  }  
  for(i=0;i<n;i++)
  {
       p[i].tat=p[i].ct-p[i].at;
       p[i].wt=p[i].tat-p[i].bt;
       tot_tat+=p[i].tat;
       tot_wt+=p[i].wt;
  }
   
  avg_tat=tot_tat/n;
  avg_wt=tot_wt/n;
   
  printf("Process id\tAT\tBT\tCT\tTAT\tWT\t \n");
  for(i=0;i<n;i++)
  {
     printf("%d\t\t%d\t%d\t%d\t%d\t%d \n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
  }
 
  printf("Avg turnaround time %f\n",avg_tat);
  printf("Avg waiting time %f",avg_wt);
 
}