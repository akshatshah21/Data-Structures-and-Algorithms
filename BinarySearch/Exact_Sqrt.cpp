#include<iostream>
using namespace std;

int sqrt(int n) {
	if(n == 0 || n == 1)
		return n;
	int lo = 1, hi = n/2, mid, sq;
	while(lo <= hi) {
		mid = lo + (hi-lo)/2;
		sq = mid * mid;
		if(sq == n)
			return mid;
		else if(sq < n)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	cout << sqrt(n) << endl;
	return 0;
}
