
#include <stdio.h>
#include<stdlib.h>
int main()

  
    
{ 
int ch;
int *p,i;
int arr[20];
printf("enter the choice: 1)static 2)dynamic \n");
scanf("%d",&ch);
switch(ch)
{ 
case 1: 



printf("YOU have entered STATIC ZONE \n");
for(i=0; i<20; i++)
    { 
        arr[i]=i+1; //data+i
    }
for( i=0; i<20; i++)
    {        printf("%d ",arr[i]);
    }


break;
case 2:


printf("YOU have entered DYNAMIC ZONE \n");
p=(int *)malloc(sizeof(int)*20);
for( i=0; i<20; i++)
    { 
        *(p+i)=i+1;
        printf("%d ", *(p+i));
       
    } 
    
break;
default :
printf("wrong choice");
} 



    return 0;
} 
