#include<iostream>
using namespace std;

/* Upper Bound Function
 * Returns the least (first) index of the smallest element in the array strictly greater than key
 * If the key is greater than the maximum element of the array, it returns -1
 */
int upper_bound(int arr[], int lo, int hi, int key) {
	int mid, ans = hi+1;
	while(lo <= hi) {
		mid = lo + (hi-lo)/2;
		if(arr[mid] > key) {
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
	int ub = upper_bound(a, 0, n-1, k);
	if(ub != n)
		cout << a[ub] << " at position: " << ub << "\n";
	else
		cout << "Does not exist in this array\n";
	return 0;
}
