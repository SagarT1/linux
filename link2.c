#include <stdio.h>
#include<stdlib.h>
void menu();
void print();
void insertAtEnd();
void insertAfter();

struct node{

int data;


struct node *link;

};

typedef struct node ll;

ll *first, *temp, *temp2; int ch;

int main()

{

do

{

menu();

printf("Enter your choice \n");

scanf("%d",&ch);

switch(ch)

{

case 1: insertAtEnd(); break;

case 2: insertAfter(); break;

case 3: print(); break;

case 4: exit(1);

default: printf("Wrong choice choice 1 to 4");

}

}while(ch!=4);

return 0;

}

void insertAfter()
{
    ll *temp=(ll*)malloc(sizeof(ll));
    //ll *nextNode=NULL;
    int position,ele;
    printf("enter a data: ");
    scanf("%d", &ele);
    printf("enter position: ");
    scanf("%d", &position);
    temp->data= ele;
    temp->link=NULL;
    
    if(first==NULL)
    {
        if(position!=0)
        return;
        else
        first=temp; 
        //set temp to be new head;
        return;

    }
    
    if(first!=NULL && position==0)
    {
        temp->link=first;
        first=temp;
        return;
    }
    ll *current=first;
    ll *previous=NULL;
    int i=0;
    while(i<position)
    {
        previous=current;
        current = current->link;
    
        if(current == NULL)
        {
            break;
        }
        i++;
    }
    temp->link=current;
    previous->link=temp;
    
}






void insertAtEnd(){

if(first==NULL){

first = (ll*)malloc(sizeof(ll));

printf("Enter Data ");

scanf("%d",&first->data);

first->link = NULL;

printf("inserted At End");

return;

}

temp = first ;

while(temp->link != NULL)

{

temp=temp->link;

}

temp2 = (ll*)malloc(sizeof(ll)); // New Last Node

printf("Enter Data ");

scanf("%d",&temp2->data);

temp2->link = NULL; // NULL because it is going to be Last Node

temp->link=temp2;

}

void print()

{

temp = first;

  if(temp==NULL)
      printf("Linked list empty\n");
    
while(temp!=NULL)

{

printf("[%d %u]",temp->data,temp->link);

temp = temp ->link;

}

}

void menu(){ printf("\n1 Insert\n2 InsertAfter \n3 Print \n4 Exit \n"); }

