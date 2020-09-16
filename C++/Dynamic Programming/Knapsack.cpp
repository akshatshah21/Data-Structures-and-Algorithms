#include<iostream>
using namespace std;

int main() {
	int n, W;
	cin >> n >> W;
	int v[n+1], w[n+1];
	v[0]=0, w[0]=0;
	for(int i=1;i<=n;i++)
		cin >> w[i] >> v[i];
	int dp[n+1][W+1];
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=W;j++) {
			if(i==0 || j==0)
				dp[i][j] = 0;
			else {
				dp[i][j] = dp[i-1][j];
				if(w[i]<=j)
					dp[i][j] = max(dp[i][j], dp[i-1][ j-w[i] ] + v[i]);
			}
		}
	}
	cout << dp[n][W] << "\n";
	return 0;
}

