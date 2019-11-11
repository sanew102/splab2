// your code here
#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 
#include <stdlib.h> 
#include <errno.h>   
#include <sys/wait.h> 
  
int main(int argc, char* argv[]) 
{ 
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  pid_t p1 = fork();
  if(p1==0){
    printf("child 1: %d+%d=%d\n",a,b,a+b);
    exit(0);
  }
  wait(NULL);
  pid_t p2 = fork();
  if(p2==0){
    printf("child 2: %d*%d=%d\n",a,b,a*b);
    exit(0);
  }
  wait(NULL);
  pid_t p3 = fork();
  if(p3==0){
    printf("child 3: %d-%d=%d\n",a,b,a-b);
    exit(0);
  }

  wait(NULL);
  pid_t p4 = fork();
  if(p4==0){
    printf("child 4: %d/%d=%d\n",a,b,a/b);
    exit(0);
  }
  wait(NULL);
  printf("parent: done\n");
}
