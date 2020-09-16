/* Question link(HackerEarth): https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/count-friends/ */

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define ull unsigned long long
class UF {
    public:
    int parent[100001];
    int size[100001];
    UF() {
        for(int i=0;i<=100000;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int root(int x) {
        int i = x;
        while(i != parent[i]) 
            i = parent[i];
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
        while(q != qroot) {
            next = parent[q];
            parent[q] = proot;
            q = next;
        }
        parent[qroot] = proot;
        size[proot] += size[qroot];
    }
    int count(int p) {  // count number of friends
        return size[root(p)] - 1;
    }
};
int main() {
    fastio();
    int n, m;
    cin >> n >> m;
    UF uf;
    int a,b;
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        if(!uf.find(a,b))  uf.do_union(a,b);
    }
    for(int i=0;i<n;i++) {
        cout << uf.count(i+1) << ' ';
    }
    cout << endl;
    return 0;
}