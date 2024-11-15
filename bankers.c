#include<stdio.h>
int frame[100][2],frames_updated=0;

int search(int x)
{
int c=-1,i;
for(i=0;i<frames_updated;i++)
{
if(frame[i][0]==x)
{
c=i;
}
}
return(c);
}

int replace()
{
int small=frame[0][1],index=0,i;
for(i=1;i<frames_updated;i++)
{
if(frame[i][1]<small)
{
small=frame[i][1];
index=i;
}
}
return(index);
}


void main()
{
int nf,n,ref[100],current=0,page_fault=0,i,f,p,index;
printf("\nenter the no of frames = ");
scanf("%d",&nf);
printf("\nenter the no of pages = ");
scanf("%d",&n);
printf("\nenter the strings = ");
for(i=0;i<n;i++)
{
scanf("%d",&ref[i]);
}
for(i=0;i<n;i++)
{
p=ref[i];
f=search(p);
if(f==-1)
{
page_fault++;
if(frames_updated<nf)
{
frame[frames_updated][0]=p;
frame[frames_updated][1]=current;
frames_updated++;
}
else
{
index=replace();
frame[index][0]=p;
frame[index][1]=current;
}
}
current++;
}
printf("\nno of page fault = %d ",page_fault);
}
