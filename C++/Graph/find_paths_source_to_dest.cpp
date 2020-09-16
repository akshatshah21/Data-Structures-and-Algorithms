#include<iostream>
#include<vector>
using namespace std;

void dfs(const vector<vector<int>> &g, int node, int d, bool vis[], vector<int> &path) {
	if(node == d) {
		for(int i: path)
			cout << i << " ";
		cout << node << "\n";
		return;
	}
	vis[node] = true;
	path.emplace_back(node);
	for(int i: g[node])
		if(!vis[i])
			dfs(g, i, node, vis, path);
	path.pop_back();
	vis[node] = false;
}

int main() {
	int n, m, s, d, u, v;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for(int i=0;i<m;i++) {
		cin >> u >> v;
		g[u].emplace_back(v);
	}
	cin >> s >> d;
	bool vis[n] = {0};
	vector<int> path;
	dfs(g, s, d, vis, path);
}

