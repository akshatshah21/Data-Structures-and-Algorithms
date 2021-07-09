/**
 * Given an array of unique integers, find the index of any peak element
 * 
*/

#include <iostream>

int peak(int a[], int n) {
	int low = 0, high = n-1, mid;
	while(low < high) {
		mid = low + (high-low)/2;
		if(a[mid] > a[mid+1]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	return low;
}

int main() {
	int a[] = {2, 1};
	std::cout << peak(a, 2) << '\n';
	int b[] = {1, 2};
	std::cout << peak(b, 2) << '\n';
}
