// Sample input
// 6289
// Output
// six two eight nine
// Sample input
// 3345
// Output
// double three four five

// Sample input
// 2222234
// triple two double two three four

import java.util.*;

class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        int count = 1;

        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && s.charAt(i) == s.charAt(i + 1)) {
                count++;
            } else {
                if (count > 1) {
                    System.out.print(countWord(count) + " ");
                }

                char ch = s.charAt(i);

                if (ch == '0') System.out.print("zero ");
                else if (ch == '1') System.out.print("one ");
                else if (ch == '2') System.out.print("two ");
                else if (ch == '3') System.out.print("three ");
                else if (ch == '4') System.out.print("four ");
                else if (ch == '5') System.out.print("five ");
                else if (ch == '6') System.out.print("six ");
                else if (ch == '7') System.out.print("seven ");
                else if (ch == '8') System.out.print("eight ");
                else System.out.print("nine ");

                count = 1;
            }
        }
    }

    static String countWord(int c) {
        if (c == 2) return "double";
        if (c == 3) return "triple";
        if (c == 4) return "quadruple";
        if (c == 5) return "quintuple";
        if (c == 6) return "sextuple";
        if (c == 7) return "septuple";
        if (c == 8) return "octuple";
        if (c == 9) return "nonuple";
        return c + " times";
    }
}