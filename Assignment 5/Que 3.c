#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
 int i,j;
 i=fork();
 if(i==0)//child process
 {
  for(j=1;j<=10;j++)
  printf("Child Process \n");
  exit(0);
 }
 else //parent process
 {
  for(j=1;j<=10;j++)
  printf("Parent Process \n");
 }
 exit(0);
}
