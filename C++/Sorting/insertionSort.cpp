#include<iostream>
using namespace std;
/*
	Insertion Sort
	Parameters: pointer to first element of arr, length of arr
	Time: O(n^2) | Space: O(1)
*/
void insertionSort(int arr[], int n) {
	for(int i=1;i<n;i++) {	// start from k = 1
		int key =  arr[i];	// take arr[i], insert it at its correct pos in arr[0 to i]
		int j = k-1;
		while(j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];	// if arr[j] > key, move it ahead
			j -= 1;				// check next left element
		}
		arr[j+1] = temp;		// correct place for temp in arr[0 to i]
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
