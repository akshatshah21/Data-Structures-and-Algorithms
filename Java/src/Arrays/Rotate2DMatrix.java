package Arrays;

import FastScanner.FastScanner;

import java.io.BufferedOutputStream;
import java.io.PrintWriter;

/*
    Rotate a NxN matrix by 90 deg anticlockwise
    Do this in-place
 */
public class Rotate2DMatrix {
    static PrintWriter out;

    public static void rotate(int[][] a) {
        int n = a.length;
        // Take transpose
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int t = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = t;
            }
        }
        
        // Reverse all columns
        // If we needed to rotate by 90 deg clockwise, we would reverse all rows
        for (int j = 0; j < n; j++) {
            for(int i=0, k=n-1; i<k; i++, k--) {
                int t = a[i][j];
                a[i][j] = a[k][j];
                a[k][j] = t;
            }
        }
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = fs.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = fs.nextInt();
            }
        }
        
        rotate(a);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out.print(a[i][j] + " ");
            }
            out.println();
        }
        out.close();
    }
}
