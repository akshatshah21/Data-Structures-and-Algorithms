#include<iostream>
using namespace std;
#define EPS 0.00001
double sqrt(double n) {
	double lo = 0, hi = n/2+1;
	double mid, sq;
	while(hi-lo > EPS) {
		mid = lo + (hi-lo)/2;
		sq = mid * mid;
		if(sq < n)
			lo = mid;
		else
			hi = mid;
	}
	return lo + (hi-lo)/2;
}

int main() {
	double n;
	cin >> n;
	cout << sqrt(n) << "\n";
	return 0;
}
