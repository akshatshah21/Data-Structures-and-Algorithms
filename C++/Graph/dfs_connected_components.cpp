#include<iostream>
#include<map>
#include<set>
using namespace std;

// Augmented Depth First Search to color nodes according to the component they belong to using count and component array
void dfs_aug(map<int, set<int>> g, bool visited[], int &count, int component[], int node) {
	visited[node] = true;
	component[node] = count;
	for(int neighbor: g[node])
		if(!visited[neighbor])
			dfs_aug(g, visited, count, component, neighbor);
}

// Function to return number of connected components in a graph
int findConnectedComponents(map<int, set<int>> g, int component[]) {
	bool visited[g.size()] = {0};
	int count = 0;
	for(auto node: g)
		if(!visited[node.first]) {
			count++;
			dfs_aug(g, visited, count, component, node.first);
		}
	return count;
}

// Utility function to construct an adjacency list of the graph based on input
void graphInput(map<int, set<int>> &g) {
	int n, e, u, v;
	cin >> n >> e;
	for(int i=0;i<e;i++) {
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}

}
int main() {
	map<int, set<int>> g;
	graphInput(g);
	// component[i] stores component number to which node i belongs
	int component[g.size()];
	cout << "Number of connected components: " << findConnectedComponents(g, component) << '\n';
	if(g.size()) {
		cout << "Component array:\n";
		for(auto node: g)
			cout << component[node.first] << ": " << node.first << "\n";
	}	
	return 0;
}

