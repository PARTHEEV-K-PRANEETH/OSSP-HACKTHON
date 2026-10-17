#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main(int c,char**v){const char*p=c>1?v[1]:"/tmp/vmv.fifo";if(mkfifo(p,0600)<0&&errno!=EEXIST){perror("mkfifo");return 1;}puts("Waiting for FIFO client...");int f=open(p,O_RDONLY);if(f<0){perror("open");return 1;}char b[256];ssize_t n;while((n=read(f,b,sizeof b))>0)write(1,b,n);close(f);return 0;}