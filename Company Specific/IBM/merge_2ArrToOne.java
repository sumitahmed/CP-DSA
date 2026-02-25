// Write a function merge_sorted_arrays that takes two sorted arrays and merges them into a single sorted array.

// Sample input
// 1 3 5
// 2 4
// Output
// 1 2 3 4 5

import java.util.*;

class A {
    static int[] merge_sorted_arrays(int[] a, int[] b) {
        int i = 0, j = 0, k = 0;
        int[] res = new int[a.length + b.length];

        while (i < a.length && j < b.length) {
            if (a[i] <= b[j]) {
                res[k++] = a[i++];
            } else {
                res[k++] = b[j++];
            }
        }

        while (i < a.length) {
            res[k++] = a[i++];
        }

        while (j < b.length) {
            res[k++] = b[j++];
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();

        int m = sc.nextInt();
        int[] b = new int[m];
        for (int i = 0; i < m; i++) b[i] = sc.nextInt();

        int[] ans = merge_sorted_arrays(a, b);

        for (int x : ans) {
            System.out.print(x + " ");
        }
    }
}