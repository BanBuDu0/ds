#include<iostream>
#include<stdlib.h>
using namespace std;

#define MaxSize 100

typedef struct OLNode{
	int row, col;
	struct OLNode * right, * down;
	float val;
}OLNode;

typedef struct{
	OLNode * rhead, * chead;
	int m, n, k;
}CrossList;

int creatcrossListmat(int A[][MaxSize], int m, int n, int k, CrossList &M){
	if(M.rhead){
		free(M.rhead);
	}
	if(M.chead){
		free(M.chead);
	}
	M.m = m;
	M.n = n;
	M.k = k;
/*
	if( ! ( M.rhead = (OLNode*)malloc(sizeof(OLNode) * m) ) ){
		return 0;
	}
	if( !( M.chead = (OLNode*)malloc(sizeof(OLNode) * n) ) ){
		return 0;
	}*/
	M.rhead = new OLNode[m];
	M.chead = new OLNode[n];
	for(int i = 0; i < m; ++i){
		M.rhead[i].right = NULL;
		M.rhead[i].down = NULL;
	}
	for(int i = 0; i < n; ++i){
		M.chead[i].right = NULL;
		M.chead[i].down = NULL;
	}
	OLNode *temp_r[MaxSize];
	for(int i = 0; i < n; ++i){
		temp_r[i] = &(M.chead[i]);
	}
	for(int i = 0; i < m; ++i){
		OLNode *c = &(M.rhead[i]);
		for(int j = 0; j < n; ++j){
			if(A[i][j] != 0){
			    OLNode *p = (OLNode *)malloc(sizeof(OLNode));
			    p->row = i;
			    p->col = j;
			    p->val = A[i][j];
			    p->right = NULL;
			    p->down = NULL;
			    c->right = p;
			    c = p;
			    temp_r[j]-> down = p;
			    temp_r[j] = p;
			}
		}
	}
	return 1;
}

//move the no ZERO elem to the head of the mat
void movement(int a[], int n){
	int j = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] != 0){
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			++j;
		}
	}
}

void maxRecursion(float a[], int n, int i){
    if(i == j){
        return a[i]; 
    }    
    if(){
        
    }
}

int main(int argc, char const *argv[]){
    CrossList m;
    int a[MaxSize][MaxSize];
    a[0][0] = 0;
    a[0][1] = 0;
    a[0][2] = 0;
    a[0][3] = 1;
    a[1][0] = 0;
    a[1][1] = 4;
    a[1][2] = 3;
    a[1][3] = 2;
    a[2][0] = 1;
    a[2][1] = 0;
    a[2][2] = 0;
    a[2][3] = 0;
    a[3][0] = 0;
    a[3][1] = 2;
    a[3][2] = 0;
    a[3][3] = 0;
    creatcrossListmat(a, 4, 4, 5, m);
	for(int i = 0; i < 4; ++i){
	    while((m.rhead[i]).right != NULL){
	        cout << (m.rhead[i]).right->val<< endl;
	        m.rhead[i] = *(m.rhead[i].right);
	    }
    }
    cout <<endl;
    for(int i = 0; i < 4; ++i){
	    while(m.chead[i].down != NULL){
	        cout << m.chead[i].down->val<< endl;
	        m.chead[i] = *(m.chead[i].down);
	    }
    }

	return 0;
}
