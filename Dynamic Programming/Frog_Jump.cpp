#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int h[n];
	for(int i=0;i<n;i++)
		cin >> h[i];
	int dp[n];
	dp[0] = 0;
	dp[1] = abs(h[1]-h[0]);
	int prev[n];
	prev[0]=-1;prev[1]=0;
	for(int i=2;i<n;i++) {
		if(dp[i-1]+abs(h[i]-h[i-1]) < dp[i-2]+abs(h[i]-h[i-2])) {
			dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
			prev[i] = i-1;
		}
		else {
			dp[i] = dp[i-2]+abs(h[i]-h[i-2]);
			prev[i] = i-2;
		}
	}
	cout << dp[n-1] << "\n";
	vector<int> ans;
	int trav = n-1;
	while(trav != -1) {
		ans.push_back(trav);
		trav = prev[trav];
	}
	reverse(ans.begin(), ans.end());
	for(auto i: ans)
		cout << i+1 << " ";
	cout << "\n";
	return 0;
}

