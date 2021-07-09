#include <iostream>

int merge(int a[], int low, int high) {
	int res = 0;
	int mid = low + (high - low)/2;
	int x = 0, y = mid+1, k = 0;
	int A[high - low + 1];
	while(x <= mid && y <= high) {
		if(a[x] <= a[y]) {
			A[k++] = a[x++];
		} else {
			// a[y] skips over a[x...mid]
			res += mid - x + 1;
			A[k++] = a[y++];
		}
	}
	while(x <= mid) {
		A[k++] = a[x++];
	}
	while(y <= high) {
		A[k++] = a[y++];
	}
	for (int i = low; i <= high; i++) {
		a[i] = A[i-low];
	}
	return res;
}

int inversion_count(int a[], int low, int high) {
	int res = 0;
	if(low < high) {
		int mid = low + (high - low)/2;
		res += inversion_count(a, low, mid);
		res += inversion_count(a, mid+1, high);
		res += merge(a, low, high);
	}
	return res;
}

int main() {
	int a[] = { 3, 1, 2 };
	std::cout << inversion_count(a, 0, 2) << "\n";	
}
