#include<iostream>
using namespace std;

#define MAX_SIZE 100
#define MAX_JOBS 100

class CircularQueue {
		int arr[MAX_SIZE];	// Data is call number or job number
		int front, rear, size;
	public:
		CircularQueue() {
			front = -1;
			rear = -1;
			size = 0;
		}
		bool enqueue(int x);
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

bool CircularQueue :: enqueue(int x) {
	if(isEmpty()) {
		front = 0;
		rear = 0;
	}
	else if(isFull()) {
		return false;
	}
	arr[rear] = x;
	rear = (rear + 1) % MAX_SIZE;
	size++;
	return true;
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
	int t = 1;
	int op;
	int arrival, service[MAX_JOBS], now = 0, idle[MAX_JOBS], start[MAX_JOBS];
	cout<<"1. Enter a job with arrival time and service time, separated with spaces:\n2. Exit\nCommand:";
	cin>>op;

	
	while(op != 2) {
		if(job_queue.isFull()) {
			cout<<"Job queue is full\n";
		}	
		job_queue.enqueue(t);
		cin>>arrival>>service;
		start[t-1] = now;
		idle[t-1] = now - arrival;
		t++;
		now += service;
		job_queue.dequeue();
		cout<<"Command:";	
		cin>>op;
	}
	
	int job_count = 0;
	for(int time = 0; time< 121;i++) {
		if(time == start[job_queue.getFront()]) {
			int job = job.dequeue();
			idle = arrival[i] - time;
			start[job] = time;
			time += service[job];
			job_count++;
		}
	}
	
	
	cout<<"***********************\n";
	cout<<"Total jobs done:"<<job_count<<endl;
	for(int i=0;i<t-1;i++) {
		cout<<"Job "<<i+1<<"\tStart:"<<start[i]<<"\tIdle:"<<idle[i]<<endl;
	}
	return 0;
}
