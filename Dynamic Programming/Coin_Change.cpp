#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
	int n; // number of coin types
	cin >> n;
	int v[n];
	for(int i=0;i<n;i++)
		cin >> v[i];
	int S; // required sum / given total
	cin >> S;

	// Backward dp
	int dp[S+1]; // dp[i] = min number of coins to get total i
	dp[0] = 0;
	for(int i=1;i<=S;i++) {
		int minc = INT_MAX;
		for(int j=0;j<n;j++) {
			if(i-v[j]>=0)
				minc = min(minc, dp[i-v[j]]+1);
		}
		dp[i] = (minc==INT_MAX?-1:minc);
	}
	cout << dp[S] << "\n";
	
	// Forward dp
	int dp2[S+1];
	for(int i=1;i<=S;i++)
		dp2[i] = INT_MAX;
	dp2[0] = 0;
	for(int i=0;i<=S;i++) {
		for(int j=0;j<n;j++) {
			if(i+v[j] <= S)
				dp2[i+v[j]] = min(dp2[i+v[j]], dp2[i]+1);
		}
	}
	cout << dp2[S] << "\n";

}
