#include<iostream>
using namespace std;


void shellSort(int a[], int n, int h) {
	for(int i=0;i<n;i++)
		for(int j=i-1;j >= 0 && a[j+1] < a[j];j-=h) {
				swap(a[j+1], a[j]);
		}
}


int main() {
	int arr[] = {5,8,3,9,7,4,3,0,9};
	shellSort(arr, 9, 4);
	shellSort(arr, 9, 1);
	for(int i=0;i<9;i++)
		cout << arr[i] << ' ';
	cout << endl;
	
	return 0;
}

