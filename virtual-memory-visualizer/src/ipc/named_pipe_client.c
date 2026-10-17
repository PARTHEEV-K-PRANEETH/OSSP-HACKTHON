#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int c,char**v){const char*p=c>1?v[1]:"/tmp/vmv.fifo";int f=open(p,O_WRONLY);if(f<0){perror("open FIFO; start server first");return 1;}char*m="message from named FIFO client\n";write(f,m,strlen(m));close(f);return 0;}