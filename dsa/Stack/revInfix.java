// Write a program to reverse an infix expression 
// Without using build function 

// Time 15 min

import java.util.Scanner;

class A {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        String infix = sc.nextLine();

        int n = infix.length();
        char exp[] = new char[n];

        for (int i = 0; i < n; i++) {
            exp[i] = infix.charAt(i);
        }

        int i = 0;
        int j = n - 1;

        while (i < j) {
            char temp = exp[i];
            exp[i] = exp[j];
            exp[j] = temp;
            i++;
            j--;
        }

        for (i = 0; i < n; i++) {
            if (exp[i] == '(')
                exp[i] = ')';
            else if (exp[i] == ')')
                exp[i] = '(';
        }

        for (i = 0; i < n; i++) {
            System.out.print(exp[i]);
        }

        sc.close();
    }
}
