#include<iostream>
#include<queue>
#include<map>
#include<set>
using namespace std;

void bfs(map<int, set<int>> graph, int start, int nodes) {
	bool visited[nodes]={0};
	queue<int> q;
	q.push(start);
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		visited[curr] = true;
		cout << curr << ' ';
		for(auto neighbor: graph[curr])
			if(!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
	}		
}

int main() {
	int n; // Nodes
	cin >> n;
	int e; // Edges
	cin >> e;
	map<int, set<int>> graph;
	int u, v;
	for(int i=0;i<e;i++) {
		cin >> u >> v;
		graph[u].insert(v);
	}
	bfs(graph, 0, n);
	cout << "\n";

	return 0;
}

