#include <stdio.h>
#include <stdlib.h>
#include "mydata.h"
#include "bintree.h"

static binnode* alloc_bin_node(void)
{
	return calloc(1,sizeof(binnode));
}
static void set_bin_node(binnode *n, const mydata *x,const binnode *left,const binnode* right)
{
	n->data = *x;
	n->left = left;
	n->right = right;
}

binnode* add(binnode* p,const mydata* x)
{
	int cond;
	
	if(p==NULL){
		p=alloc_bin_node();
		set_bin_node(p,x,NULL,NULL);
	}else if((cond=mydata_no_cmp(x,&p->data))==0)
		printf("Error %d is already registerd.\n",x->no);
	else if (cond <0)
		p->left=add(p->left,x);
	else
		p->right=add(p->right,x);
	return p;
}

void printtree(const binnode* p)
{
	if(p!=NULL){
		println_mydata(&p->data);
		printf("left node of %d:\n",(&p->data)->no);
		printtree(p->left);
		printf("right node of %d:\n", (&p->data)->no);
		printtree(p->right);
		printf("right node of %d end:\n", (&p->data)->no);
}
}


int remove_node(binnode **root, const mydata *x) {
	binnode **p = root;
	binnode *temp, *next;
	binnode **min, **left;

	while (1) {
		int cond;
		if (*p == NULL) {
			printf("Error: %d is not registered\n", x->no);
			return -1;
		}else if((cond = mydata_no_cmp(x, &(*p)->data))==0){
			break;
		}else if (cond < 0){
			p = &((*p)->left);
		}else{
			p = &((*p)->right);
		}
	}

	if ((*p)->left == NULL && (*p)->right == NULL) {
		temp = *p;
		*p = NULL;
		free(temp);
	}else if ((*p)->left == NULL){
		next = (*p)->right;
		temp = *p;
		*p = next;
		free(temp);
	}else if ((*p)->right == NULL){
		next = (*p)->left;
		temp = *p;
		*p = next;
		free(temp);
	}else{
		if ((*p)->left == NULL) {
			next = (*p)->right;
		}else{
			binnode **leftPtr = &((*p)->left);
			while ((*leftPtr)->right != NULL) {
				leftPtr = &((*leftPtr)->right);
			}
			next = *leftPtr;
			*leftPtr = (*leftPtr)->left;
		}
		temp = *p;
		*p = next;
		free(temp);
	}

	return 0;
}

