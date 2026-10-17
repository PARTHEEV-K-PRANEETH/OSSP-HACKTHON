#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
static volatile sig_atomic_t stop=0;static void h(int s){(void)s;stop=1;}
int main(void){struct sigaction a={0};a.sa_handler=h;sigemptyset(&a.sa_mask);sigaction(SIGINT,&a,0);sigaction(SIGTERM,&a,0);puts("Running; Ctrl-C to stop.");while(!stop)pause();puts("Graceful shutdown.");return 0;}