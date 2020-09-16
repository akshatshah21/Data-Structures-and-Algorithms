package Arrays;

import FastScanner.FastScanner;

import java.io.BufferedOutputStream;
import java.io.PrintWriter;

/*
    Find the previous lexicographically largest permutation of the given array
 */
public class PreviousPermutation {
    static PrintWriter out;

    private static void findPreviousPermutation(int[] a) {
        int i = a.length - 2;
        // Find the first element from behind which does not follow
        // the descending order (as viewed from right)
        while(i >= 0 && a[i] <= a[i+1]) {
            i--;
        }

        // If i == -1, then the array is sorted in ascending order
        if(i != -1) {

            // Binary Search for the largest element < a[i] in a[i+1...n-1]
            int lo = i+1, hi = a.length-1, mid, ans = -1;
            while(lo <= hi) {
                mid = lo + (hi-lo)/2;
                if(a[mid] < a[i]) {
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
        //Reverse a[i+1...n-1]. Note that this also works for i == -1
        for(int j=i+1, k=a.length-1; j<k; j++, k--) {
            int t = a[j];
            a[j] = a[k];
            a[k] = t;
        }
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = fs.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = fs.nextInt();
        }
        findPreviousPermutation(a);
        for (int i = 0; i < n; i++) {
            out.print(a[i] + " ");
        }
        out.println();
        out.close();
    }
}
