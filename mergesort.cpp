#include<iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high) {
	int l1 = mid-low+1, l2 = high - mid;
	int L[l1], R[l2];
	for(int i=0;i<l1;i++)	L[i] = arr[low+i];
	for(int j=0; j<l2; j++)	R[j] = arr[mid+1+j];
	int i=0, j=0, k=low; // i -> L | j -> R | k -> arr
	while(i < l1 && j < l2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<l1) {
		arr[k] = L[i];
		k++;
		i++;
	}
	while(j < l2) {
		arr[k] = R[j];
		k++;
		j++;
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
