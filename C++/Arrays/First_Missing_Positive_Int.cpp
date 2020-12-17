/**
 * Given an array of integers, find the first missing positive
 * integer in linear time and constant space. In other words,
 * find the lowest positive integer that does not exist in the
 * array. The array can contain duplicates and negative numbers
 * Input: 
 * n
 * a1 a2 a3 ... an
 */

#include<iostream>
using namespace std;

int f(int a[], int n) {
	for(int i=0; i<n; i++) {
		if(a[i] <= 0 || a[i] > n || a[i] == i+1) continue;
		if(a[i] == a[a[i]-1]) a[i] = -a[i];
		else if(a[a[i]-1] <= 0 || a[a[i]-1] > n) a[a[i]-1] = a[i];
		else {
			swap(a[i], a[a[i]-1]);
			i--;
		}
	}
	for(int i=0; i<n; i++) {
		if(a[i] != i+1) return (i+1);
	}
	return n+1;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	cout << f(a, n) << '\n';
}
