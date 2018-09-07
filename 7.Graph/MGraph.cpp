#include<iostream>
using namespace std;

#define MaxSize 100
#define MaxNum 0x7fffffff

typedef struct{
    int edge[MaxSize][MaxSize];
    int vexnum, arcnum;
}MGraph;


/*
 *dist存储最短路径
 *set存储已经求得最短路径的节点
 */
void Dijkstra(MGraph g, int v, int dist[]){
	int set[MaxSize];
	for(int i = 0; i < g.vexnum; ++i){
		set[i] = 0;
		dist[i] = g.edge[v][i];
	}
	set[v] = 1;
	int min = MaxNum;
	int u; // 记录节点最短路径节点
	//找到当前树到剩余节点的最短路径
	for(int i = 0; i < g.vexnum - 1; ++i){
		if(dist[i] < m && set[i] == 0){
			min = dist[i];
		    u = i;
		}
	}
	set[u] = 1;
	//更新加入新节点之后的最短路径表
	for(int i = 0 ; i < g.vexnum; ++i){
		if((dist[u] + g.edge[u][i] < dist[i]) && set[i] == 0){
			dist[i] = dist[u] + g.edge[u][i];
		}
	}
}

int main(int argc, char const *argv[])
{
	return 0;
}