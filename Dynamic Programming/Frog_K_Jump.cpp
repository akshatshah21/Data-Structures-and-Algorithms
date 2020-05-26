#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int h[n];
	for(int i=0;i<n;i++)
		cin >> h[i];
	int dp[n];
	dp[0] = 0;
	int prev[n];
	prev[0]=-1;
	for(int i=1;i<n;i++) {
		int minc=INT_MAX, mini=-1;
		for(int j=i-1;j>=max(0, i-k);j--) {
			if(minc > dp[j]+abs(h[i]-h[j])) {
				minc = dp[j]+abs(h[i]-h[j]);
				mini = j;
			}
			dp[i] = minc;
			prev[i] = mini;
		}
	}
	cout << dp[n-1] << "\n";
	vector<int> ans;
	for(int trav = n-1;trav != -1;trav = prev[trav])
		ans.push_back(trav);
	reverse(ans.begin(), ans.end());
	for(auto i: ans)
		cout << i+1 << " ";
	cout << "\n";
	return 0;
}

