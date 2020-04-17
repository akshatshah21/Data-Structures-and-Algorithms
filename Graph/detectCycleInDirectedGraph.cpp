#include<iostream>
#include<set>
#include<map>
using namespace std;


// Depth first search augmented to keep track of nodes in recursion stack
/*
 * Params:
 * g: adjacency list of graph
 * vis[]: boolean array to keep track of visited nodes. In this case, it is required to keep track of visited components(see main)
 * u: current node
 * recurStack: set, not a stack, to keep track of nodes in current recursion stack of dfs(). If a current node u is already in recursion stack, cycle exists and found
*/

bool dfs(map<int, set<int>> g, bool vis[], int u, set<int> recurStack) {
	if(recurStack.count(u))
		return true;
	recurStack.insert(u);
	for(int v: g[u]) {
		if(!vis[v] && dfs(g, vis, v, recurStack))
			return true;
	}
	vis[u] = true;
	// Note that we're marking vis here, AFTER all the recursive calls.
	// This is important as if we marked it before the for loop, then the condition
	// in the if statement wouldn't be true even if cycle existed, since !vis[v] would be false.
	// For a simple example, consider a self loop, or even a loop of two nodes.
	return false;
}


int main() {
	map<int, set<int>> g; // adj list
	// Input
	int n, e;
	cin >> n >> e;
	int u, v;
	for(int i=0;i<e;i++) {
		cin >> u >> v;
		g[u].insert(v);
	}
	// End of input

	bool vis[n] = {0};
	bool cycle = false;
	for(auto i: g) {
		if(!vis[i.first]) {
			set<int> recurStack;
			if(dfs(g, vis, i.first, recurStack)) {
				cycle = true;
				break;
			}
		}
	}
	if(cycle)
		cout << "YES\n";
	else
		cout << "NO\n";
}
