#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Find first element from behind which breaks the non-decreasing pattern
	// (as viewed in reverse)
	int i = n - 2;
	while (i >= 0 && a[i] >= a[i + 1]) i--;

	if (i < 0) {
		// Array is sorted in reverse order
		// Next permutation is sorted order
		reverse(a, a + n);
	} else {
		// Binary search for the smallest element greater than
		// the element we found above
		// in the range [i+1...n-1]
		int lo = i + 1, hi = n - 1, mid, ans;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (a[mid] > a[i]) {
				ans = mid;
				lo = mid + 1; // since a[i+1...n-1] is sorted in non-increasing order
			} else {
				hi = mid - 1;
			}
		}
		swap(a[i], a[ans]); // Note that ans will always be defined by BS
		// Reverse a[i+1...n-1]
		reverse(a + i + 1, a + n);
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

}
