// Write a Program to return the nth row of Pascal's triangle.

// Sample input
// 5
// Output
// 1 5 10 10 5 1

import java.util.*;
class A{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int val=1;
        for(int k=0;k<=n;k++){
            System.out.print(val+" ");
            val=val*(n-k)/(k+1);
        }
    }
}