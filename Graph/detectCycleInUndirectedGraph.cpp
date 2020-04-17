#include<iostream>
#include<map>
#include<set>
using namespace std;

bool dfs(map<int, set<int>> g, bool vis[], int u, int parent) {
	vis[u] = true;
	for(int v: g[u]) {
		if(vis[v] && parent != v)
			return true;
		else if(!vis[v] && dfs(g, vis, v, u))
			return true;
	}
	return false;
}

int main() {
	map<int, set<int>> g;
	int n, e, u, v;
	cin >> n >> e;
	for(int i=0;i<e;i++) {
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	bool cycle = false;
	bool vis[n] = {false};
	for(auto i: g) {
		if(!vis[i.first] && dfs(g, vis, i.first, -1)) {
			cycle = true;
			break;
		}
	}
	if(cycle)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}