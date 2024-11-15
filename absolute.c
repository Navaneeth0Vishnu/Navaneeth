#include<stdio.h>
#include<conio.h>
#include<string.h>


void main()
{
char input[10];
int start,len,address,prev;
FILE *f1,*f2;
f1=fopen("input.txt","r");
f2=fopen("output.txt","w");
fscanf(f1,"%s",input);
while(strcmp(input,"E")!=0)
{
if(strcmp(input,"H")==0)
{
fscanf(f1,"%d",&start);
fscanf(f1,"%d",&len);
fscanf(f1,"%s",input);
}
else if(strcmp(input,"T")==0)
{
fscanf(f1,"%x",&address);
fscanf(f1,"%s",input);
if((address>prev)&&(prev!=0))
{
    while(address!=prev)
    {
        fprintf(f2,"x\txx\n",prev);
        prev++;
    }
}
fprintf(f2,"%x\t%c%c\n",address,input[0],input[1]);
fprintf(f2,"%x\t%c%c\n",(address+1),input[2],input[3]);
fprintf(f2,"%x\t%c%c\n",(address+2),input[4],input[5]);
address+=3;
fscanf(f1,"%s",input);
}
else
{
fprintf(f2,"%x\t%c%c\n",address,input[0],input[1]);
fprintf(f2,"%x\t%c%c\n",(address+1),input[2],input[3]);
fprintf(f2,"%x\t%c%c\n",(address+2),input[4],input[5]);
address+=3;
fscanf(f1,"%s",input);
prev=address;
}
}
fclose(f1);
fclose(f2);
printf("FINISHED\ncheck the file");
getch();
}