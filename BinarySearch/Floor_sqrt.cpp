#include<iostream>
using namespace std;

int floor_sqrt(int n) {
	if(n == 0)
		return 0;
	int lo = 1, hi = n/2 + 1, mid, sq;
	while(lo < hi) {
		mid = lo + (hi-lo)/2;
		sq = mid * mid;
		if(sq == n)
			return mid;
		else if(sq < n)
			lo = mid+1;
		else
			hi = mid;
	}
	return lo;
}

int main() {
	int n;
	cin >> n;
	cout << floor_sqrt(n) << endl;
	return 0;
}
