#include<iostream>
using namespace std;
/* Lower Bound function
 * Returns the least (first) index of an element >= key, in the array from [start, end]
 * If key is larger than the max element, it returns n
 */
int lower_bound(int arr[], int lo, int hi, int key) {
	int mid, ans = hi+1;
	while(lo <= hi) {
		mid = lo + (hi-lo)/2;
		if(arr[mid] >= key) {
			ans = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	return ans;
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
	int lb = lower_bound(a, 0, n-1, k);
	if(lb != n)
		cout << lb << "\n";
	else
		cout << "Does not exist in the array\n";
	return 0;
}

