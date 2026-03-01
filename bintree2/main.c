#include <stdio.h>
#include "mydata.h"
#include "bintree.h"

int main(void){
	binnode* root=NULL;
	mydata *temp;
	
	temp=create_data(1,"Yamada");
	root=add(root,temp);
	
	temp=create_data(5,"Suzuki");
	root=add(root,temp);
	
	temp=create_data(2,"Tanaka");
	root=add(root,temp);
	
	temp=create_data(4,"Sato");
	root=add(root,temp);
	
		temp=create_data(8,"Yamamoto");
	root=add(root,temp);
	
	printtree(root);
}