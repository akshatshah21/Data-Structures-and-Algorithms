package BinarySearch;

import FastScanner.FastScanner;

import java.io.BufferedOutputStream;
import java.io.PrintWriter;

/*
    Standard Binary Search, returns whether key exists in the array or not
    Expects a sorted array as input
 */
public class BinarySearch {
    static PrintWriter out;
    
    public static boolean search(int[] a, int key) {
        int lo = 0, hi = a.length-1, mid;
        while(lo <= hi) {
            mid = lo + (hi-lo)/2;
            if(a[mid] == key) {
                return true;
            } else if(a[mid] < key) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return false;
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
        if(search(a, x)) {
            out.println("Key " + x + " exists in given array");
        } else {
            out.println("Key " + x + " does not exist in given array");
        }
        
        out.close();
    }
}
