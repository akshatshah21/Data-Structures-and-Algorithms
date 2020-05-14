#include<iostream>
using namespace std;

int lower_bound(int arr[], int low, int high, int key) {
	int mid;
	int lo = low, hi = high;
	while(lo < hi) {
		mid = lo + (hi-lo) / 2;
		if(arr[mid] >= key)
			hi = mid;
		else
			lo = mid+1;
	}
	if(lo == high || (lo == low && arr[lo] > key))
		lo--;
	return lo;
}

int upper_bound(int arr[], int lo, int hi, int key) {
	int mid;
	while(lo < hi) {
		mid = lo + (hi-lo) / 2;
		if(arr[mid] <= key)
			lo = mid+1;
		else
			hi = mid;
	}
	return lo;
}

int count(int arr[], int low, int high, int key) {
	int lb = lower_bound(arr, low, high, key);
	int ub = upper_bound(arr, low, high, key);

	if(lb == -1 || (ub == high && arr[high-1] != key))
		return 0;
	return ub-lb;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cout << i << " ";
	cout << endl;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int k;
	cin >> k;
	cout << count(a, 0, n, k) << endl;
	return 0;
}

