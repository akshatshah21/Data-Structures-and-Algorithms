#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s; // "IDIDIDDIDD" I --> Inc, D --> Dec
	int n = s.length();
	int ans[n + 1];

	// Keep a range, [1..N], where N = n+1
	// Keep eating away values from left or right, depending on
	// whether the next element is greater than or less than respectively
	int l = 1, r = n + 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'I') {
			ans[i] = l++;
		} else {
			ans[i] = r--;
		}
	}
	ans[n] = l;
	for (int i = 0; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
