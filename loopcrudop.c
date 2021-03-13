#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void update();
void delete();
void search();
void create();
void read();
void menu();
struct employees
{
  int id;
  char name[10];
};
int flag=0,count=0;
typedef struct employees emp;
//emp e[4];
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
  fp=fopen("wfile","wb");
  if(fp==NULL)
  {
    printf("file error\n");
    return;
  }
  printf("Enter the details of all employees\n"); 
  for(i=0;i<4;i++)
{ printf("%d employee id and name\n",i);
  scanf("%d%s",&e[i].id,e[i].name);
 // scanf("%s",e[i].name);
  fwrite(&e[i],1,sizeof(e[i]),fp);
}
  fclose(fp);
}
void read()
{
  emp e[4];
  int i;
  fp=fopen("wfile","rb");
  if(fp==NULL)
  {
	printf("File Error\n");
	return;
  }
  for(i=0;i<4;i++)
{
  fread(&e[i],1,sizeof(e[i]),fp);
  printf("[%d %s]\n",e[i].id,e[i].name);
}
  fclose(fp);
}
void update()
{
  int nid,i;
	FILE *fp;
	fp=fopen("wbfile","r+");
   emp e[4];int flag=0;
  printf("Enter the id to be update\n");
  scanf("%d",&nid);
  for(i=0;i<4;i++)
  {
  fread(&e[i],1,sizeof(e[i]),fp);
  if(e[i].id==nid)
  {
	printf("Enter the new name to be updated\n");
	//scanf("%d",&e[i].id);
	scanf("%s",e[i].name);
        fseek(fp,sizeof(e[i]),SEEK_SET);
	fwrite(&e[i],1,sizeof(e[i]),fp);
	flag=1;
	//return;
  }
}
	if(flag==1)
	printf("inforamtion update\n");
  else
   {
     printf("Information not updated\n");
   }
  
fclose(fp);
}
void search()
{
  emp e[4];
  int i,sid;
	FILE *fp;
	fp=fopen("wfile","rb");
  printf("Enter the id to be searched\n");
  scanf("%d",&sid);
 /* for(i=0;i<4;i++)
  {
    if(e[i].id==sid)
     {
       fseek(fp,sizeof(e[i]),SEEK_SET);
       printf("Information is found\n");
	printf("[%d %s]\n",e[i].id,e[i].name);
      }
     else
     printf("not found\n");
  }*/
	 i=0;
for(i=0;i<4;i++)
{
 fread(&e[i],1,sizeof(e[i]),fp);

   count++;
                if(e[i].id==sid)
                {
			printf("%s\n",e[i].name);
                        flag=1;
                        break;
                 }
	
//printf("\n%d\n",count);
}
        if(flag==0)
        {
                printf("not found\n");
	}
	else
	{
	flag=0;
	printf("\nfound\n");
	}



	fclose(fp);
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


