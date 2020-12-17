/**
 * Given an array of integers, return a new array such that
 * each element at index i of the new array is the product of
 * all the numbers in the original array except the one at i.
 * Assume the array has no zeroes
 * Input:
 * n
 * a1 a2 a3 ... an
 *
 * Follow-up: Don't use division
 */

#include<iostream>
#include<vector>
using namespace std;

vector<int> f1(vector<int> a) {
	int n = a.size();
	int p = 1;
	for(int i: a) p *= i; // may overflow
	vector<int> res(n);
	for(int i=0; i<n; i++) {
		res[i] = p / a[i];
	}
	return res;
}

// Without division
vector<int> f2(vector<int> a) {
	int n = a.size();
	vector<int> pref(n), suff(n);
	pref[0] = 1; suff[n-1] = 1;
	for(int i=1; i<n; i++) {
		pref[i] = pref[i-1] * a[i-1]; // may overflow
	}
	for(int i=n-2; i>=0; i--) {
		suff[i] = suff[i+1] * a[i+1]; // may overflow
	}
	vector<int> res(n);
	for(int i=0; i<n; i++) {
		res[i] = pref[i] * suff[i]; // may overflow
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];

	vector<int> v1, v2;
	v1 = f1(a);
	v2 = f2(a);

	for(int i: v1) cout << i << ' ';
	cout << '\n';
	for(int i: v2) cout << i << ' ';
	cout << '\n';
}

/**
 * Concern: Integer overflow
 */
