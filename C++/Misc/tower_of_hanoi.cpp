#include<iostream>
using namespace std;
void hanoi(int, char, char, char);
int main() {
	char a = 'A', b = 'B', c = 'C';
	int n;
	cout<<"Enter number of disks: ";
	cin>>n;
	hanoi(n, a, c, b);
	return 0;
}

void hanoi(int n, char src, char dest, char aux) {
	if(n==1) {
		cout<<"Move disk 1 from "<<src<< " to "<<dest<<endl;
		return;
	}
	hanoi(n-1, src, aux, dest);
	cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
	hanoi(n-1 , aux, dest, src);
}