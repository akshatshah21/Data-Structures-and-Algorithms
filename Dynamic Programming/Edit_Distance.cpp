#include<iostream>
#include<string>
using namespace std;

int edit_distance(const string &s1,const string &s2) {
	int n = s1.length();
	int m = s2.length();
	// Corner cases get handled by the table too
	// So these aren't necessary
	if(n == 0)
		return m;
	if(m == 0)
		return n;

	int dp[n+1][m+1];
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			int cost;
			if(i==0) {
				dp[0][j] = j;
				continue;
			}
			else if(j==0) {
				dp[i][0] = i;
				continue;
			}
			else if(s1[i-1] == s2[j-1])
				cost = 0;
			else
				cost = 1;
			dp[i][j] = min(min(dp[i][j-1] + 1, 	// Insertion
								dp[i-1][j] + 1),// Deletion
						dp[i-1][j-1] + cost); 	// Swap
		}
	}
	// Print the DP Table
	/* cout << "\n"; */
	/* for(int i=0;i<=n;i++) { */
	/* 	for(int j=0;j<=m;j++) */
	/* 		cout << dp[i][j] << " "; */
	/* 	cout << "\n"; */
	/* } */
	return dp[n][m];
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << "Edit distance: " << edit_distance(s1, s2) << "\n";
	return 0;
}

