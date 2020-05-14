#include<iostream>
using namespace std;

/* Upper Bound Function
 * Returns the least (first) index of the smallest element in the array strictly greater than key
 * If the key is greater than the maximum element of the array, it returns end
 * If the key is lesser than the minimum element of the arrat, it returns start
 */
int upper_bound(int arr[], int start, int end, int key) {
	int lo = start, hi = end, mid;
	while(lo < hi) {
		mid = lo + (hi-lo)/2;
		if(arr[mid] <= key)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
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
	cout << upper_bound(a, 0, n, k) << endl;
	return 0;
}
