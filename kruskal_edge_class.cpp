#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_NODES 20
vector<int> djarr;
class Edge {
public:
	int src, dest, weight;
	Edge(int src, int dest, int weight) {
		this -> src = src;
		this -> dest = dest;
		this -> weight = weight;
	}
	Edge() {}
};
bool sort_edge(Edge e1, Edge e2) {
	return e1.weight < e2.weight;
}

void do_union(int x, int y) {
	if(x < y)	swap(x,y);
	int temp = djarr[x];
	for(int i=0;i<djarr.size();i++) {
		if(djarr[i] == temp)	djarr[i] = djarr[y];
	}
}
int find(int x, int y) {
	return djarr[x] == djarr[y] ? true : false;
}
bool comp(pair<pair<int, int>, int> e1, pair<pair<int, int>, int> e2) {
	return e1.second < e2.second;
}
int main() {
	int v;
 	cout << "Enter number of nodes:";
	cin >> v;
	for(int i=0;i<=v;i++) { // <= v for it to work with first node as 0 or 1
		djarr.push_back(i);
	}
	int n;
 	cout << "Enter number of edges:";
	cin >> n;
	Edge graph[n];
	int v1, v2, weight;
	for(int i=0; i<n; i++) {
		cin >> v1 >> v2 >> weight;
		graph[i] = Edge(v1, v2, weight);
		
	}
	sort(graph, graph+n, sort_edge);
	int min_cost = 0;
	Edge mst[v-1];
	int count = 0;
	for(int i=0; i<n; i++) {
		if(!find(graph[i].src, graph[i].dest)) { 
			do_union(graph[i].src, graph[i].dest);
			min_cost += graph[i].weight;
			mst[count++] = Edge(graph[i].src, graph[i].dest, graph[i].weight);
		}
	}
	cout << min_cost << endl;
 	cout << "N1 N2 Weight\n";
 	for(int i=0;i<v-1;i++) {
 		cout << mst[i].src << ' ' << mst[i].dest << ' ' << mst[i].weight << endl;
 	}
	return 0;
}