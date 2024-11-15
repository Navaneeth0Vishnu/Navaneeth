#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
char add[6],length[10],input[10],binary[12],bitmask[12],relocbit;
int start,inp,len,i,address,opcode,addr,actualadd;
FILE *f1,*f2;
printf("Enter the actual address = ");
scanf("%d",&start);
f1=fopen("relinput.txt","r");
f2=fopen("reloutput.txt","w");
fscanf(f1,"%s",input);
while(strcmp(input,"E")!=0)
{
if(strcmp(input,"H")==0)
{
fscanf(f1,"%x",add);
fscanf(f1,"%s",length);
fscanf(f1,"%s",input);
}
if(strcmp(input,"T")==0)
{
fscanf(f1,"%x",&address);
fscanf(f1,"%s",bitmask);
address+=start-add;
len=strlen(bitmask);
for(i=0;i<len;i++)
{
fscanf(f1,"%d",&opcode);
fscanf(f1,"%x",&addr);
relocbit=bitmask[i];
if(relocbit=='0')
actualadd=addr;
else
actualadd=addr+start-add;
fprintf(f2,"%x\t%d%d\n",address,opcode,actualadd);
address+=3;
}
fscanf(f1,"%s",input);
}
}
fclose(f1);
fclose(f2);
printf("FINISHED\ncheck the file");
}
