#include<iostream>
using namespace std;
void insertionSort(int arr[], int n) {
	for(int k=1;k<n;k++) {
		int temp = arr[k];
		int j = k-1;
		while(j >= 0 && arr[j] > temp) {
			arr[j+1] = arr[j];
			j -= 1;
		}
		arr[j+1] = temp;
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