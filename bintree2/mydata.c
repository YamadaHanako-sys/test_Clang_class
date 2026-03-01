#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mydata.h"

mydata* create_data(int no,char* name)
{
mydata* tmp=(mydata*)calloc(1,sizeof(mydata));
tmp->no=no;
strcpy(tmp->name,name);
return tmp;
}

int mydata_no_cmp(const mydata*x,const mydata *y){
	return x->no < y->no ? -1: x->no > y->no ? 1 : 0;
}

void print_mydata(const mydata* x){
	printf("%d %s",x->no,x->name);
}

void println_mydata(const mydata* x){
	printf("%d %s\n",x->no,x->name);
}