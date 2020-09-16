package Arrays;


import FastScanner.FastScanner;

import java.io.BufferedOutputStream;
import java.io.PrintWriter;

/*
    Find the next lexicographically smallest permutation of the given array
 */
public class NextPermutation {
    static PrintWriter out;

    private static void findNextPermutation(int[] a) {
       int i= a.length - 2;
       // Find the first element from behind which does not follow the
       // ascending order (as viewed from right)
       while(i >= 0 && a[i] >= a[i+1]) {
           i--;
       }
       // if i == -1, then the array is sorted in descending order
       if(i != -1) {

           // Binary Search for smallest element > a[i] in a[i+1...n-1]
           int ans =- 1, lo = i+1, hi = a.length-1, mid;
           while(lo <= hi) {
               mid = lo + (hi-lo)/2;
               if(a[mid] > a[i]) {
                   ans = mid;
                   lo = mid+1;
               } else {
                   hi = mid-1;
               }
           }
           // Note that ans != -1, always, since that is how we defined 'i' above
           // Swap a[i] and a[ans]
           int t = a[i];
           a[i] = a[ans];
           a[ans] = t;
       }
       // Reverse a[i+1...n-1] (Note that this works for i=-1 too)
       for(int j=i+1, k=a.length-1; j<k; j++, k--) {
           int t = a[j];
           a[j] = a[k];
           a[k] = t;
       }
    }

    public static void main(String[] args)  {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = fs.nextInt();
        }
        findNextPermutation(a);
        for (int i = 0; i < n; i++) {
            out.print(a[i]+ " ");
        }
        out.println();
        out.close();
    }
}
