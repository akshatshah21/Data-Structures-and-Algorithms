#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<int> adj[], bool vis[], int node, int parent) {
	vis[node] = true;
	for(int i: adj[node]) {
		if(i == parent)
			continue;
		if(vis[i] || dfs(adj, vis, i, node))
			return true;
	}
	return false;
}

int main() {

	// Input
	int n, e, u, v;
	cin >> n >> e;
	vector<int> adj[];
	for(int i=0;i<e;i++) {
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u); // since undirected
	}
	// End of Input
	
	bool cycle = false;
	bool vis[n] = {0};
	for(int i=0;i<n;i++) {
		if(!vis[i] && dfs(g, vis, i, -1)) {
			cycle = true;
			break;
		}
	}
	cout << (cycle ? "Cycle exists" : "Cycle does not exist") << '\n';
	return 0;
}
