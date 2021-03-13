#include<stdio.h>
#include<string.h>
struct node
{
int data;
char name[10];
};
int main()
{
struct node n1;
FILE *fp;
n1.data=222;
fp=fopen("binfile","rb");
if(fp==NULL)
{
printf("File error\n");
return;
}
fread(&n1,1,sizeof(n1),fp);
printf("data : %d\t",n1.data);
printf("name : %s",n1.name);
fclose(fp);
}
