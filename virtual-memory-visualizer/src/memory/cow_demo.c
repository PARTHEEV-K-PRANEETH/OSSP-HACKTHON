#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(void){int x=10;fflush(stdout);pid_t p=fork();if(p<0)return 1;if(!p){x=99;printf("child value=%d\\n",x);fflush(stdout);_exit(0);}waitpid(p,0,0);printf("parent value=%d\\n",x);return 0;}