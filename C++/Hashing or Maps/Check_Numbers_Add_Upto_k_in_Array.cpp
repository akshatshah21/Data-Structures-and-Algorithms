/**
 * Given an array of numbers of size n and a number k,
 * return whether any two numbers from the list add up to k.
 * Input:
 * n k
 * a1 a2 a3...an
 */

#include<iostream>
#include<unordered_set>
using namespace std;

bool check(int a[], int n, int k) {
	unordered_set<int> s;
	for(int i=0; i<n; i++) {
		if(s.count(k-a[i])) return true;
		s.insert(a[i]);
	}
	return false;
}
int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	cout << (check(a, n, k) ? "YES" : "NO") << '\n';
}
