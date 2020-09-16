#include<iostream>
using namespace std;

// Works for distinct elements only
int rotation_point(int a[], int lo, int hi) {
	if(a[lo] < a[hi])
		return lo;
	int mid;
	while(lo < hi) {
		cout << lo << " " << hi << endl;
		mid = lo + (hi-lo)/2;
		if(a[mid] > a[hi])
			lo = mid+1;
		else
			hi = mid; // NOTE!
	}
	return lo;
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << rotation_point(a, 0, n-1) << "\n";
	return 0;
}
