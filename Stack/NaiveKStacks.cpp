#include<iostream>
using namespace std;
#define N 20
#define K 2
int arr[N], top[K];
bool isEmpty(int sn) {
	return top[sn] == sn*N/K - 1;
}
bool isFull(int sn) {
	return top[sn] == (sn+1)*N/K - 1;
}
void push(int sn, int x) {
	if(isFull(sn)) {
		cout << "Stack Overflow\n";
		return;
	}
	arr[++top[sn]] = x;
}
int pop(int sn) {
	if(isEmpty(sn)) {
		cout << "Stack Underflow, returning -999\n";
		return -999;
	}
	return arr[top[sn]--];
}
int getTop(int sn) {
	if(isEmpty(sn)) {
		cout << "Stack Empty, returning -999\n";
		return -999;
	}
	return arr[top[sn]];
}
int main() {
	for(int i=0;i<K;i++)
		top[i] = i*N/K-1;
	cout << "Pushing to Stack1\n";
	push(0,1);
	push(0,2);
	push(0,3);
	push(0,4);
	push(0,5);
	push(0,6); 
	cout << "Pushing to Stack 2\n";
	push(1,6);
	push(1,7);
	push(1,8);
	push(1,9);
	push(1,10);
	cout << "Top sn1:" << getTop(0) << endl;
	cout << "Top sn1:" << getTop(1) << endl;
	while(!isEmpty(0))
		cout << pop(0) << endl;
	while(!isEmpty(1))
		cout << pop(1) << endl;
	cout << "Now all stacks should be empty\n"	;
	cout << pop(0) << endl;
	cout << pop(0) << endl;
}
