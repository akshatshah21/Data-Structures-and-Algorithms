package BinarySearch;

import FastScanner.FastScanner;

import java.io.BufferedOutputStream;
import java.io.PrintWriter;

/*
    Find the first element in array that is greater than or equal to key
    Return n if such an element does not exist
 */
public class LowerBound {
    static PrintWriter out;
    
    public static int lowerBound(int[] a, int key) {
        int lo = 0, hi = a.length-1, mid, ans = a.length;
        while(lo <= hi) {
            mid = lo + (hi-lo)/2;
            if(a[mid] >= key) {
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
    
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
    
        int n = fs.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = fs.nextInt();
        }
        int x = fs.nextInt();
    
        out.println(lowerBound(a, x));
    
        out.close();
    }
}
