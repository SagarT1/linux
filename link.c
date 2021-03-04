#include <stdio.h>

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

case 2: break;

case 3: print(); break;

case 4: exit(1);

default: printf("Wrong choice choice 1 to 4");

}

}while(ch!=4);

return 0;

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

while(temp!=NULL)

{

printf("[%d %u]",temp->data,temp->link);

temp = temp ->link;

}

}

void menu(){ printf("\n1 Insert \n3 Print \n4 Exit \n"); }

