#include<iostream>
using namespace std;
#define MAX_SIZE 3
class PriorityQueue {
	int size, front, rear, arr[MAX_SIZE];
public:
	PriorityQueue() {
		size = 0;
		front = -1;
		rear = -1;		
	}

	void enqueue(int x) {
		if(isFull()) {
			cout<<"PriorityQueue full\n";
			return;
		}
		else if(isEmpty()) {
			front = 0;
			rear = 1;
			arr[rear - 1] = x;
			size ++;
			return;
		}
		int i;
		for(i=rear-1;i>=front;i--) {
			if(arr[i] > x)
				arr[i+1] = arr[i];
			else	break;
		}
		arr[i+1] = x;
		rear++;
		size++;
	}

	int dequeue() {
		if(isEmpty()) {
			cout<<"PriorityQueue empty\n";
			return -1;
		}
		int temp = arr[front++];
		size --;
		if(isEmpty()) {
			front = -1;
			rear = -1;
		}
		return temp;
	}

	int get_front() {
		if(isEmpty()) {
			cout<<"PriorityQueue empty\n";
			return -1;
		} 
		return arr[front];
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return rear == MAX_SIZE;
	}

	void print() {
		for(int i = front; i < rear;i++) {
			cout<<arr[i]<<' ';
		}
		cout<<endl;
	}


};

int main() {
	PriorityQueue pq;
	int op = -1;
	while(op != 5) {
		cout<<"1-Enqueue\t2-Dequeue\n3-See front\t4-Print PriorityQueue\n5-Exit\n";
		cin>>op;
		switch(op) {
			case 1:
			{
				int a;
				cout<<"Enter element to be enqueued: ";
				cin>>a;
				pq.enqueue(a);
				break;
			}
			case 2:
				cout<<"Dequeued element: "<<pq.dequeue()<<endl;
				break;
			case 3:
				cout<<"Front element: "<<pq.get_front()<<endl;
				break;
			case 4:
				cout<<"PriorityQueue: ";
				pq.print();
				break;
			case 5:
				break;
			default:
				cout<<"Invalid option\n";
		}
	}
	return 0;
}