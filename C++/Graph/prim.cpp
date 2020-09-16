#include<iostream>
using namespace std;
#define V 5
int minDist(int dist[], bool mstSet[]) {
	int min = 999999;
	int min_index;
	for(int i=0;i<V;i++)
		if(!mstSet[i] && dist[i] < min)
			min = dist[i], min_index = i;
	return min_index;
}
void printMST(int parent[], int graph[V][V]) {
	cout << "Edge\tWeight\n";
	for(int i=1;i<V;i++)
		cout << parent[i] << '-' << i << '\t' << graph[i][parent[i]] << endl;
}
int prim(int graph[V][V]) {
	int parent[V], dist[V];
	bool mstSet[V] = {0};
	for(int i=0;i<V;i++)	dist[i] = 999999;
	dist[0] = 0;
	parent[0] = -1;
	for(int e=0;e<V-1;e++) {
		int u = minDist(dist, mstSet);
		mstSet[u] = true;
		for(int v=0;v<V;v++)
			if(!mstSet[v] && graph[u][v] && graph[u][v] < dist[v])
				parent[v] = u, dist[v] = graph[u][v];
	}
	printMST(parent, graph);
}
int main() {
	int graph[V][V] = { { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } };  
    prim(graph);
    return 0;
}