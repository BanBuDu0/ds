#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

#define MaxSize 100

typedef struct TBTNode
{
	char data;
    int ltag, rtag;
	struct BTNode *lchild;
	struct BTNode *rchild;
}TBTNode;


void Visit(TBTNode *p){
	printf("%c ", p->data);
	//cout << p->data << " ";
}


void InThread(TBTNode *p, TBTNode *&pre){
    if(p != NULL){
        InThread(p -> lchild, pre);
        if(p -> lchild == NULL){
            p -> lchild = pre;
            p -> ltag = 1;
        }
        if( pre != NULL && pre -> rchild == NULL){
            pre -> rchild = p;
            pre -> rtag = 1;
        }
        pre = p;
        InThread(p -> rchild, pre);
    }
}

TBTNode *InThreadFirst(TBTNode *p){
    while(p -> ltag == 0){
        p = p -> lchild;
    }
    return p;
}

TBTNode *Next(TBTNode *p){
    //如果有右孩子，则后继为右子树最左边的节点
    if(p -> rtag == 0){
        return InThreadFirst(p -> rchild); 
    }else{
        //直接返回后继
        return p -> rchild;
    }
}

//p is the root node
void InOrder(TBTNode *p){
    for(TBTNode * q = InThreadFirst(p); q != NULL; q = Next(q)){
        Visit(q);
    }
}

int main(){
    return 0;
}