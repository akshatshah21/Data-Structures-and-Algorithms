#include<iostream>
#include<vector>
using namespace std;

// Disclaimer: This is not the solution at GFG.
// It is from CP-Algorithms: https://cp-algorithms.com/graph/finding-cycle.html
// This same logic can also be used for undirected graphs, with special condition for edge to parent.

/* vis[i] = 0, if node i is unvisited
 * vis[i] = 1, if node i is currently on the recursion stack
 * vis[i] = 2, if node i has been visited in some previous recursion
 */

bool dfs(vector<int> adj[], short vis[], int node) {
	vis[node] = 1; // add to set of nodes on recursion stack
	for(int i: adj[node]) {
		if(vis[i] == 0 && dfs(adj, vis, i))
			return true;
		else if(vis[i] == 1)
			return true;
		// do nothing if vis[i] == 2
	}
	vis[node] = 2; // remove from set of nodes on recursion stack
	return false;
}

int main() {
	// Input
	int n, e;
	cin >> n >> e;
	vector<int> adj[n]; // adj list
	int u, v;
	for(int i=0;i<e;i++) {
		cin >> u >> v;
		adj[u].insert(v);
	}
	// End of input

	short vis[n] = {0};
	bool cycle = false;
	for(int i=0;i<n;i++) {
		if(vis == 0 && dfs(adj, vis, i)) {
			cycle = true;
			break;
		}
	}
	cout << (cycle ? "Cycle exists" : "Cycle does not exist") << '\n';
}
