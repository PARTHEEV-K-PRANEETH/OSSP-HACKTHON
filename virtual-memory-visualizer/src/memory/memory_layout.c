#include <stdio.h>
int main(void){FILE*f=fopen("/proc/self/maps","r");if(!f){perror("maps");return 1;}char b[512];while(fgets(b,sizeof b,f))fputs(b,stdout);fclose(f);return 0;}