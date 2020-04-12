// Kahn's algorithm for the topological ordering of a DAG


// This works for the SPOJ TOPSORT problem. Just take care of 1-based nodes input.
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<set>
using namespace std;

// Prints the lexicographically smallest topological ordering of the nodes in input graph, if possible. Else, Sandro fails.
void kahn(vector<vector<int>> g, int N) {
	// Compute indegree of all nodes
	int indeg[N] = {0};
	for(auto u: g) {
		for(auto v: u)
			indeg[v]++;
	}

	// Priority Queue (min-heap) for lexicographically smallest ordering
	priority_queue<int, vector<int>, greater<int>> q;
	// Enqueue all nodes with indegree 0
	for(int i=0;i<N;i++) {
		if(indeg[i] == 0)
			q.push(i);
	}

	int count = 0;
	vector<int> topo;
	while(!q.empty()) {
		int u = q.top();
		q.pop();
		topo.push_back(u);
		count++;

		for(auto v: g[u]) {
			indeg[v]--;
			if(indeg[v] == 0)
				q.push(v);
		}
	}

	if(count != N) {
		cout << "This graph is not acyclic\n";
	}
	else {
		for(auto u:topo)
			cout << u << " ";
		cout << "\n";
	}
}

int main() {
	int N, E;
	cin >> N >> E;
	vector<vector<int>> g(N);
	int u, v;
	for(int i=0;i<E;i++) {
		cin >> u >> v;
		g[u].push_back(v);
	}
	kahn(g, N);
	return 0;
}
