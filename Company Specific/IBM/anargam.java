// Write a program to check if two strings are anagrams (contain the same characters with the same frequency, ignoring case). Return true if they are anagrams, false otherwise.
// Example: 
// Input: 
// listen 
// silent

// Output: true

import java.util.*;

class A {
    public boolean isAnagram(String s, String t) {
        s = s.toLowerCase();
        t = t.toLowerCase();

        if (s.length() != t.length()) {
            return false;
        }

        char a[] = s.toCharArray();
        char b[] = t.toCharArray();

        Arrays.sort(a);
        Arrays.sort(b);

        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.nextLine();
        String t = sc.nextLine();

        A obj = new A();
        System.out.println(obj.isAnagram(s, t));
    }
}