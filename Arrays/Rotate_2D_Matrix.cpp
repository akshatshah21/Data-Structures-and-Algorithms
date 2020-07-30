// Rotate an n x n matrix 90 degrees clockwise

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	int m[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	// First take transpose
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			swap(m[i][j], m[j][i]);
		}
	}

	// Now reverse order of columns
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		for (int k = 0; k < n; k++) {
			swap(m[k][i], m[k][j]);
		}
	}
	// If 90 degrees anticlockwise required, reverse rows after transpose

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << m[i][j] << ' ';
		}
		cout << '\n';
	}
}
