#include <pthread.h>
#include <stdio.h>
#define N 100000
static long count;static pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;
static void*w(void*x){(void)x;for(int i=0;i<N;i++){pthread_mutex_lock(&m);count++;pthread_mutex_unlock(&m);}return 0;}
int main(void){pthread_t a,b;if(pthread_create(&a,0,w,0)||pthread_create(&b,0,w,0))return 1;pthread_join(a,0);pthread_join(b,0);printf("mutex count=%ld expected=%d\n",count,2*N);pthread_mutex_destroy(&m);return count==2L*N?0:1;}