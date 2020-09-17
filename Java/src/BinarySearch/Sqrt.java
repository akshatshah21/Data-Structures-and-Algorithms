package BinarySearch;

import FastScanner.FastScanner;

import java.io.BufferedOutputStream;
import java.io.PrintWriter;

public class Sqrt {
    static FastScanner fs;
    static PrintWriter out;
    public static double EPS = 0.0001;
   
    private static double sqrt(double n) {
        double lo = 0, hi = n/2 + 1, mid = lo;
        while(hi - lo > EPS) {
            mid = lo + (hi-lo)/2;
            double sq = mid * mid;
            if(sq > n) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return mid;
    }
    
    public static void main(String[] args) {
        fs = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        double n = fs.nextDouble();
        out.println(sqrt(n));;
        out.close();
    }
}
