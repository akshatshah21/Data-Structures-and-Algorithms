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
	void buildFromArr(int arr[], int len);
	void deleteDuplicates();
	void print();
};

void LinkedList :: insertAtHead(int x) {
	Node *node = new Node(x);
	node -> next = head;
	head = node;
}

void LinkedList :: append(int x) {
	Node *node = new Node(x);
	// print();
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
	static int count=0;
	if(head == NULL) {
		cout<<"LinkedList empty\n";
		return;
	}
	// cout<<"count="<<count<<endl;
	cout<<"LinkedList:";
	Node *trav = head;
	while(trav != NULL) {
		cout<<trav -> data<<' ';
		trav = trav -> next;
	}
	cout<<endl;
}

void LinkedList :: buildFromArr(int arr[], int len) {
	for(int i=0;i<len;i++) {
		append(arr[i]);
		// print();
	}
	// print();
}

void LinkedList :: deleteDuplicates() {
	if(head == NULL)	return;
	if(head -> next == NULL)	return;
	Node* trav1 = head;
	Node *trav2, *temp;
	while(trav1 != NULL && trav1 -> next !=  NULL) {
		// cout<<"Did I enter the loop?\n";
		// if(trav1->next == NULL)	break;
		
		trav2 = trav1;
		while(trav2 -> next != NULL) {
			if(trav2 -> next -> data == trav1 -> data) {
				// cout<<trav2->next->data<<"=="<<trav1->data<<endl;
				temp = trav2 -> next;
				trav2 -> next = temp -> next;
				// cout<<"Deleting "<<temp->data<<endl;
				delete temp;
				// cout<<"Deleted.\n";
			}
			else	trav2 = trav2 -> next;
		}

		// if(trav1 == NULL)	cout<<"trav1 became NULL\n";
		trav1 = trav1 -> next;
		// if(trav1 == NULL)	cout<<"trav1 became NULL later\n";
		// cout<<"Now trav1 points to"<<trav1->data<<endl;
	}
	// cout<<"Broke out of loop\n";
}




int main() {
	LinkedList ll;
	int len;
	cout<<"Enter size of list:";
	cin>>len;
	int arr[len];
	cout<<"Enter list:\n";
	for(int i=0;i<len;i++) cin>>arr[i];
	// ll.print();
	ll.buildFromArr(arr, len);
	ll.deleteDuplicates();
	ll.print();
	return 0;
}