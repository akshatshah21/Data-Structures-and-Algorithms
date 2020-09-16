#include<iostream>
using namespace std;
// Swap utility function
void swap(int &p, int &q) {
	int  t = p;
	p = q;
	q = t;
}

/*
 * 	Selection Sort Algorithm
 * 	Params: Array a of length n
 * 	Time complexity: O(n^2)
 */
void selectionSort(int a[], int n) {
	for(int i=0;i<n-1;i++) {
		int min = i;
		for(int j=i+1;j<n;j++) 
			if(a[j] < a[min])	min = j;
		swap(a[min], a[i]);
	}		
}

int main() {
	int arr[] = {3,4,6,7,2,7,3,8,9};
	selectionSort(arr, 9);
	for(int i=0;i<9;i++)	cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
