#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_NODES 20
vector<int> djarr;
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
	for(int i=0;i<v;i++) {
		djarr.push_back(i);
	}	
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
	int min_cost = 0;
	vector<pair<pair<int, int>, int>> mst;
	for(int i=0; i<n; i++) {
		if(!find(graph[i].first.first, graph[i].first.second)) { 
			do_union(graph[i].first.first, graph[i].first.second);
			min_cost += graph[i].second;
			mst.push_back({{graph[i].first.first, graph[i].first.second}, graph[i].second});
		}
	}
	cout << min_cost << endl;
	cout << "N1 N2 Weight\n";
	for(int i=0;i<mst.size();i++) {
		cout << mst[i].first.first << ' ' << mst[i].first.second << ' ' << mst[i].second << endl;
	}
	return 0;
}
