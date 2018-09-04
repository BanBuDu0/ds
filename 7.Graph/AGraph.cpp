#include<iostream>
#include<queue>
using namespace std;

#define MaxSize 100
#define MaxNum 0x7fffffff

int visit[MaxSize]; //the visit array used in bfs, storage the visited node
int visit_DFS[MaxSize]; //the visit array used in dfs, storage the visited node


// arcnode : 弧形节点
typedef struct ArcNode{
    int vex;
    struct ArcNode *nextarc;
}ArcNode;


typedef struct{
    char data;
    ArcNode *firstarc;
}VexNode;


typedef struct{
    VexNode adjlist[MaxSize];
    int n, e; //n = vexnum e = arcnum
}Graph;


void Visit(Graph g, int v){
	printf("%c ", g.adjlist[v].data);
}

int FirstNeighbor(Graph g, int v){
	ArcNode *p = g.adjlist[v].firstarc;
	return p -> vex;

}

int NextNeighbor(Graph g, int v){
	 ArcNode *p = g.adjlist[v].firstarc -> nextarc;
	 if(p != NULL){
	 	return p->vex; 
	 }else{
	 	return -1;
	 }

}

void BFS(Graph g, int v){
	Visit(g, v);
	visit[v] = 1;
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		q.push();
		for(int i = FirstNeighbor(g, v); i >= 0; i = NextNeighbor(g, i)){
			if(visit[i] == 0){
				Visit(g, i);
				visit[i] = 1;
				q.push(i);	
			}
		}
	}
}

void BFSTraverse(Graph g){
	for(int i = 0; i < g.n; ++i){
		visit[i] = 0;
	}
	for(int i = 0; i < g.n; ++i){
		if(visit[i] == 0){
			BFS(g, i);
		}
	}
}


void DFS(Graph g, int v){
	Visit(g, v);
	visit_DFS[i] = 1;
	for(int i = FirstNeighbor(g, v); i >= 0; i = NextNeighbor(g, i)){
		if(visit[i] == 0){
			DFS(g, i);
		}
	}
}

void DFSTraverse(Graph g){
	for(int i = 0; i < g.n; ++i){
		visit_DFS[i] = 0;
	}
	for(int i = 0; i < g.n; ++i){
		if(visit_DFS[i] == 0){
			DFS(g, i);
		}
	}
}



int main(){
    // p = g.adjlist[3].firstarc->nextarc;//只有他爸是指针的时候才用 ->
    return 0;
}
