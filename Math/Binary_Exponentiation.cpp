#include<iostream>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

// Recursive
ll _bexp(ll x, ll n) {
	if(n == 0) return 1;
	ll p = _bexp(x, n/2);
	if(n&1) return ((p%MOD)*(p%MOD)*(x%MOD))%MOD;
	else return ((p%MOD)*(p%MOD))%MOD;
}

// Iterative
ll bexp(ll x, ll n) {
	ll p = x;
	ll res = 1;
	while(n) {
		if(n&1) res = ((res%MOD)*(p%MOD))%MOD;
		p = ((p%MOD)*(p%MOD))%MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	ll x, n;
	cin >> x >> n;
	cout << bexp(x, n) << '\n';
}
