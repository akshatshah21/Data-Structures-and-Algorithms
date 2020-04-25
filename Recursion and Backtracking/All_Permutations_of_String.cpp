#include<iostream>
using namespace std;

/* Recursive function to find all permutations of string s
 * l: left boundary
 * r: right boundary
 */
void permute(int l, int r, string s) {
	// Base case (leaf node in the recursion tree, when l == r)
	if(l == r) {
		cout << s << "\n";
		return;
	}

	// Put all characters from l to r at position l, and then recur over s[l+1:r] (the remaining part)
	// After calling recursive function, return to initial state by again swapping the swapped characters
	for(int i=l;i<=r;i++) {
		swap(s[l], s[i]);
		permute(l+1, r, s);
		swap(s[l], s[i]);
	}
}

int main() {
	string s;
	cin >> s;
	cout << "Permutations:\n";
	permute(0, s.length()-1, s);
	return 0;
}
