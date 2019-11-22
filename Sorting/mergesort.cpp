#include<iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high) {
	int A[high-low+1]; // temp array
	for(int i=low; i<=high; i++)
		A[i-low] = arr[i];
	int p1 = 0;	// low - low | pointer to left subarr in temp arr A
	int p2 = mid+1-low; // pointer to right subarr in temp arr A
	int p = low;	// pointer to low in arr
	while(p1 <= mid-low && p2 <=high-low) { // -low is the offset in temp arr A
		if(A[p1] <= A[p2]) {
			arr[p] = A[p1];
			p1++;
			p++;
		}
		else {
			arr[p] = A[p2];
			p2++;
			p++;
		}
	}
	while(p1 <= mid-low) {	// -low is the offset in temp arr A
		arr[p] = A[p1];
		p1++;
		p++;
	}
	while(p2 <= high-low) {	// -low is the offset in temp arr A
		arr[p] = A[p2];
		p2++;
		p++;
	}

}
void mergesort(int arr[], int low, int high) {
	if(low >= high)	return;
	int mid = (low + high) / 2;
	mergesort(arr, low, mid);
	mergesort(arr, mid+1, high);
	merge(arr, low, mid, high);
}
int main() {
	int arr[] = {5, 4, 1, 2, 3, 6, 7, 43, 5, 1};
	mergesort(arr, 0, 9);
	for(int i=0;i<10;i++)	cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
