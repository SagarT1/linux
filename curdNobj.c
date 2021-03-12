#include<stdio.h>
#include<string.h>
struct employees
{
  int id;
  char name[10];
};
typedef struct employees emp;
FILE *fp;
int ch=0;
int main()
{
	do
	{
	       menu();
       	       printf("Enter the choice\n");
	       scanf("%d",&ch);
	       switch(ch)
	       {
		  case 1:create(); break;
		  case 2:read(); break;
		  case 3:update(); break;
		  case 4:search(); break;
		  case 5:delete(); break;
		  case 6:exit(1); break;
		  default:printf("wrong choice\n");
	        }
	}while(ch);
}
void menu()
{
	printf("1.CREATE\n2.READ\n3.UPDATE\n4.SEARCH\n5.DELETE\n6.EXIT\n");
	return;
}
void create()
{
  int i;
  emp e[4];
  fp=fopen("wfile","w");
  if(fp==NULL)
  {
    printf("file error\n");
    return;
  }
  printf("Enter the details of all employees\n"); 
  for(i=0;i<4;i++)
{ printf("%d employee details\n",i);
  scanf("%d",e[i].id);
  scanf("%s",e[i].name);
  fwrite(&e[i],1,sizeof(e[i]),fp);
}
  fclose(fp);
}
void read()
{
  emp e[4];
  int i;
  fp=fopen("wfile","r");
  if(fp==NULL)
  {
	printf("File Error\n");
	return;
  }
  for(i=0;i<4;i++)
  fread(&e[i],1,sizeof(e[i]),fp);
  fclose(fp);
}
void update()
{
  int nid,i;
   emp e[4];
  printf("Enter the id to be searched\n");
  scanf("%d",nid);
  for(i=0;i<4;i++)
  {
  if(e[i].id==nid)
  {
	printf("Enter the details to be updated\n");
	scanf("%d",&e[i].id);
	scanf("%s",e[i].name);
        fseek(fp,sizeof(e[i]),SEEK_SET);
	fwrite(&e[i],1,sizeof(e[i]),fp);
	return;
  }
  else
   {
     printf("Information not found\n");
     return;
   }
  }
}
void search()
{
  emp e[4];
  int i,sid;
  printf("Enter the id to be searched\n");
  scanf("%d",sid);
  for(i=0;i<4;i++)
  {
    if(e[i].id==sid)
     {
       fseek(fp,sizeof(e[i]),SEEK_SET);
       printf("Information is found\n");
      }
     else
     printf("not found\n");
  }
     return;
}
void delete()
{
  int i,did;
  emp e[4];
  FILE *fp1;
  fp1=fopen("newfile","w");
  printf("enter the id to be deleted\n");
  scanf("%d",did);
  for(i=0;i<4;i++)
  {
  if(e[i].id!=did)
  {
	fread(&e[i],1,sizeof(e[i]),fp);
        fwrite(&e[i],1,sizeof(e[i]),fp1);
  }
  }
  return;
}


