#include <iostream>
#include <vector>
using namespace std;

// DSU with path compression and union by size

class DSU {
	vector<int> parent, size;
  public:
	DSU(int n) {
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}
	DSU() {}
	int root(int u) {
		if (parent[u] == u) return u;
		return parent[u] = root(parent[u]);
	}
	void union_sets(int u, int v) {
		int u_root = root(u);
		int v_root = root(v);
		if (u_root != v_root) {
			if (size[u_root] < size[v_root]) {
				swap(u_root, v_root);
			}
			parent[v_root] = u_root;
			size[u_root] += size[v_root];
		}
	}
};
