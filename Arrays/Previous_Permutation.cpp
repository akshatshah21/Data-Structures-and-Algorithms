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

	int i = n - 2;
	// Find first element from behind which breaks the non-decreasing pattern
	// (as viewed in reverse)
	while (i >= 0 && a[i] <= a[i + 1]) i--;

	if (i < 0) {
		// Array in sorted order,
		// so previous permutation is reverse of it
		reverse(a, a + n);
	} else {
		// Binary Search for the largest element less than
		// the element we found above
		// in the range [i+1...n-1]
		int lo = i + 1, hi = n - 1, mid, ans;
		while (lo <= hi) {
			mid = lo + (hi - lo) / 2;
			if (a[mid] < a[i]) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		swap(a[i], a[ans]); // note that ans will always be defined by BS

		// Reverse a[i+1...n-1]
		reverse(a + i + 1, a + n);
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}
