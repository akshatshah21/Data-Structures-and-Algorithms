#include<iostream>
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
	void insertAtHead(int x);
	void append(int x);
	void insertAt(int pos, int x);	// 0 based indexing
	void deleteHead();
	void deleteTail();
	void deleteAt(int pos);			// 0 based indexing
	int getHead();
	int getTail();
	int getAt(int pos);				// 0 based indexing
	void print();
};

void LinkedList :: insertAtHead(int x) {
	Node *node = new Node(x);
	node -> next = head;
	head = node;
}

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

void LinkedList :: insertAt(int pos, int x) {
	if(head == NULL) {
		cout<<"LinkedList is empty\n";
		return;
	}	
	if(pos == 0)	return insertAtHead(x);
	Node *node = new Node(x);
	Node *trav = head;
	int count = 0;
	while(count != pos - 1 && trav != NULL) {
		trav = trav -> next;
		count++;
	}
	if(trav == NULL) {
		cout<<"Index out of bound, could not add "<<x<<" at pos="<<pos<<endl;
		return;
	}
	node -> next = trav -> next;
	trav -> next = node;
}

void LinkedList :: deleteHead() {
	if(head == NULL) {
		cout<<"LinkedList empty. Cannot delete head\n";
		return;
	}
	Node *temp = head;
	head = head -> next;
	delete temp;
}

void LinkedList :: deleteTail() {
	if(head == NULL) {
		cout<<"LinkedList empty. Cannot delete tail\n";
		return;
	}
	Node *trav = head;
	if(head -> next == NULL) { 	// If only one node
		delete trav;
		head == NULL;
		return;
	}
	while(trav -> next -> next != NULL) 
		trav = trav -> next;
	Node *temp = trav -> next;
	trav -> next = NULL;
	delete temp;
}

void LinkedList :: deleteAt(int pos) {
	if(head == NULL) {
		cout<<"LinkedList empty. Cannot delete node at pos="<<pos<<endl;
		return;
	}
	if(pos == 0)	return deleteHead();
	Node *trav = head;
	int count = 0;
	while(count != pos - 1 && trav != NULL) {
		trav = trav -> next;
		count++;
	}
	if(trav == NULL || trav -> next == NULL) {
		cout<<"Index out of bounds\n";
		return;
	}

	Node *temp = trav -> next;
	trav -> next = trav -> next -> next;
	delete temp;
}

int LinkedList :: getHead() {
	if(head == NULL) {
		cout<<"LinkedList empty. Returning -1\n";
		return -1;
	}
	return head -> data;
}

int LinkedList :: getTail() {
	if(head == NULL) {
		cout<<"LinkedList empty. Returning -1\n";
		return -1;
	}
	Node *trav = head;
	while(trav -> next != NULL) 
		trav = trav -> next;
	return trav -> data;
}

int LinkedList :: getAt(int pos) {
	if(head == NULL) {
		cout<<"LinkedList empty. Returning -1\n";
		return -1;
	}
	if(pos == 0)	return getHead();
	int count = 0;
	Node *trav = head;
	while(count != pos && trav != NULL) {
		trav = trav -> next;
		count++;
	}
	if(trav == NULL) {
		cout<<"Index out of bounds. Returning -1\n";
		return -1;
	}
	return trav -> data;
}

void LinkedList :: print() {
	if(head == NULL) {
		cout<<"LinkedList empty\n";
		return;
	}
	cout<<"LinkedList:";
	Node *trav = head;
	while(trav != NULL) {
		cout<<trav -> data<<' ';
		trav = trav -> next;
	}
	cout<<endl;
}

int main() {
	LinkedList ll;
	// ll.append(0);
	// ll.append(1);
	// ll.append(2);
	// ll.append(3);
	// ll.insertAt(5, 100);
	// ll.print();
	// cout<<"Head:"<<ll.getHead()<<endl;
	// cout<<"Tail:"<<ll.getTail()<<endl;
	// cout<<ll.getAt(5)<<endl;
	// ll.deleteAt(5);
	// ll.insertAtHead(5);
	// ll.insertAt(4, 8);
	// ll.deleteHead();
	// ll.deleteHead();
	// ll.deleteTail();
	// ll.deleteTail();
	// ll.print();
	return 0;
}
