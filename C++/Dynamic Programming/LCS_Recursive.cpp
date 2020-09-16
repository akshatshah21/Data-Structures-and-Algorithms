#include<iostream>
using namespace std;
int memo[100][100];
int lcs(int x[], int y[], int l1, int l2) {
	if(l1==0 || l2==0)
		return 0;
	if(memo[l1][l2] != -1)
		return memo[l1][l2];
	if(x[l1-1] == y[l2-1])
		return 1 + lcs(x, y, l1-1, l2-1);
	return max(lcs(x, y, l1, l2-1), lcs(x, y, l1-1, l2));
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int x[n1], y[n2];
	for(int i=0;i<=n1;i++)
		for(int j=0;j<=n2;j++)
			memo[i][j] = -1;
	for(int i=0;i<n1;i++)
		cin >> x[i];
	for(int i=0;i<n2;i++)
		cin >> y[i];
	cout << "Length of LCS: " << lcs(x, y, n1, n2);
	return 0;
}
