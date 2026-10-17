#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
int main(void){char p[]="/tmp/vmv-map-XXXXXX";int f=mkstemp(p);if(f<0)return 1;char s[]="mapped file\\n";write(f,s,sizeof s);char*m=mmap(0,sizeof s,PROT_READ|PROT_WRITE,MAP_SHARED,f,0);if(m==MAP_FAILED){close(f);unlink(p);return 1;}m[0]='M';msync(m,sizeof s,MS_SYNC);puts(m);munmap(m,sizeof s);close(f);unlink(p);return 0;}