#include<iostream>
using namespace std;

void partition3(int a[], int low, int high) {
	if(low < high) {
		int lt = low, gt = high, i = low+1;
		int pivot = a[low];
		while(i <= gt) {
			if(a[i] < pivot) {
				swap(a[i], a[lt]);
				lt++;
				i++;
			}
			else if(a[i] > pivot) {
			swap(a[i], a[gt]);
			gt--;
		}
		else
			i++;
		}
		partition3(a, low, lt-1);
		partition3(a, gt+1, high);
	}	
}

void quicksort(int arr[], int n) {
	if(n == 0 || n == 1)	return;
	// Practically, cutoff to insertion sort if n is about 10
	partition3(arr, 0, n-1);
}

int main() {
	int arr[10] = {9,6,5,8,5,9,2,2,0,4};
	quicksort(arr, 10);
	for(int i=0;i<10;i++)	cout << arr[i] << ' ';
	cout << "\n";
	return 0;
}
