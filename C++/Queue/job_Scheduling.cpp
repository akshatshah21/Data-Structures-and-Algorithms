#include<iostream>
using namespace std;
#define MAX_SIZE 3
class CircularQueue {
		int arr[MAX_SIZE];	// Data is call number or job number
		int front, rear, size;
	public:
		CircularQueue() {
			front = -1;
			rear = -1;
			size = 0;
		}
		void enqueue(int x);
		int dequeue();
		int get_front();
		void print();
		bool isEmpty() {
			return size == 0;
		}
		bool isFull() {
			return size == MAX_SIZE;
		}	
};
void CircularQueue :: print() {
	int f = front;
	while(f != rear) {
		cout<<arr[f]<< ' ';
		f = (f+1) % MAX_SIZE;
	}
	cout<<endl;
}
void CircularQueue :: enqueue(int x) {
	if(isEmpty()) {
		front = 0;
		rear = 0;
	}
	else if(isFull()) {
		cout<<"Circular Queue full\n";
		return;
	}
	arr[rear] = x;
	rear = (rear + 1) % MAX_SIZE;
	size++;
}
int CircularQueue :: dequeue() {
	if(isEmpty()) {
		cout<<"Circular Queue empty\n";
		return -1;
	}
	int temp = arr[front];
	front = (front + 1) % MAX_SIZE;
	size--;
	if(isEmpty()) {
		front = -1; rear = -1;
	}
	return temp;
}
int CircularQueue :: get_front() {
	if(!isEmpty())	return arr[front];
	cout<<"Circular Queue is empty\n";
	return -1;
}
int main() {
	CircularQueue job_queue;
	int t=120, n, calls_served = 0;
	cout<<"Enter number of jobs: ";
	cin>>n;
	int arrival[n], service[n], idle=0;
	cout<<"Enter Arrival and Service time:";
	cin>>arrival[0]>>service[0];
	if(arrival[0] > 0)	idle += arrival[0] - 0;
	job_queue.enqueue(service[0]);
	int k = 1, done = -1, temp;
	while(t - job_queue.get_front() >= 0) {
		while(!job_queue.isFull() && k != n) {
			cout<<"Enter Arrival and Service time:";
			cin>>arrival[k]>>service[k];
			job_queue.enqueue(service[k++]);
		}
		if(k!=n)
			cout<<"Queue full...\n";
		temp = job_queue.dequeue();
		done++;
		calls_served++;
		cout<<"\n***\nWaiting time for call "<<done+1<<" is "<<(((120 - t - arrival[done]) >= 0) ? 120 - t - arrival[done] : 0)<<"\n***\n"<<endl;
		t -= temp;
		if(calls_served==n)	break;
		if(arrival[done+1] > (120-t))	idle += arrival[done+1] - (120-t);
		cout<<"Idle:"<<idle<<endl;
	} 
	cout<<"\n***\nNumber of calls served: "<<calls_served<<"\n***\n"<<endl;
	cout<<"Total idle time:"<<idle<<"\n***\n"<<endl;
	return 0;
}