#include<algorithm>

class Solution {
public:
	bool check_2_sum(int a[], int n, int k) {
		sort(a, a+n);
		int front = 0, end = n-1;
		while(front < end) {
			if(a[front] + a[end] == k) {
				return true;
			} else if(a[front] + a[end] > k) {
				end--;
			} else {
				front++;
			}
		}
		return false;
	}
};
