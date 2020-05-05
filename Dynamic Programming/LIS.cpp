// https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
#include<iostream>
#include<vector>
using namespace std;
vector<int> lis(int a[], int n) {
	int d[n], p[n];
	int maxl = 1, maxi=0;
	for(int i=0;i<n;i++) {
		d[i] = 1; p[i]=-1;
		for(int j=0;j<i;j++) {
			if(a[i] > a[j]) { // condition for "increasing" part
				if(d[i] < d[j]+1) { // condition for "longest" part
					d[i] = d[j]+1; 
					p[i] = j; // for storing parent to retrace later
				}
			}
		}
		if(maxl < d[i]) {
			maxl = d[i];
			maxi = i;
		}
	}
	vector<int> LIS(maxl, 0);
	int ptr=maxi, bp=maxl-1;
	while(ptr != -1) {
		LIS[bp--] = a[ptr];
		ptr = p[ptr];
	}
	return LIS;
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	vector<int> LIS = lis(a, n);
	cout << "LIS length: " << LIS.size() << "\n";
	cout << "LIS: ";
	for(auto i: LIS)
		cout << i << " ";
	cout << "\n";

}
