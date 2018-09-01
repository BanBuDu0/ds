#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef struct BTNode
{
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

void Visit(BTNode *p){
	printf("%c ", p->data);
	//cout << p->data << " ";
}

void preorder(BTNode *p){
	if(p != NULL){
		Visit(p);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(BTNode *p){
	if(p != NULL){
		inorder(p->lchild);
		Visit(p);
		inorder(p->rchild);
	}
}

void postorder(BTNode *p){
	if(p != NULL){
		postorder(p->lchild);
    	postorder(p->rchild);
		Visit(p);
    }
	
}

int op(int a, int b, char c){
	switch(c){
		case '+' : return a + b;
		case '*' : return a * b;
		case '-' : return a - b;
		case '/' : return a / b;
	}
}

int comp(BTNode *p){
	int a, b;
	if(p != NULL){
		if(p->lchild != NULL && p->rchild != NULL){
			a = comp(p->lchild);
			b = comp(p->rchild);
			return op(a, b, p->data);
		}else{
			return p->data - '0';
		}
	}else{
		return 0;
	}
}

int getDeepth(BTNode *p){
	int deepL, deepR;
	if(p == NULL){
		return 0;
	}else{
		deepL = getDeepth(p->lchild);
		deepR = getDeepth(p->rchild);
		return (deepL > deepR ? deepL : deepR) + 1;
	}

}
