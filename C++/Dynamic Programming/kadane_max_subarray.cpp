#include<iostream>
using namespace std;

int max(int a, int b) {
	if(a >= b)
		return a;
	return b;
}

int kadane(int a[], int n) {
	int max_global = a[0];
	int max_ending_here = a[0];
	for(int i=1;i<n;i++) {
		/* The main logic behind Kadane's algorithm:
		 * If we are at index i, and we have computed the maximum sum subarray
		 * till (and including) index i-1, say [M] then the maximum sum subarray 
		 * till (and including) index i is one out of [M, a[i]] and [a[i]]
		 */
		max_ending_here = max(max_ending_here + a[i], a[i]);
		max_global = max(max_global, max_ending_here);
	}
	return max_global;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << kadane(a, n) << "\n";
	return 0;
}
