#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
int glob = 0;
void *myThreadFun(void *vargp) 
{ 
    int *myid = (int *)vargp; 

    int locl =1;

    static int st = 0; 

    ++st; ++glob; 
    printf("Thread ID: %d, Static: %d, Global: %d, Local: %d\n", *myid, ++st, ++glob,++locl); 
} 
  
int main() 
{ 
    int i; 
    pthread_t tid; 
  
    for (i = 0; i < 3; i++) 
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 
  
    pthread_exit(NULL); 
    return 0; 
}
