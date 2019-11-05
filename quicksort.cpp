#include<iostream>
using namespace std;
void _swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
int partition(int arr[], int low, int high) {
	cout << "partition " << low << ' ' << high << endl;
	int left = low;
	int right = high - 1;
	int mid = (low + high) / 2;
	_swap(arr[mid], arr[high]); // move pivot to end
	do {
		cout << "here\n";
		while(arr[left] < arr[high]) left++;
		while(arr[right] >= arr[high] && right > left)	right--;
		if(right <= left)	break;
		_swap(arr[left], arr[right]);
	} while(left < right);
	_swap(arr[high], arr[left]);
	return right;
}
void quicksort(int arr[], int low, int high) {
	if(low >= high)	return;
	int j = partition(arr, low, high);
	cout << "break at " << j << endl;
	quicksort(arr, low, j);
	quicksort(arr, j+1, high);
}
int main() {
	int arr[] = {5,4, 1, 2, 3, 6, 7, 43, 5, 1};
	quicksort(arr, 0, 9);
	for(int i=0;i<10;i++)	cout << arr[i] << ' ';
	cout << endl;
	return 0;
}
