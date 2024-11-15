#include<stdio.h>

struct process
{
int id,at,bt,ct,tat,wt,st;
}p[20],temp;

void main()
{
int i,tot_tat=0,tot_wt=0,complete=0,current=0;
float n,avg_tat,avg_wt;
printf("enter the number of process = ");
scanf("%f",&n);
for(i=0;i<n;i++)
{
printf("enter process id,at,bt = ");
scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
p[i].st=0;
}
while(complete!=n)
{
int min_bst=32765,index=-1;
for(i=0;i<n;i++)
{
if((p[i].at<=current)&&(p[i].st==0))
{
if(p[i].bt<=min_bst)
{
if(p[i].bt==min_bst)
{
if(p[i].at<p[index].at)
{
index=i;
min_bst=p[i].bt;
}
}
else
{
index=i;
min_bst=p[i].bt;
}
}
}
}
if(index==-1)
{
current++;
}
else
{
current+=p[index].bt;
p[index].st=1;
p[index].ct=current;
complete++;
}
}
printf("pid\t at\t bt\t ct\t tat\t wt\n ");
for(i=0;i<n;i++)
{
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
tot_wt+=p[i].wt;
tot_tat+=p[i].tat;
printf("%d\t %d\t %d\t %d\t %d\t %d\n ",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
}
printf("average tat = %f \n average wt = %f ",tot_tat/n,tot_wt/n);
}
