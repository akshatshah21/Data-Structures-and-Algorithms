package BinarySearch;


import FastScanner.FastScanner;

import java.io.BufferedOutputStream;
import java.io.PrintWriter;

/*
    Find the square root of a perfect square
    If given number is not a perfect square, return -1
 */
public class ExactSqrt {
    static FastScanner fs;
    static PrintWriter out;
    
    public static int sqrt(int n) {
        int lo = 0, hi = n/2 + 1, ans = -1, mid;
        while(lo <= hi) {
            mid = lo + (hi-lo)/2;
            if(mid*mid == n) {
                return mid;
            } else if(mid * mid < n) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return -1;
    }
    
    public static void main(String[] args) {
        fs = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = fs.nextInt();
        out.println(sqrt(n));
        out.close();
    }
}
