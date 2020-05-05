#include<iostream>
#include<vector>
using namespace std;
#define INF 99999999
void dijkstra(vector<vector<pair<int, int>>> g, int n, vector<int> &dist, vector<int> &p, int s, int e=-1) {
	dist = vector<int>(n, INF);
	dist[s] = 0;
	bool vis[n] = {false};
	p = vector<int>(n, -1);

	for(int i=0;i<n;i++) {
		int mind = INF, v = -1;
		for(int j=0;j<n;j++) {
			if(!vis[j] && (v == -1 || dist[j] < mind)) {
				v = j;
				mind = dist[j];
			}
		}
		vis[v] = true;
		for(auto edge: g[v]) {
			int to = edge.first, w = edge.second;
			if(!vis[to]) {
				int newd = dist[v] + w;
				if(newd < dist[to]) {
					dist[to] = newd;
					p[to] = v;
				}
			}
		}
		if(v == e)
			break;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>>	g(n);
	int u, v, w;
	for(int i=0;i<m;i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	vector<int> d, p;
	dijkstra(g, n, d, p, 0);
	cout << "Shortest distance array:\n";
	for(auto i: d)
		cout << i << " ";
	cout << "\nPredecessor array:\n";
	for(auto i: p)
		cout << i << " ";
	cout << "\n";
}
