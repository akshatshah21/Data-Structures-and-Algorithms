#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int upper_bound(int a[], int low, int high, int key) {
	while(low < high) {
		int mid = low + (high-low)/2;
		if(a[mid] <= key)
			low = mid+1;
		else
			high = mid;
	}
	return low;
}

vector<int> lis(int a[], int n) {
	int d[n+1], p[n+1], pos[n+1];
	d[0] = INT_MIN, p[0]=-1, pos[0] = -1;
	for(int i=1;i<n+1;i++) {
		p[i] = -1;
		d[i] = INT_MAX;
		pos[i] = -1;
	}
	for(int i=0;i<n;i++) {
		int j = upper_bound(d, 0, n, a[i]);
		if(d[j-1] < a[i] && a[i] < d[j]) {
			d[j] = a[i];
			pos[j] = i;
			p[i] = pos[j-1];
		}
	}

	int len=1;
	for(int i=1;i<n+1;i++)
		if(d[i] < INT_MAX)
			len = i;
	vector<int> ans(len, 0);
	int ptr = pos[len];
	int bp = len-1;
	while(ptr != -1) {
		ans[bp--] = a[ptr];
		ptr = p[ptr];
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	vector<int> LIS = lis(a, n);
	cout << "LIS length: " << LIS.size() << "\n";
	for(auto i: LIS)
		cout << i << " ";
	cout << "\n";
	return 0;
}
