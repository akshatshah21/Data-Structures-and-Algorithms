#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define MAX_NODES 10
class Passenger {
public:
	int pNo;
	string name;
	Passenger() {}
	Passenger(string name, int a, int b, int c) {
		this -> name = name;
		pNo = a/1000 + b - c;
	}
};
Passenger arr[MAX_NODES];
int ptr = 0;
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
void enqueue(Passenger p) {
	if(ptr == MAX_NODES) {
		cout << "Priority Queue full!\n";
		return;
	}
	arr[ptr++] = p;
	int pos = ptr - 1;
	while(arr[pos].pNo > arr[(pos-1)/2].pNo && pos > 0) {	// new element floating to its place
		swap(arr[pos], arr[(pos-1)/2]);
		pos = (pos-1) / 2;
	}
}
Passenger get_front() {
	if(ptr == 0) {
		cout << "Priority Queue empty. Returning -1\n";
		return Passenger("err", 0, 0, 0);
	}
	return arr[0];
}
Passenger dequeue() {
	if(ptr == 0) {
		cout << "Priority Queue empty. Returning -1\n";
		return Passenger("err", 0, 0, 0);
	}
	Passenger temp = arr[0];
	arr[0] = arr[--ptr];
	int pos = 0;
	while(arr[pos].pNo < arr[2*pos+1].pNo || arr[pos].pNo < arr[2*pos+2].pNo) {	// root element sinking to its place
		if(arr[2*pos+1].pNo > arr[2*pos+2].pNo && (2*pos+1 < ptr)) { // left > right
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
void print() {
	if(ptr == 0) {
		cout << "Priority Queue is empty\n";
		return;
	}
	cout << "Name" << "\tPriority Number" << endl;
	while(ptr != 0)	{
		Passenger p = dequeue();
		cout << p.name << '\t' << p.pNo << endl;
	}	
}
int main() {
	fstream f;
	f.open("file.txt", ios::in);
	int n;
	f >> n;
	int a,b,c;
	string name;
	for(int i=0;i<n;i++) {
		f >> name >> a >> b >> c;
		enqueue(Passenger(name, a, b, c));
	}
	print();
	f.close();
}