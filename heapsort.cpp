#include<iostream>
using namespace std;
#define MAX_NODES 10
int arr[MAX_NODES], ptr = 0;
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
void insert(int data) {
	if(ptr == MAX_NODES) {
		cout << "Heap full!\n";
		return;
	}
	arr[ptr++] = data;
	int pos = ptr - 1;
	while(arr[pos] < arr[(pos-1)/2] && pos > 0) {	// new element floating to its place
		swap(arr[pos], arr[(pos-1)/2]);
		pos = (pos-1) / 2;
	}
}
int remove() {
	if(ptr == 0) {
		cout << "Heap empty. Returning -1\n";
		return -1;
	}
	int temp = arr[0];
	arr[0] = arr[--ptr];
	int pos = 0;
	while(arr[pos] > arr[2*pos+1] || arr[pos] > arr[2*pos+2]) {	// root element sinking to its place
		if(arr[2*pos+1] < arr[2*pos+2] && (2*pos+1 < ptr)) { // left > right
			swap(arr[pos], arr[2*pos+1]);
			pos = 2*pos+1;
		}
		else if(2*pos+2 < ptr){ // right >= left
			swap(arr[pos], arr[2*pos+2]);
			pos = 2*pos+2;
		}
		else	break;
	}
	return temp;
}
int main() {
	int arr[7] = {6,3,4,2,1,5,7};
	for(int i=0;i<7;i++)	insert(arr[i]);
	for(int i=0;i<7;i++)	arr[i] = remove();
	for(int i=0;i<7;i++)	cout << arr[i] << ' ';
	cout << endl;
	return 0;
}