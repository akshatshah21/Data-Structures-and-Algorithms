#include<iostream>
using namespace std;
int lcs(char x[], char y[], int l1, int l2, char ans[], int *l) {
	int L[l1+1][l2+1];
	for(int i=0;i<=l1;i++) {
		for(int j=0;j<=l2;j++) {
			if(i==0 || j==0)
				L[i][j] = 0;
			else if(x[i-1] == y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}
	int i=l1, j=l2;
	while(i > 0 && j > 0) {
		if(x[i-1] == y[j-1]) {
			ans[(*l)-1] = x[i-1];
			i--;j--;(*l)--;
		}
		else if(L[i-1][j] > L[i][j-1])
			i--;
		else
			j--;
	}

	return L[l1][l2];
}
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	char x[n1], y[n2];
	for(int i=0;i<n1;i++)
		cin >> x[i];
	for(int i=0;i<n2;i++)
		cin >> y[i];
	int l = max(n1, n2);
	int lcopy = l;
	char ans[l];
	cout << "Length of LCS: " << lcs(x, y, n1, n2, ans, &lcopy) << "\n";
	cout << "LCS: ";
	for(int i=lcopy;i<l;i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
