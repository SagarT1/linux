#include<stdio.h>
int main()
{
  FILE *fp1,*fp2;
  char ch;
  fp1=fopen("file1","r");
  if(fp1==NULL)
  {
    printf("File error");
   return;
  }

  fp2=fopen("file1","r");
  if(fp2==NULL)
  {
    printf("File error");
   return;
  }
  fp2=fopen("file2","w");
  do
  {
    ch=fgetc(fp1);
     if(ch==EOF)
        break;
     else
      fputc(ch,fp2);
  }while(ch!=EOF);
fclose(fp1);
fclose(fp2);
}
