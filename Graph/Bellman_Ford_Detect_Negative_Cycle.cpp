#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e9;
int max(int a, int b) {
	if(a >= b)	return a;
	return b;
}

struct Edge {
	int from, to, w;
};
void bellman_ford(vector<Edge> edges, int n, int m, int s) {
	vector<int> d(n, INF);
	vector<int> p(n, -1);
	d[s] = 0;
	int x = -1;
	for(int i=0;i<n;i++) {
		x = -1;
		for(int j=0;j<m;j++) {
			if(d[edges[j].from] < INF) {
				if(d[edges[j].to] > d[edges[j].from] + edges[j].w) {
					d[edges[j].to] = max(-INF, d[edges[j].from] + edges[j].w);
					p[edges[j].to] = edges[j].from;
					x = edges[j].to;
				}
			}
		}
	}
	if(x != -1) {
		// Negative cycle detected
		int y = x;
		for(int i=0;i<n;i++)
			y = p[y];
		vector<int> ncycle;
		for(int curr = y; ;curr = p[curr]) {
			ncycle.push_back(curr);
			if((curr = y) && (ncycle.size() > 1))
				break;
		}
		cout << "Negative cycle:";
		for(auto i: ncycle)
			cout << i << " ";
		cout << "\n";
	}
	else {
		// No negative cycle
		cout << "Distance from " << s << ": ";
		for(auto i: d)	cout << i << " ";
		cout << "\nPredecessor array: ";
		for(auto i: p)	cout << i << " ";
		cout << "\n";
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<Edge> edges;
	Edge e;
	for(int i=0;i<m;i++) {
		cin >> e.from >> e.to >> e.w;
		edges.push_back(e);
		// If undirected,
		// swap(e.to, e.from);
		// edges.push_back(e);
	}
	bellman_ford(edges, n, m, 0);
}
