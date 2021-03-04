/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#define max 5
int top=-1;
int s[10];
void push()
{
    
    
    
    if( top>=max) //top==max-1
    {
        printf("\nTHE STACK IS FULL \n");
    }else
    {
        int ele;

    printf("\nenter the element: ");
    scanf("%d", &ele);
        ++top;
        s[top]=ele;
    
        
    }
    
    
}

int pop()
{
    if(top==-1)
    printf("THE STACK IS EMPTY\n");
    
    else{
        int delement= s[top];
        printf("\nthe popped elements is :%d\n", delement);
        --top;
    
    return delement;    
    }
    
    
}
void printstack()
{
  if(top==-1)
  {
   printf("\nSTACK IS EMPTY! can't print\n");
 }
  else
  {
  int i;
    printf("\n");
    for( i=top;i>=0; i--)
    printf("%d\n", s[i]);
  }
  printf("\n");
}



int main()
{
    int ch;

    while(1){
            printf("\nenter your choice:\n1) push \n2) pop \n3) print \n4) exit\n");
    scanf("%d", &ch);
    switch(ch)
    {
        
        case 1: push(); break;
        case 2: pop(); break;
        case 3: printstack(); break;
        case 4: exit(2);
        default: printf("\nwrong choice\n");
        
    }
    }

    return 0;
}
