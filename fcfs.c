#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct process{
 int pid,bt,at,tat,wt,ct;
 }p[100];
 
 void main(){
 int n,i,j,flag;
 int temp=0;
 int sum=0;
 float avg_tat,avg_wt,t_tat,t_wt;
 
 printf("Enter the process number:\n");
 scanf("%d",&n);
 for(i=0;i<=n-1;i++){
  p[i].pid=i+1;
  printf("Enter the process id,arrival time,burst time of the process:\n");
  scanf("%d%d%d",&p[i].pid,&p[i].at,&p[i].bt);
  }
  for(i=0;i<n;i++){
  for(j=0;j<n-i-1;j++){
  if(p[j].at>p[j+1].at){
  
  temp=p[j].pid;
  p[j].pid=p[j+1].pid;
  p[j+1].pid=temp;
  
  temp=p[j].at;
  p[j].at=p[j+1].at;
  p[j+1].at=temp;
  
  temp=p[j].bt;
  p[j].bt=p[j+1].bt;
  p[j+1].bt=temp;
  }
  }
  }
  for(i=0;i<n;i++){
  if(sum<p[i].at){
  sum=p[i].at;
  i--;
  }
  else{
  sum=sum+p[i].bt;
  p[i].ct=sum ;
  }
  }
  
  for(i=0;i<n;i++)
  {
  p[i].tat=p[i].ct-p[i].at;
  p[i].wt=p[i].tat-p[i].bt;
  t_tat=t_tat+p[i].tat;
  t_wt=t_wt+p[i].wt;
  }
  avg_tat=t_tat/n;
  avg_wt=t_wt/n;
  
  
  printf(" process details\n");
  printf(" details of process\npid    at      bt      ct      tat     wt\n");
  for(i=0;i<n;i++)
  {
  printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
  }
  printf("the total Turn Around Time is %f\n",t_tat);
  printf("The total Waiting Time is %f\n",t_wt);
  printf("The average Turn Around Time is %f\n",avg_tat);
  printf("The average Waiting Time is %f",avg_wt);
  printf("\nGhant chart is :");
  printf("\n|");
  
  for(i=0;i<n;i++){
 if(p[i].at==0){
 flag=1;
 }
 }
 if(flag==1){
 for(i=0;i<n;i++)
 {

 printf(" P%d| ",p[i].pid);
}
printf("\n 0");
 for(i=0;i<n;i++){
 printf("   %d ",p[i].ct );}
 printf("\n");
 }
 
 else {
 printf("\t|");
 for(i=0;i<n;i++)
 {

 printf(" P%d| ",p[i].pid);
}
printf("\n");
 printf(" 0\t%d",p[0].at);
 for(i=0;i<n;i++){
 
 printf("   %d ",p[i].ct );}

 printf("\n");
 }
 
 }

  
  
  
  
  
  
  
  
  
  
