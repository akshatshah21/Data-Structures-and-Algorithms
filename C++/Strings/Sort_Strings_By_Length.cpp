/**
 * Write a custom compare function to sort strings based on length
 */

#include <iostream>
#include <algorithm>
#include <string>

bool comp(const std::string &a, const std::string &b) {
	return a.length() <= b.length();
}

int main() {
	std::string arr[] = {"This", "is", "a", "string"};
	sort(arr, arr+4, comp);
	for(const std::string &s: arr) std::cout << s << " ";
	std::cout << '\n';
}
