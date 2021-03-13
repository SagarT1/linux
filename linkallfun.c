#include <stdio.h>
#include<stdlib.h>
void menu();
void print();
void deleteAtEnd();
void deleteAtPos();
void deleteAtBeg();
void insertAtEnd();
void insertAfter();
void insertAtBeg();
struct node{
int data;
struct node *link;
};
int length=0;
typedef struct node ll;
ll *first=NULL, *temp, *temp2; int ch;
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
			case 3: insertAtBeg(); break;
			case 4: deleteAtEnd(); break;
			case 5: deleteAtPos(); break;
			case 6: deleteAtBeg(); break;
			case 7: print(); break;
			case 8: exit(1);
			default: printf("Wrong choice choice 1 to 4");
		}
		}while(ch!=8);
return 0;

}

void deleteAtEnd()
{

temp=first;
if(first==NULL)
{
printf("List is empty\n");
return;
}
temp2=first;
while(temp->link!=NULL)
{
	temp2=temp;
	temp=temp->link;
}
temp2->link=NULL;
free(temp);
--length;


}

void deleteAtPos()
{
int pos;
temp=first;
if(first==NULL)
{
printf("List is empty\n");
return;
}


printf("enter a pos\n");
scanf("%d",&pos);
if(pos==1)
{
deleteAtBeg();
return;
}
if(pos<0 || pos>length)
{
	printf("\ninvalid pos\n");
	return;
}
temp2=NULL; int i;
for(i=0; i<pos-1;i++)
{
	temp2=temp;
	temp=temp->link;
}
temp2->link=temp->link;
free(temp);
--length;
}

void deleteAtBeg()
{
temp=first;
if(first==NULL)
{
	printf("List is empty\n");
	return;
}
first=temp->link;
free(temp);
--length;
}
void insertAfter()
{
int pos=0,ele;

if(first==NULL)
{

	insertAtEnd();
	return;
}
printf("enter a pos\n");
scanf("%d",&pos);
if((pos<=0) || (pos>length+1))
{
	printf("invalid pos\n");
	return;
}

if(pos==1)
{
 insertAtBeg();
return;
}

temp=first;int i;
for(i=0;i<pos-2;i++)
{
	temp=temp->link;
}

printf("enter a data\n");
scanf("%d",&ele);
temp2=(ll*)malloc(sizeof(ll));
temp2->data=ele;

temp2->link=temp->link;
temp->link=temp2;
length++;
printf("\ninserted at pos=%d\n",pos);

}

void insertAtEnd()
{
 int ele;
temp=(ll*)malloc(sizeof(ll));
printf("\nenter data:\n");
scanf("%d",&ele);
temp->data=ele;
temp->link=NULL;

if(first==NULL)
{
	first=temp;
	length++;
	return;
}

temp2 = first ;

while(temp2->link != NULL)
{
	temp2=temp2->link;
}
temp2->link=temp;
length++;
}



void insertAtBeg()
{
int ele;
temp=(ll*)malloc(sizeof(ll));
printf("enter data:\n");
scanf("%d",&ele);
temp->data=ele;
temp->link=NULL;

if(first==NULL)
{
	first=temp;
	length++;
 	return;
}
temp->link=first;
first=temp;
length++;

}
void print()

{

temp = first;

  if(temp==NULL)
      printf("Linked list empty\n");
    
while(temp!=NULL)

{

printf("[%d %u]->",temp->data,temp->link);

temp = temp ->link;

}

}

void menu(){ printf("\n1 InsertEND\n2 InsertAfter \n3 InsertAtBeg  \n4 deleteAtEnd \n5 deleteAtPos \n6 deleteAtBeg \n7 print \n8 Exit \n"); }

