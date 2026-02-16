// Given an array Arr[] of N integers and a positive integer K, cyclically rotate the array clockwise by K.

// Input Format:

// First line: N (number of elements)
// Second line: N space-separated integers (array elements)
// Third line: K (number of rotations)
// Output Format:

// Rotated array as space-separated integers
// Example

// Input
// 5
// 10 20 30 40 50
// 2

// Output
// 40 50 10 20 30

import java.util.*;
class A{
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int arr[] = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }

        int m = sc.nextInt();
        m = m % n;

        int temp[] = new int[n];

        for(int i = 0; i < n; i++){
            temp[(i + m) % n] = arr[i];
        }

        for(int i = 0; i < n; i++){
            System.out.print(temp[i] + " ");
        }
    }
}
