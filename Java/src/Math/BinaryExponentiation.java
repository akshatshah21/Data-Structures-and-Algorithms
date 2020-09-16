package Math;

import FastScanner.FastScanner;

import java.io.BufferedOutputStream;
import java.io.PrintWriter;

public class BinaryExponentiation {
    static PrintWriter out;
    
    private static long bexpIterative(long x, int n) {
        long res = 1;
        while(n != 0) {
            if((n&1) == 1) {
                res *= x;
            }
            x = x * x;
            n >>= 1;
        }
        return res;
    }
    
    private static long bexpIterative(long x, int n, int MOD) {
        long res = 1;
        while(n != 0) {
            if((n&1) == 1) {
                res = ((res%MOD) * (x%MOD)) % MOD;
            }
            x = x * x;
            n >>= 1;
        }
        return res;
    }
    
    private static long bexpRecursive(long x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        long p = bexpRecursive(x, n/2);
        if((n&1) == 1) return p*p*x;
        return p*p;
    }
    
    private static long bexpRecursive(int x, int n, int MOD) {
        if(n == 0) return 1;
        if(n == 1) return x;
        long p = bexpRecursive(x, n/2, MOD);
        if((n&1) == 1) {
            return ((p%MOD) * (p%MOD) * (x%MOD)) % MOD;
        }
        return ((p%MOD) * (p%MOD)) % MOD;
    }
    
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int x = fs.nextInt();
        int n = fs.nextInt();
    
        out.println(bexpIterative(x, n));
        out.println(bexpIterative(x, n, (int)1e9+7));
        out.println(bexpRecursive(x, n));
        out.println(bexpRecursive(x, n, (int)1e9+7));
        
        out.close();
    }
}
