#include<iostream>
using namespace std;

int main() {
	int n, W;
	cin >> n >> W;
	int v[n+1], w[n+1];
	v[0]=0, w[0]=0;
	for(int i=1;i<=n;i++)
		cin >> w[i] >> v[i];
	int dp[W+1]={0};
	for(int i=0;i<=n;i++) {
		for(int j=W;j>=1;j--) { // W to 1 is important!
			/* dp[j] = dp[j]; */
			if(w[i]<=j)
				dp[j] = max(dp[j], dp[ j-w[i] ] + v[i]);
		}
	}
	cout << dp[W] << "\n";
	return 0;
}

