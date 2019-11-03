#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_NODES 20
int djarr[MAX_NODES];

int do_union(int x, int y) {
	if(x < y)	swap(x,y);
	int temp = djarr[x];
	// search for all temp, replace with djarr[y]
}

int find(int x, int y) {
	return djarr[x] == djarr[y] ? true : false;
}

bool comp(pair<pair<int, int>, int> e1, pair<pair<int, int>, int> e2) {
	return e1.second > e2.second;
}

int main() {
	int n;
	cout << "Enter number of edges:";
	cin >> n;
	vector<pair<pair<int, int>, int>> graph;
	int v1, v2, weight;
	for(int i=0; i<n; i++) {
		cin >> v1 >> v2 >> weight;
		graph.push_back({{v1, v2}, weight});
	}
	sort(graph.begin(), graph.end(), comp);

	vector<pair<pair<int, int>, int>> mst;
	for(int i=0; i<n; i++) {
		if(!find(graph[i].first.first, graph[i].first.second)) {
			do_union(graph[i].first.first, graph[i].first.second);
			min_cost += graph[i].second;
		}
	}

	cout << min_cost << endl;
	// Print mst
}