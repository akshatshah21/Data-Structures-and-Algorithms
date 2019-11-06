#include<iostream>
using namespace std;
#define MAX_NODES 10
int arr[MAX_NODES], ptr = 0;
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
void enqueue(int data) {
	if(ptr == MAX_NODES) {
		cout << "Priority Queue full!\n";
		return;
	}
	arr[ptr++] = data;
	int pos = ptr - 1;
	while(arr[pos] < arr[(pos-1)/2] && pos > 0) {
		// cout << "here\n";
		swap(arr[pos], arr[pos/2]);
		pos /= 2;
	}
}
 
int get_front() {
	if(ptr == 0) {
		cout << "Priority Queue empty. Returning -1\n";
		return -1;
	}
	return arr[0];
}

int dequeue() {
	if(ptr == 0) {
		cout << "Priority Queue empty. Returning -1\n";
		return -1;
	}
	int temp = arr[0];
	arr[0] = arr[--ptr];
	int pos = 0;
	while((arr[pos] > arr[2*(pos+1)] || arr[pos] > arr[2*(pos + 1)-1]) && (2*(pos + 1)-1 < ptr)) {
		// cout << "here\n";
		if(arr[2*(pos+1)] > arr[2*(pos+1)-1]) {
			swap(arr[pos], arr[2*(pos+1)]);
			pos = 2*(pos+1);
		}
		else {
			swap(arr[pos], arr[2*(pos+1)-1]);
			pos = 2*(pos+1)-1;
		}
	}
	return temp;
}

void print() {
	if(ptr == 0) {
		cout << "Priority Queue is empty\n";
		return;
	}
	for(int i=0;i<ptr;i++)	cout << arr[i] << ' ';
	cout << endl;
}

int main() {
	cout << "1-Enqueue\t2-Get Front\t3-Dequeue\n4-Print\t5-Exit\n";
	int op=-1;
	while(op != 5) {
		cin >> op;
		switch(op) {
			case 1:
				cout << "Enter value to be enqueued:";
				int num;
				cin >> num;
				enqueue(num);
				break;
			case 2:
				cout << "Front of queue:" << get_front() << endl;
				break;
			case 3:
				cout << "Dequeued:" << dequeue() << endl;
				break;
			case 4:
				print();
				break;
			case 5:
				break;
			default:
				cout << "Invalid input\n";
		}
		cout << "1-Enqueue\t2-Get Front\t3-Dequeue\n4-Print\t5-Exit\n";
	}
	return 0;
}