#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
void forkexample()  
{  	int x = 1;
    fork();     
    fork(); 	
    if (fork() == 0)  		
       printf("Child has x = %d\n", ++x);  	
    else if(fork()>0) 		
       printf("Parent has x = %d\n", --x); 	
    else 	    
       printf("Fork Failure\n"); 
}
       
int main()  
{  	
   forkexample();  	
   return 0;  
} 
