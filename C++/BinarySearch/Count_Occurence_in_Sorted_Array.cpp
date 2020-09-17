#include<iostream>
using namespace std;

int lower_bound(int arr[], int lo, int hi, int key) {
	int mid, ans = hi+1;
	while(lo <= hi) {
		mid = lo + (hi-lo) / 2;
		if(arr[mid] >= key) {
			ans = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	return ans;
}

int upper_bound(int arr[], int lo, int hi, int key) {
	int mid, ans = hi+1;
	while(lo <= hi) {
		mid = lo + (hi-lo) / 2;
		if(arr[mid] > key) {
			ans = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	return ans;
}

int count(int arr[], int low, int high, int key) {
	int lb = lower_bound(arr, low, high, key);
	int ub = upper_bound(arr, low, high, key);
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
	cout << count(a, 0, n-1, k) << endl;
	return 0;
}

