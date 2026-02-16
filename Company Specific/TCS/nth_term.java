// 0,2,1,3,1,5,2,7,3,11,5…………

// This series is a mixture of two series

// Find the nth term of the series


// Sample input
// 14
// Output
// 17

// Sample input
// 13
// Output
// 8

import java.util.*;

class A {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int result = 0;

        if (n % 2 == 1) {
            int k = (n + 1) / 2 - 1;
            int a = 0, b = 1;
            if (k == 0) result = 0;
            else if (k == 1) result = 1;
            else {
                for (int i = 2; i <= k; i++) {
                    int c = a + b;
                    a = b;
                    b = c;
                }
                result = b;
            }
        } else {
            int k = n / 2;
            int count = 0, num = 1;
            while (count < k) {
                num++;
                boolean prime = true;
                if (num == 2 || num == 3) prime = true;
                else if (num % 2 == 0 || num % 3 == 0) prime = false;
                else {
                    for (int i = 5; i * i <= num; i += 6) {
                        if (num % i == 0 || num % (i + 2) == 0) {
                            prime = false;
                            break;
                        }
                    }
                }
                if (prime) count++;
            }
            result = num;
        }

        System.out.println(result);
    }
}