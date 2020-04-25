#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[n]; // if string, use string
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int fall = n-2;
	/* Find the first element from the right (rightmost element)
	 * that breaks the NON-DECREASING pattern
	 * Let 'fall' be its index.
	 * >= because NON-DECREASING, not just increasing. Adjacent equal elements don't break the pattern */
	while(fall >= 0 && arr[fall] >= arr[fall+1]) 
		fall--;
	if(fall == -1) {
		cout << "Given permutation is lexicographically greatest\n";
		return 0;
	}

	/* Find the smallest element larger than arr[fall],
	 * in the range [fall+1, n-1].
	 * A little thought would tell you that we need this exact
	 * element to be placed at index fall for the next permutation.
	 * Use binary search for this, since the elements
	 * after fall are already sorted in non-increasing order
	 */
	int replace_w = -1;
	int low = fall+1, high = n-1;
	int mid;
	while(low <= high) {
		mid = low + (high-low)/2;
		if(arr[mid] <= arr[fall])
			high = mid-1;
		else {
			low = mid+1;
			/* >= in the if below is important. E.g. 324441.
			 * We need to send the fall element farthest 
			 * possible to the right (after all elements greater 
			 * than it), so that when we reverse the array later,
			 * we have the lexicographically smallest next permutation.
			 */
			if(replace_w == -1 || arr[replace_w] >= arr[mid])
				replace_w = mid;
		}
	}
	swap(arr[fall], arr[replace_w]);

	/* Sort arr[fall+1, n-1]
	 * But we can simply reverse the array because elements in
	 * the range[fall+1, n-1] are in non-increasing order
	 */
	for(int i=fall+1; i<=(n+fall)/2;i++) {
		swap(arr[i], arr[n-i+fall]);
	}

	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}

// In C++, there is a function next_permutation(start, end) which does this to an array/string inplace. If no such permutation is possible, then it returns false. Else it returns true.
// SPOJ Question based on next permutation: https://www.spoj.com/problems/JNEXT/
