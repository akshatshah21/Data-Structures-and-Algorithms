#include<iostream>
using namespace std;
#define MOD 1000000007

long long fastpow(long long x, long long n) {
	if(n == 0)
		return 1;
	long long hp = fastpow(x, n/2);
	if(n & 1)
		return ((x%MOD) * (hp%MOD) * (hp%MOD))%MOD;
	else
		return ((hp%MOD) * (hp%MOD))%MOD;
}


int main() {
	long long n;
	cin >> n;
	cout << fastpow(2, n) << "\n";
	return 0;
}

