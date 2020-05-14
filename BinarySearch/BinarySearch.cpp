#include<iostream>
using namespace std;
int main() {
	int n;
	cout << "Enter number of numbers:";
	cin >> n;
	int arr[n];
	cout << "Enter numbers (sorted in ascending order):";
	for(int i=0;i<n;i++)	cin >> arr[i];
	int item;
	cout << "Enter value to be searched:";
	cin >> item;
	int low = 0;
	int high = n;
	int mid;
	bool f = false;
	while(low < high) {
		mid = (low+high) / 2;
		if(arr[mid] == item)	{f = true; break;}
		else if(item < arr[mid])	high = mid;
		else	low = mid + 1;
	}
	if(f)
		cout << item << " found at position " << mid+1 << endl;
	else	cout << "Not found\n";
	return 0;
}
