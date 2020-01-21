#include<iostream>
using namespace std;

void reverse(int arr[], int len) {
	for(int i=0;i<len/2;i++) {
		int t = arr[i];
		arr[i] = arr[len-1-i];
		arr[len-i-1] = t;
	}
}

void multiply(int num1[], int n1, int num2[], int n2) {
	reverse(num1, n1);
	reverse(num2, n2);
	int ans[n1+n2] = {0};
	for(int i=0;i<n2;i++) {
		int ansptr = i, carry = 0;
		for(int j=0;j<n1;j++) {
			int prod = num1[j] * num2[i];
			//cout << prod << endl;
			ans[ansptr++] += (prod+carry) % 10;
			carry = (prod+carry)  / 10;
		}
		ans[ansptr] += carry;
		//cout << "i=" << i << endl;
		//for(int k=0;k<n1+n2;k++)	cout << ans[k];
		//cout << endl;
	}
	//cout << "reverse ans:";
	//for(int i=0;i<n1+n2;i++)	cout << ans[i];
	//cout << endl;
	int i = n1 + n2 - 1;
	int len = n1+n2;
	while(ans[i--] == 0)	len--;
	reverse(ans, len);
	for(i=0;i<len;i++)	cout << ans[i];
	cout << endl;
}

int main() {
	int num1[] = {1, 2}, n1 = 2;
	int num2[] = {1, 2}, n2 = 2;
	multiply(num1, n1, num2, n2);
	return 0;
}
