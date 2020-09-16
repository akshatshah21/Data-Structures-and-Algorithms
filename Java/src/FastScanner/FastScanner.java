package FastScanner;

import java.io.*;
import java.util.StringTokenizer;

public class FastScanner {
    BufferedReader bf;
    StringTokenizer st;
    public FastScanner() {
        this.bf = new BufferedReader(new InputStreamReader(System.in));
        this.st = new StringTokenizer("");
    }
    public String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                this.st = new StringTokenizer(this.bf.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return this.st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(this.next());
    }

    public long nextLong() {
        return Long.parseLong(this.next());
    }

    public double nextDouble() {
        return Double.parseDouble(this.next());
    }

    public String nextLine() {
        String str = "";
        try {
            str = this.bf.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    public static void main() {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int t = fs.nextInt();

        for (int x = 0; x < t; x++) {
            int n = fs.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = fs.nextInt();
            }
            out.println("The Array is:");
            for (int i = 0; i < n; i++) {
                out.print(a[i] + " ");
            }
            out.println();
        }
    }
}
