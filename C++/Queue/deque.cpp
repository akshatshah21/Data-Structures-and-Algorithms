#include<iostream>
using namespace std;
#define N 5
int arr[N], l = -1, r = -1, size = 0;
void insert_left(int x) {
	if(size==N) {
		cout << "Overflow\n";
		return;
	}
	if(l==-1) {		// if deque is empty || r==-1 is same
		l = 0;
		r = 0;
	}
	else {
		if(l==0)	// circle to N-1
			l = N-1;
		else
			l = l-1;// regular
	}
	arr[l] = x;
	size++;
}
void insert_right(int x) {
	if(size == N) {
		cout << "Overflow\n";
		return;
	}
	if(r==-1) {	// If deque empty | l==-1 is same 
		r = 0;
		l = 0;
	}
	else {
		if(r==N-1)
			r = 0;
		else
			r = r+1;
	}
	arr[r] = x;
	size++;
}
int delete_left() {
	if(size == 0) {
		cout << "Underflow\n";
		return -999;
	}
	int temp = arr[l];
	if(l==N-1)
		l = 0;
	else
		l = l+1;
	size--;
	return temp;
}
int delete_right() {
	if(size == 0) {
		cout << "Underflow\n";
		return -999;
	}
	int temp = arr[r];
	if(r==0)
		r = N-1;
	else
		r = r-1;
	size--;
	return temp;
}
int get_left() {
	if(size == 0) {
		cout << "Deque empty\n";
		return -999;
	}
	return arr[l];
}
int get_right(){
	if(size == 0) {
		cout << "Deque empty\n";
		return -999;
	}
	return arr[r];
}
/*	Testing	 */
int main() {
	cout << get_left() << endl;
	cout << get_right() << endl;
	insert_left(1);
	insert_left(2);
	insert_left(3);
	insert_left(4);
	insert_left(5);
	cout << "Should cause overflow:\n";
	insert_left(5);
	cout << "Should cause overflow:\n";
	insert_right(5);
	while(size != 0)
		cout << delete_right() << endl;	
	cout << "Should cause underflow:\n";
	cout << delete_left() << endl;

	cout << "********\n";

	insert_right(1);
	insert_right(2);
	insert_right(3);
	insert_right(4);
	insert_right(5);
	cout << "Should cause overflow:\n";
	insert_right(6);
	cout << "Should cause overflow:\n";
	insert_left(6);
	while(size != 0)
		cout << delete_left() << endl;	
	cout << "Should cause underflow:\n";
	cout << delete_right() << endl;

	cout << "********\n";

	insert_left(1);
	insert_right(2);
	insert_left(3);
	insert_right(4);
	insert_left(5);
	cout << "Should cause overflow:\n";
	insert_right(6);
	cout << get_left() << endl;
	cout << get_right() << endl;
	cout << delete_right() << endl;
	cout << delete_left() << endl;
	insert_right(7);
	insert_left(9);
	cout << get_left() << endl;
	cout << get_right() << endl;
	while(size!=0)
		cout << delete_right() << endl;
	cout << delete_right() << endl;
	cout << delete_left() << endl;
	return 0;
}