#include<iostream>
using namespace std;

/* Recursive function to generate all possible binary strings of length n
 * For the total problem, n denotes the number of positions left for which the recursion tree will fork ( 0 or 1)
 * At every point, we have two choices. Put 1 in the current position or put 0. We go down both paths
 */
void gen1(string a, int n) {
	// Base case, no position left to put 1 and 0 in
	if(n==0) {
		cout << a << "\n";
		return;
	}

	// Recursive cases:
	// Put 0 in the current pos i.e. n-1, recur for other positions to the left
	gen1(a, n-1);

	// Put 1 in current pos, recur for the other positions to the left
	a[n-1] = '1';
	gen1(a, n-1);
}


/* Recursive function to print all binary numbers of length n in order
 * The method is the same, the only difference is that we are starting from left, and we recur the '0' path before the '1' path, like in gen1, so we get the numbers in order
 * i is the current pos in the string
 */
void gen2(string a, int n, int i) {
	if(i==n) {
		cout << a << "\n";
		return;
	}

	a[i] = '0';
	gen2(a, n, i+1);
	a[i] = '1';
	gen2(a, n, i+1);

}

int main() {
	int n;
	cin >> n;
	string a(n, '0');
	gen2(a, n, 0);
}
