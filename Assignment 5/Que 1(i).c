#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#define true 1
#define false 0
int a, b;
sem_t sem;
void* inputno() {
 while(true) {
   printf("Enter two numbers: ");
   scanf("%d %d", &a, &b);
   sem_post(&sem);
   sleep(4);
 }
}
void* outputsum() {
  while(true) {
   sem_wait(&sem);
   printf("Sum = %d\n", a+b);
  }
}
int main() {
 pthread_t thread1;
 pthread_t thread2;
 sem_init(&sem, 0, 0);
 pthread_create(&thread1, NULL, inputno, NULL);
 pthread_create(&thread2, NULL, outputsum, NULL);
 pthread_join(thread1, NULL);
 pthread_join(thread2, NULL);
 printf("Both threads finished!\n");
 sem_destroy(&sem);
 return 0;
}
