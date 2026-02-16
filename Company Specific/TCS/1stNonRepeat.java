// Given a string, find and print the first non-repeating character. If all characters repeat, print '-'

// Input Format:

// Single string
// Output Format:

// Single character: the first non-repeating character, or '-' if none exists
// Example:‍

// Input
// ccbpa

// Output
// b

// Sample input
// bbaa 
// Output
// -

import java.util.*;
class A{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();

        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            if(str.indexOf(ch) == str.lastIndexOf(ch)){
                System.out.println(ch);

                return;
            }
        }
        System.out.println("-");
    }
}