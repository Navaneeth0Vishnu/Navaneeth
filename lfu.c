#include<stdio.h>
int frame[100][3],frames_updated=0;

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
int small=frame[0][2],index=0,i;
for(i=1;i<frames_updated;i++)
{
if(frame[i][2]<=small)
{
if(frame[i][2]==small)
{
if(frame[i][1]<frame[index][1])
{
index=i;
}
}
else
{
small=frame[i][2];
index=i;
}
}
}
return(index);
}


void main()
{
int nf,n,ref[100],current=0,page_fault=0,i,j,f,p,index,feq;
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
feq=0;
p=ref[i];
f=search(p);
for(j=0;j<i;j++)
{
if(ref[j]==p)
{
feq++;
}
}
if(f==-1)
{
page_fault++;
if(frames_updated<nf)
{
frame[frames_updated][0]=p;
frame[frames_updated][1]=current;
frame[frames_updated][2]=feq;
frames_updated++;
}
else
{
index=replace();
frame[index][0]=p;
frame[index][1]=current;
frame[index][2]=feq;
}
}
else
{
frame[f][1]=current;
frame[f][2]=feq;
}
current++;
}
printf("\nno of page fault = %d ",page_fault);
}