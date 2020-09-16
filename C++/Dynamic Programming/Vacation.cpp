/* Problem link: https://atcoder.jp/contests/dp/tasks/dp_c */


#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pi pair<int, int>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define deb(x) cout << #x << ":" << x << endl;
#define deba(x) cerr << #x << endl; for (auto a : x) cerr << a << " "; cerr << endl;
/* freopen("input.txt", "r", stdin); */
/* freopen("output.txt", "w", stdout); */
const int MOD = 1000000007;


int main() {
	fastio();
	int n;
	cin >> n;
	int a[n], b[n], c[n], dp[n][3];
	for(int i=0;i<n;i++)
		cin >> a[i] >> b[i] >> c[i];
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];
	for(int i=1;i<n;i++) {
		dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
	}
	cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << "\n";
	return 0;
}

