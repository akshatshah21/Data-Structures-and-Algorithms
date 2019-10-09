#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Node {	// Singly Linked List node
	public:
	int data;
	Node *next;
	Node(int data) {
		this -> data = data;
	}

};
class LinkedList { // Singly Linked List
	Node *head;
public:
	LinkedList() {
		head = NULL;
	}
	void append(int x);
	void buildFromArr(int arr[], int len);
	void print();
};
void LinkedList :: append(int x) {
	Node *node = new Node(x);
	node -> next = NULL;
	if(head == NULL) {
		head = node;
		return;
	}
	Node *trav = head;
	while(trav -> next != NULL) 
		trav = trav -> next;
	trav -> next = node;
}

void LinkedList :: buildFromArr(int arr[], int len) {
	for(int i=0;i<len;i++) {
		append(arr[i]);
	}
}
void LinkedList :: print() {
	if(head == NULL) {
		cout<<"LinkedList empty\n";
		return;
	}
	Node *trav = head;
	while(trav != NULL) {
		cout<<trav -> data<<' ';
		trav = trav -> next;
	}
	cout<<endl;
}
class Student {
	private:
		int id;
		string name;
		LinkedList marks;
	public:
		Student(int id, string name) {
			this -> id = id;
			this -> name = name;
		}
		void addMarks(int arr[], int len);
		void get();
};

void Student :: addMarks(int arr[], int len) {
	marks.buildFromArr(arr, len);
}

void Student :: get() {
	cout<<"Student:"<<name<<endl;
	cout<<"Student ID:"<<id<<endl;
	cout<<"Marks:";marks.print();
}
int main() {
	int n;
	fstream f;
	f.open("marks.txt", ios::in);
	/*	
		File format as follows: (N is number of students)
		N
		ID1 Name1 NumberOfSubjects
		ID2 Name2 NumberOfSubjects
		.
		.
		.
		IDN NameN NumberOfSubjects
	*/
	f>>n;
	Student *students[n];
	string name;
	int id, m;
	for(int i=0;i<n;i++) {
		f>>id;	
		f>>name;
		f>>m;
		int marks[m];
		for(int j=0;j<m;j++) f>>marks[j];
		students[i] = new Student(id, name);
		students[i] -> addMarks(marks, m);
	}
	cout<<"STUDENTS:\n\n";
	for(int i=0;i<n;i++) {
		students[i] -> get();
		cout<<"--------------------------\n";
	}
	return 0;
}
