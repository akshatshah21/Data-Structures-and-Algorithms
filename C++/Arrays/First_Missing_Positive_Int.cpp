/**
 * Given an array of integers, find the first missing positive
 * integer in linear time and constant space. In other words,
 * find the lowest positive integer that does not exist in the
 * array. The array can contain duplicates and negative numbers
 * Input:
 * n
 * a1 a2 a3 ... an
 */

/**
 * LeetCode: https://leetcode.com/problems/first-missing-positive
*/

class Solution {
private:
    int n;
    bool valid(int x) {
        return (x > 0 && x <= n);
    }
public:
    int firstMissingPositive(vector<int>& a) {
        n = a.size();
        for(int i=0; i<n; i++) {
            if(valid(a[i])) {
                if(a[i] == i+1) continue;
                if(a[a[i]-1] == a[i]) {
                    a[i] = 0;
                } else if(!valid(a[a[i]-1])) {
                    a[a[i]-1] = a[i];
                } else {
                    swap(a[i], a[a[i]-1]);
                    i--;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(a[i] != i+1) return (i+1);
        }
        return n+1;
    }
};
