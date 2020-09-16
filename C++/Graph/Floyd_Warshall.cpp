#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e7;

/* Floyd Warshall Algorithm: All Pairs Shortest Paths
 * Parameters:
 * 	d: n x n matrix of shortest distances
 * 	next: n x n matrix to keep track of next node in shortest path from i to j
 * 	n: Number of nodes
 * Returns:
 * 	ncycle: boolean value indicating whether a negative cycle exists or not
 * 	d (passed by reference)
 * 	next (passed by reference
 */
bool floyd_warshall(vector<vector<int>> &d, vector<vector<int>> &next, int n) {
	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(d[i][k] < INF && d[k][j] < INF && d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = max(-INF, d[i][k] + d[k][j]);
					next[i][j] = next[i][k];
				}
			}
		}
	}
	bool ncycle = false;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int t=0;t<n;t++) {
				if(d[t][t] < 0 && d[i][t] < INF && d[t][j] < INF) {
					ncycle = true;
					d[i][j] = -INF;
					next[i][j] = -1;
				}
			}
		}
	}
	return ncycle;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n), next(n);
	for(int i=0;i<n;i++) {
		adj[i].assign(n, INF);
		next[i].assign(n, -1);
		adj[i][i] = 0;
	}
	int u, v, w;
	for(int i=0;i<m;i++) {
		cin >> u >> v >> w;
		adj[u][v] = w;
		next[u][v] = v;
		// If undirected:
		// adj[v][u] = w;
		// next[v][u] = u;
	}
	vector<vector<int>> d = adj;
	bool ncycle = floyd_warshall(d, next, n);
	cout << "Distance matrix:\n";
	for(auto i: d) {
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	if(ncycle)
		cout << "Negative cycle exists!\n";
	else {
		cout << "No negative cycle\n";
		cout << "Shortest distance from 0 to n-1: " << d[0][n-1] << "\n";;
		int at = 0;
		for(;at != n-1;at = next[at][n-1])
			cout << at << " ";
		cout << n-1 << "\n";
	}
	
}
