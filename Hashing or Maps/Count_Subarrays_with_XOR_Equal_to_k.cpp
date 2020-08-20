#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	map<int, int> m; // count of XOR values
	int x = 0;
	m[0] = 1; // necessary if any prefix has XOR = k
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x ^= a[i]; // prefix XOR
		// if (x^k) exists in the map, add its count,
		// since that will count the number of starting positions,
		// and i is the ending position for subarray with XOR = k
		ans += m[x ^ k];
		m[x]++; // maintain the count map
	}
	cout << ans << '\n';
	return 0;
}

