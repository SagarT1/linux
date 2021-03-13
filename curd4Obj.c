#include<stdio.h>
#include<string.h>
struct employees
{
  int id;
  char name[10];
};
typedef struct employees emp;
FILE *fp=NULL,*fp1=NULL;
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
  emp e1,e2,e3,e4;
  fp=fopen("wfile","wb");
  if(fp==NULL)
  {
    printf("file error\n");
    return;
  }
  e1.id=10;
  e2.id=20;
  e3.id=30;
  e4.id=40;
  strcpy(e1.name,"RAJ");
  strcpy(e2.name,"John");
  strcpy(e3.name,"RAVI");
  strcpy(e4.name,"James");
  fwrite(&e1,1,sizeof(e1),fp);
  fwrite(&e2,1,sizeof(e2),fp);
  fwrite(&e3,1,sizeof(e3),fp);
  fwrite(&e4,1,sizeof(e4),fp);
  fclose(fp);
}
void read()
{
  emp e1,e2,e3,e4;
  fp=fopen("wfile","rb");
  if(fp==NULL)
  {
	printf("File Error\n");
	return;
 }
  fread(&e1,1,sizeof(e1),fp);
  printf("%d\t%s\n",e1.id,e1.name);
  fread(&e2,1,sizeof(e2),fp);
  printf("%d\t%s\n",e2.id,e2.name);
  fread(&e3,1,sizeof(e3),fp);
  printf("%d\t%s\n",e3.id,e3.name);
  fread(&e4,1,sizeof(e4),fp);
  printf("%d\t%s\n",e4.id,e4.name);
  fclose(fp);
}
void update()
{
  emp e;
  int found=0,pos=0;
  printf("Enter the emp id and new name\n");
  scanf("%d",&e.id);
  scanf("%s",e.name);
  searchupdate(e.id,&found,&pos);
  fp=fopen("wfile","r+");
  if(fp==NULL)
  {
 	printf("File Error\n");
	return;
  }
  fseek(fp,sizeof(e)*(pos-1),SEEK_SET);
  fwrite(&e,1,sizeof(e),fp);
  fclose(fp);  
}
void searchupdate(int id1,int *found,int *pos)
{
  emp ee;
  int count=0,flag=0;
  fp1=fopen("wfile","rb");
  while(fread(&ee,1,sizeof(ee),fp1) > 0)
  {
	count++;
	  if(ee.id==id1)
	  {
	     flag=1;
	     break;
	  }
   }
   if(flag == 0)
   {
	printf("Not found\n");
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
void search()
{
  emp e;
  int found=0,pos=0;
  int i,sid;
  printf("Enter the id to be searched\n");
  scanf("%d",sid);
  searchupdate(e.id,&found,&pos);
  
  
	printf("Employee found\n");
	return;
  
}
void delete()
{
  int i;
  emp e;
  FILE *fp1;
  fp1=fopen("newfile","w");
  printf("enter the id to be deleted\n");
  scanf("%d",e.id);
  del(e.id);
 // searchupdate(e.id,&found,&pos);
/*  fp=fopen("wfile","r+");
  if(fp==NULL)
  {
 	printf("File Error\n");
	return;
  }  
	fread(&e,1,sizeof(e),fp);
        fwrite(&e,1,sizeof(e),fp1);
  return;*/
fclose(fp1);
}
void del(int id1)
{
  emp ee1;
  int c=0,found=0,pos=0;
  searchupdate(ee1.id,&found,&pos);
  fp=fopen("wfile","r+");
  if(fp==NULL){
 	printf("File Error\n");
	return;}
  while(c!=pos)
{ 
	if(c==pos) break;
 	else{
        fread(&ee1,1,sizeof(ee1),fp);
        fwrite(&ee1,1,sizeof(ee1),fp1);c++;
         return; 
}
}
   fclose(fp);
}
