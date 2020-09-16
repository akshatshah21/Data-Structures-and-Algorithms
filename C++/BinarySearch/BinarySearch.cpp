#include<iostream>
using namespace std;
int binary_search(int a[], int lo, int hi, int key) {
	int mid;
	while(lo <= hi) {
		mid = lo + (hi-lo)/2;
		if(a[mid] == key)
			return mid;
		if(key < a[mid])	hi = mid-1;
		else	lo = mid + 1;
	}
	return -1;
}
int main() {
	int n;
	cout << "Enter number of numbers:";
	cin >> n;
	int arr[n];
	cout << "Enter numbers (sorted in ascending order):";
	for(int i=0;i<n;i++)	cin >> arr[i];
	int item;
	cout << "Enter value to be searched:";
	cin >> item;
	int pos = binary_search(arr, 0, n-1, item);
	if(pos != -1)
		cout << "Position: " << pos + 1 << "\n";
	else
		cout << "Not found\n";
	return 0;
}
