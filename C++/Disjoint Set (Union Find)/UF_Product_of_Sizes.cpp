/* Question link(HackerEarth): https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/teachers-dilemma-3/	*/
#include<bits/stdc++.h>
using namespace std;
#define fastio(); ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define ull unsigned long long

class UF {
    public:
    int *size, *parent;
    set <int> roots;
    UF(int n) {
        size = new int[n+1];
        parent = new int[n+1];
        for(int i=1;i<=n;i++) {
            size[i] = 1;
            parent[i] = i;
            roots.insert(i);
        }
    }
    int root(int p) {
        int i = p;
        while(i != parent[i]) {
            i = parent[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void do_union(int p, int q) {
        int proot = root(p);
        int qroot = root(q);
        if(size[proot] < size[qroot]) {
            swap(p,q);
            swap(proot, qroot);
        }
        int next;
        parent[qroot] = proot;
        while(q != qroot) {
            next = parent[q];
            parent[q] = proot;
            q = next;
        }
        size[proot] += size[qroot];
        roots.erase(qroot);
    }
    int f() {
        ll ans = 1;
        for(auto i:roots) {
            ans = (ans*size[i]) % 1000000007;
        }
        return ans;
    }
};

int main() {
    fastio();
    int n,m;
    cin >> n >> m;
    UF uf(n);
    int a, b;
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        if(!uf.find(a, b))
            uf.do_union(a, b);
    }
    cout << uf.f() << endl;
    return 0;
}