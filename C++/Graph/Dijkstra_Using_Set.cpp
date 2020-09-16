#include<iostream>
#include<vector>
#include<set>
#define INF 1e9
using namespace std;
void dijkstra(vector<vector<pair<int, int>>> adj, int s, vector<int> &d, vector<int> &p, int e=-1) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);
	d[s] = 0;
	set<pair<int, int>> q; // <dist, index>
	q.insert({0, s});
	while(!q.empty()) {
		int v = q.begin() -> second;
		q.erase(q.begin());
		for(pair<int, int> edge: adj[v]) {
			int to = edge.first, w = edge.second;
			if(d[to] > d[v] + w) {
				q.erase({d[to], to});
				d[to] = d[v]+w;
				p[to] = v;
				q.insert({d[to], to});
			}
		}
		if(v == e)
			break;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	int u, v, w;
	for(int i=0;i<m;i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		// If undirected,
		// adj[v].push_back({u, w});
	}
	vector<int> d, p;
	dijkstra(adj, 0, d, p);
	cout << "Dist: ";
	for(auto i: d)	cout << i << " ";
	cout << "\n";
	for(auto i: p)	cout << i << " ";
	cout << "\n";
}
