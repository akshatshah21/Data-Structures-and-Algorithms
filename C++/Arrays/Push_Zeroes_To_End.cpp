/**
 * Given an array of integers, move all zeroes to the end of the array
 * Expected solution: O(n), constant space, in-place
 * 
 */

#include <iostream>

// w: write pointer, points to first 0 in the array
// r: read pointer, regular iterator variable

void push_zeroes(int a[], int n) {
	int w = n;
	for (int i = 0; i < n; i++) {
		if(a[i] == 0) {
			w = i;
			break;
		}
	}
	for (int r = w+1; r < n; r++) {
		if(a[r] && w < r) {
			std::swap(a[r], a[w]); 
			while(w < r && a[w]) w++;
		}
	}
}

int main() {
	int a[] = {3, 5, 0, 1, 0, 4};
	push_zeroes(a, 6);
	for (int i = 0; i < 6; i++) {
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';
}
