#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
int main(void){int p[2];if(pipe(p)<0){perror("pipe");return 1;}pid_t c=fork();if(c<0){perror("fork");return 1;}if(!c){close(p[1]);char b[128];ssize_t n=read(p[0],b,127);if(n>0){b[n]=0;dprintf(1,"child received: %s\n",b);}close(p[0]);_exit(0);}close(p[0]);char*m="hello through pipe";write(p[1],m,strlen(m));close(p[1]);waitpid(c,NULL,0);return 0;}