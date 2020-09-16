#include<iostream>
using namespace std;

// Function to denote one move
// Move disk n from "from tower" to "to tower"
void move(int n, int from, int to) {
	static int count = 0;
	count++;
	cout << "Move " << count << ": Move disk " << n << " from tower " << from << " to tower " << to << "\n";
}

/* Recursive function to solve the problem
 * Subproblem: Move n disks from "from tower" to "to tower"
 * Use aux tower as auxilliary tower
 */

void hanoi(int n, int from, int to, int aux) {
	if(n==1) {
		move(n, from, to);
		return;
	}

	// Move upper n-1 disks (to aux tower) so that we can pick up the largest disk in "from tower"
	hanoi(n-1, from, aux, to);

	// Move the largest disk in "from tower" to "to tower"
	move(n, from, to);

	// Move the n-1 disks that we transferred to the aux tower to the "to tower"
	hanoi(n-1, aux, to, from);
}

int main() {
	int n;
	cin >> n;
	hanoi(n, 1, 2, 3);
	return  0;
}
