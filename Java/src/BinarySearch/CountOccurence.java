package BinarySearch;

import FastScanner.FastScanner;

import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;

/*
    Count occurence of an element in a sorted array.
    Expects a sorted array.
 */
public class CountOccurence {
    static FastScanner fs;
    static PrintWriter out;
    
    public static int count(int[] a, int key) {
        int lb = LowerBound.lowerBound(a, key);
        int ub = UpperBound.upperBound(a, key);
        return ub - lb;
    }
    
    public static void main(String[] args) {
        fs = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = fs.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = fs.nextInt();
        }
        int x = fs.nextInt();
        Arrays.sort(a);
        out.println(count(a, x));
        out.close();
    }
}
