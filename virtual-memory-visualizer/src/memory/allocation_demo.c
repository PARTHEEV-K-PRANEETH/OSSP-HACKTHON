#include <stdio.h>
#include <stdlib.h>
int main(void){int*p=malloc(4*sizeof *p);if(!p)return 1;for(int i=0;i<4;i++)p[i]=i;int*z=calloc(4,sizeof *z);if(!z){free(p);return 1;}int*q=realloc(p,8*sizeof *p);if(!q){free(p);free(z);return 1;}p=q;p[4]=44;printf("realloc p[4]=%d calloc z[0]=%d\\n",p[4],z[0]);free(p);free(z);return 0;}