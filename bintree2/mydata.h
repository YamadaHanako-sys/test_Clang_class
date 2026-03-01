#ifndef __mydata
#define __mydata
typedef struct{
int no;
char name[20];
}mydata;

mydata* create_data(int no,char* name);
int mydata_no_cmp(const mydata*x,const mydata*y);
void print_mydata(const mydata* x);
void println_mydata(const mydata* x);

#endif