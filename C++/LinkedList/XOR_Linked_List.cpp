#include<iostream>
using namespace std;

class XORList {
	class Node {
	public:
		int data;
		Node* both;
		Node(int x, Node* prev) {
			this -> data = x;
			this -> both = prev;
		}
	};
	Node* head;
public:
	XORList() {
		head = nullptr;
	}

	Node* XOR(Node *a, Node *b) {
		return (Node*)(uint64_t(a) ^ uint64_t(b));
	}

	Node* getNext(Node* curr, Node* prev) {
		return XOR(curr->both, prev);
	}

	Node* getPrev(Node* curr, Node* next) {
		return XOR(curr->both, next);
	}

	void add(int x) {
		if(!head) {
			head = new Node(x, nullptr);
		} else {
			Node *curr = head, *prev = nullptr;
			Node *next = getNext(curr, prev);
			while(next) {
				prev = curr;
				curr = next;
				next = getNext(curr, prev);
			}
			curr -> both = XOR(prev, new Node(x, curr));
		}
	}
	int get(int index) {
		if(index < 0) return -1;
		int i = 0;
		Node *curr = head, *prev = nullptr, *next;
		while(curr) {
			if(i == index) {
				return curr -> data;
			}
			next = getNext(curr, prev);
			prev = curr;
			curr = next;
			i++;
		}
		return -1;
	}
	void remove(int index) {
		if(!head) return;
		int i = 0;
		Node *curr = head, *prev = nullptr, *next = nullptr;
		while(curr) {
			next = getNext(curr, prev);
			if(i == index) break;
			prev = curr;
			curr = next;
			i++;
		}
		if(i != index) return;
		if(prev) {
			prev -> both = XOR(prev -> both, curr);
			prev -> both = XOR(prev -> both, next);
		}
		if(next) {
			cout << "next:" << next->data << '\n';
			next -> both = XOR(next -> both, curr);
			next -> both = XOR(next -> both, prev);
		}
		if(!prev) {
			head = next;
		}
		delete curr;
	}
	void print() {
		cout << "[ ";
		Node *curr = head, *prev = nullptr, *next;
		while(curr) {
			cout << curr -> data << " ";
			next = (Node*)(uint64_t(curr -> both) ^ uint64_t(prev));
			prev = curr;
			curr = next;
		}
		cout << "]" << '\n';
	}
};

int main() {
	XORList list;
	list.print();
	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.print();
	for(int i=0; i<6; i++) {
		cout << i << ": " << list.get(i) << '\n';
	}
	list.remove(5); // no effect
	list.remove(0);
	list.remove(2);
	list.remove(4); // no effect
	list.print();
}
