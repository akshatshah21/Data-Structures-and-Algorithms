#include<iostream>
#include<set>
#include<map>
#include<unordered_map>
using namespace std;

bool dfs(map<int, set<int, greater<int>>> g, int ordering[], int &pos, bool vis[], int node, unordered_map<int, bool> recurStack) {
	if(recurStack.count(node)) {
		return false;
	}
	recurStack[node] = true;
	for(int neighbor: g[node]) {
		if(!vis[neighbor-1])
			if(recurStack.count(neighbor) || !dfs(g, ordering, pos, vis, neighbor, recurStack))
				return false;
	}
	vis[node-1] = true;

	ordering[pos--] = node;
	return true;
}

bool solve(int n, map<int, set<int, greater<int>>> g, int ordering[]) {
	bool vis[n] = {0};
	int pos = n-1;
	
	for(int i=n;i>0;i--) {
		if(!vis[i-1]) {
			unordered_map<int, bool> recurStack;
			if(!dfs(g, ordering, pos, vis, i, recurStack))
				return false;
		}
	}
	return true;
}


int main() {
	map<int, set<int, greater<int>>> graph;
	int n, e;
	scanf("%d %d", &n, &e);
	int u, v;
	for(int i=0;i<e;i++) {
		scanf("%d %d", &u, &v);
		graph[u].insert(v);
	}

	int ordering[n] = {0};
	bool result = solve(n, graph, ordering);
	if(result)
		for(int i=0;i<n;i++)
			cout << ordering[i] << ' ';
	else
		cout << "The graph has a cycle!";
	cout << "\n";
}
