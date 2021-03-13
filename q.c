#include<stdio.h>
#include<stdlib.h>
#define size 5
int f=0,r=-1;
int len=0;
void removes();
void push();
void print();
int q[size];

int main()
{
int ch;
do{
printf("\n1) insert \n2)remove \n3)print \n4)exit\n");
printf("enter a choiec\n");
scanf("%d",&ch);
switch(ch)
{
case 1: push();break;
case 2: removes();break;
case 3: print();break;
case 4: exit(1);
default: printf("wrong choice\n");
}
}while(ch!=4);


return 0;
}
void push()
{
if(r==size-1)
{
	printf("queue is full\n");
	return;
}
r++;
printf("enter the data\n");
scanf("%d",&q[r]);
len++;
}
void removes()
{
if(r==-1)
{printf("empty\n");
return;
}
printf("deleted is %d",q[f]);
f++;
if(f>r)
{
f=0;r=-1;
}

}

void print()
{
if(f==0 && r==-1)
	printf("empty\n");

int i;
for(i=f;i<=r;i++)
{
printf("%d ",q[i]);
}
}

