/*
    Implement a stack using single queue
    push(): O(n)
    pop(): O{1}
    In every push(x) operation:
        1. Enqueue x to queue
        2. For all elements except the one just inserted:
            a. Dequeue element
            b. Enqueue that dequeued element
    In every pop() operation:
        1. Normal dequeue operation
*/
#include<iostream>
using namespace std;
#define N 10
int q[N], f=0, r=0, size=0;
void enq(int x) {
    q[r] = x;
    size++;
    r = (r+1) % N;
}
int deq() {
    int temp = q[f];
    f = (f+1)%N;
    size--;
    return temp;
}
bool empty() {
    return size == 0;
}
bool full() {
    return size == N;
}
void push(int x) {
    if(full()) {
        cout << "Overflow\n";
        return;
    }
    int s = size;
    enq(x);
    while(s--)
        enq(deq());
}
int pop() {
    if(empty()) {
        cout << "Underflow\n";
        return -999;
    }
    return deq();
}
int top() {
    if(empty()) {
        cout << "Stack empty\n";
        return -999;
    }
    return q[f];
}
int main() {
    cout << pop() << endl;
    cout << top() << endl;
    for(int i=0;i<10;i++)
        push(i);
    cout << "This should cause overflow\n";
    push(10);
    cout << "Top = " << top() << endl;
    while(!empty()) {
        cout << pop() << endl;
    }
    cout << "This should cause underflow\n";
    cout << pop() << endl;
    return 0;
}