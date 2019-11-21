/* Question link (HackerRank): https://www.hackerrank.com/challenges/maximum-element/problem */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
int stack[100000], trackStack[100000];
int topStack = -1, topTrackStack = -1;
void push1(int x) {
    stack[++topStack] = x;
}
void pop1() {
    topStack--;
}
void push2(int x) {
    trackStack[++topTrackStack] = x;
}
int get_front2() {
    if(topTrackStack < 0)   return -999;
    return trackStack[topTrackStack];
}
void pop2() {
    topTrackStack--;
}

int main() {
    fastio();
    int n;
    cin >> n;
    while(n--) {
        int type, x;
        cin >> type;
        switch(type) {
            case 1:
                cin >> x;
                push1(x);
                if(x > get_front2())    push2(x);
                else    push2(get_front2());
                break;
            case 2:
                pop1();
                pop2();
                break;
            case 3:
                cout << get_front2() << endl;
                break;
        }
   }
    return 0;
}
