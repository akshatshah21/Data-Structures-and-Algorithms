#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool is_bipartite(vector<int> adj[], int n) {
	vector<int> color(n, -1);
	queue<int> q;
	int curr;
	for(int i=0;i<n;i++) {
		if(color[i] == -1) {
			color[i] = 0;
			q.push(i);
			while(!q.empty()) {
				curr = q.front();
				q.pop();
				for(int j: adj[curr]) {
					if(color[j] == -1) {
						color[j] = color[curr] ^ 1;
						q.push(j);
					} else if(color[j] == color[curr])
						return false;
					// do nothing if neighbour coloured with diff colour
				}
			}
		}
	}
	return true;
}

int main() {
	int n, m, u, v;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i=0;i<m;i++) {
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u); // undirected
	}
	cout << (is_bipartite(adj, n) ? "YES" : "NO") << '\n';
}
