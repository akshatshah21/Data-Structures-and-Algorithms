#include<iostream>
using namespace std;
int partition(int a[], int low, int high) {
	int i = low, j = high+1;
	int pivot = a[low];
	while(true) {
		// It is better to use preincrement, since checking for low and high bounds is done after array element is accessed.
		while(a[++i] < pivot)
			if(i==high)	break;
		while(a[--j] > pivot)
			if(j==low)	break;
		if(i>=j)	break;
		swap(a[i], a[j]);
	}
	swap(a[j], a[low]);
	return j;

}
void quicksort(int arr[], int low, int high) {
	if(low >= high)	return;
	int j = partition(arr, low, high);
	quicksort(arr, low, j-1);
	quicksort(arr, j+1, high);
}
int main() {
	int arr[] = {5,4, 1, 2, 3, 6, 7, 43, 5, 1};
	quicksort(arr, 0, 9);
	for(int i=0;i<10;i++)	cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
