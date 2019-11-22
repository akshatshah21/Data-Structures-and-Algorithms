#include<iostream>
using namespace std;
/*
	Insertion Sort
	Parameters: pointer to first element of arr, length of arr
	Time: O(n^2) | Space: O(1)
*/
void insertionSort(int arr[], int n) {
	for(int k=1;k<n;k++) {	// start from k = 1
		int temp = arr[k];	// take arr[k], insert it at its correct pos in arr[0 to k]
		int j = k-1;
		while(j >= 0 && arr[j] > temp) {
			arr[j+1] = arr[j];	// if arr[j] > temp, move it ahead
			j -= 1;				// check next left element
		}
		arr[j+1] = temp;		// correct place for temp in arr[0 to k]
	}
}
int main() {
	int arr[] = {5, 4, 1, 2, 3, 6, 7, 43, 5, 1};
	insertionSort(arr, 10);
	cout << "Sorted array:";
	for(int i=0;i<10;i++)	cout << arr[i] << ' ';
	cout << endl;
	return 0;
}