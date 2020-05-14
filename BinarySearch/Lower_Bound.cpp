#include<iostream>
using namespace std;
/* Lower Bound function
 * Returns the least (first) index of the largest element <= key, in the array from [start, end)
 * If key is smaller than smallest element, it returns -1
 */
int lower_bound(int arr[], int start, int end, int key) {
	int lo = start, hi = end, mid;
	while(lo < hi) {
		mid = lo + (hi-lo)/2;
		if(arr[mid] >= key)
			hi = mid;
		else
			lo = mid+1;
	}
	if(lo == end || (lo == start && arr[lo] > key))
		lo--;
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
	cout << lower_bound(a, 0, n, k) << endl;
	return 0;
}

