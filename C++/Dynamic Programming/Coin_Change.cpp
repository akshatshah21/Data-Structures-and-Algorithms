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
	vector<int> coins;
	int transition_coin[S+1]={0};
	for(int i=1;i<=S;i++) {
		int minc = INT_MAX, mini=-1;
		for(int j=0;j<n;j++) {
			if(i-v[j]>=0 && minc > dp[i-v[j]]+1) {
				minc = dp[i-v[j]]+1;
				mini = j;
			}
		}
		if(minc != INT_MAX) {
			dp[i] = minc;
			transition_coin[i] = v[mini];
		}
		else
			dp[i] = -1;
	}
	cout << dp[S] << "\n"; // -1 => not possible
	if(dp[S] != -1)
		for(int i=S, j=0;i>0;j++) {
			cout << transition_coin[i] << " ";
			i -= transition_coin[i];
		}
	cout << "\n";
	
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
	cout << dp2[S] << "\n"; // INT_MAX => not possible


}
