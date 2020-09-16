#include<iostream>
using namespace std;
#define N 20
#define K 2

/*
	arr: Array used for storing the values
	next: Array used to keep track of second from top elements in stack,
			as well as the next free position in arr at which new element can be added
	top: Array used to store top pointers of K stacks
	free: variable to store next free available slot in arr
*/

int arr[N], top[K], next[N], free = 0;
bool isEmpty(int sn) {
	return top[sn] == -1;
}
bool isFull(int sn) {
	return free == -1;  // no more free spaces
}
void push(int sn, int x) {
	if(isFull(sn)) {
		cout << "Stack Overflow\n";
		return;
	}
	int i = free;   // Current available position
	free = next[i]; // Next available position
	next[i] = top[sn];  // Now top[sn] points to old top of stack sn, so index of 2nd element stored in next[i]
	top[sn] = i;    // Top pointer now points to available postition
	arr[i] = x;     // Insert x at available position in arr
}
int pop(int sn) {
	if(isEmpty(sn)) {
		cout << "Stack Underflow, returning -999\n";
		return -999;
	}

	/*
		Note that the next four lines are the exact reverse of push() code
	*/

	int i = top[sn];    // i now holds the index of arr to be emptied/popped
	top[sn] = next[i];  // top pointer should now point to second top element, given by next[current_top_pointer]
	next[i] = free;     // The second available position, which is currently in free, given to next[i]
	free = i;           // The position to be emptied, i, will become the available position, stored in free
	return arr[i];
}
int getTop(int sn) {
	if(isEmpty(sn)) {
		cout << "Stack Empty, returning -999\n";
		return -999;
	}
	return arr[top[sn]];
}

int main() {
	/* Initialize all elements of top as -1, indicating empty*/
	for(int i=0;i<K;i++)
		top[i] = -1;
	/* Initialize elements of next*/
	for(int i=0;i<N;i++)
		next[i] = i+1;
	/* Driver code */
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
	return 0;
}