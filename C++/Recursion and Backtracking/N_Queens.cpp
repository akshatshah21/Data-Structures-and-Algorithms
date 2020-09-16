#include<iostream>
using namespace std;
class Position {
public:
	int row, col;
	Position() {
		row = 0, col = 0;
	}
	Position(int row, int col) {
		this -> row = row;
		this -> col = col;
	}
};

void n_queens(int n, int row, Position positions[]) {
	if(row == n) {
		cout << "Solution:\n";
		for(int i=0;i<n;i++)
			cout << positions[i].row << " " << positions[i].col << "\n";
	}
	else {
		for(int col=0;col<n;col++) {
			bool found_safe = true;
			for(int q=0;q<row;q++) {
				if(positions[q].col == col || positions[q].row + positions[q].col == row+col || positions[q].row-positions[q].col == row-col) {
					found_safe = false;
					break;
				}
			}
			if(found_safe) {
				positions[row] = Position(row, col);
				n_queens(n, row+1, positions);
			}
		}
	}
}

int main() {
	Position positions[4];
	n_queens(4, 0, positions);
	return 0;
}
