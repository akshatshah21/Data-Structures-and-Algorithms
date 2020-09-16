#include<iostream>
#include<map>
#include<set>
using namespace std;

void dfs(map<int, set<int>> graph, int node, bool visited[]) {
	visited[node] = true;
	cout << node << " ";
	for(auto neighbor: graph[node])
		if(!visited[neighbor])
			dfs(graph, neighbor, visited);
}

int main() {
	map<int, set<int>> graph;
	int n; // Number of nodes
	cin >> n;
	int e; // Number of edges
	cin >> e;
	int u, v;
	for(int i=0;i<e;i++) {
		cin >> u >> v;
		graph[u].insert(v);
	}
	bool visited[n] = {0};
	dfs(graph, 0, visited);
	cout << "\n";
	return 0;
}

