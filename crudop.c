#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void read();
void delete();
void create();
void update();
void search(int,int*,int*);
struct node
{
	int data;
	char name[10];
};
typedef struct node n;
n e1,e2,e3,e4;int size=4;
FILE *fp=NULL, *fp1=NULL;
void menu()
{
	printf("1 create \n2 read \n3 update \n4 delete \n5 exit\n");
}
int main()
{
//	FILE *fp;
	int ch;
	while(1)
	{
		menu();
		printf("Enter the Choice\n");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1: create(); break;
		case 2: read(); break;
		case 3: update(); break;
		//case 4: delete(); break;
		case 5: exit(1);
		Default: printf("wrong choice\n");
	}
	}
}
void create()
{
//FILE *fp;
fp = fopen("emprecords", "wb");
if(fp==NULL)
{
	printf("file error\n");
	return;
}
	e1.data=10;
	e2.data=20;
	e3.data=30;
	e4.data=40;
	strcpy(e1.name,"neha");
	
	strcpy(e2.name,"darshu");
	strcpy(e3.name,"sagar");
	strcpy(e4.name,"kunya");
	fwrite(&e1,1,sizeof(e1),fp);

	fwrite(&e2,1,sizeof(e2),fp);
	fwrite(&e3,1,sizeof(e3),fp);		
	fwrite(&e4,1,sizeof(e4),fp);
	printf("data recorded\n");
	fclose(fp);
}

void read()
{
//	FILE *fp;
	fp=fopen("emprecords","rb");
	fread(&e1,sizeof(e1),1,fp);
	printf("data=%d name=%s\n", e1.data,e1.name);
	
	fread(&e2,sizeof(e2),1,fp);
	printf("data=%d name=%s\n", e2.data,e2.name);

	fread(&e3,sizeof(e3),1,fp);
	printf("data=%d name=%s\n", e3.data,e3.name);

	fread(&e4,sizeof(e4),1,fp);
	printf("data=%d name=%s\n", e4.data,e4.name);

fclose(fp);
}

void update()
	{
//	FILE *fp;
	n e; //object
//	fp=fopen("emprecords","r+");
	int data;
	int found=0,pos=0;
	printf("enter the data to be update\n");
	scanf("%d",&e.data);
	scanf("%s",e.name);
	search(e.data,&found,&pos);
	fp=fopen("emprecords","r+");
	if(fp==NULL)
	{
		printf("file error\n");
		return;
	}
	fseek(fp,sizeof(e)*(pos-1),SEEK_SET);
	fwrite(&e,1,sizeof(e),fp);
	fclose(fp);
}

void search( int data1, int *found, int *pos)

{
	int count=0,flag=0;
	n e1;
	fp1=fopen("emprecords", "rb");
	while(fread(&e1,1,sizeof(e1),fp1)>0)
	{
		count++;
		if(e1.data==data1)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("not found\n");
		fclose(fp1);
		exit(1);
	}
	else
	{
		*pos=count;
		*found=1;
	}
	fclose(fp1);


}
