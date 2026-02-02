// Write a program to create a binary tree with some values
// Then calculate the height by using one recursive function 

// Time 15 min

import java.util.*;

class Node{
    int data;
    Node left;
    Node right;

    Node(int val){
        data = val;
        left = right =null;
    }
}

class a{
    static int height(Node root){
        if(root==null){
            return 0;
        }

        int leftHeight = height(root.left);
        int rightHeight = height(root.right);

        return Math.max(leftHeight, rightHeight);
    }

    //Inorder traversal
    static void inorder(Node root){
        if(root!=null)
        {
            inorder(root.left);
            System.out.println(root.data+" ");
            inorder(root.right);
        }
    }
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter root value");
        int rootVal = sc.nextInt();
        Node root = new Node(rootVal);

        System.out.println("Enter left child of" + rootVal+ ": ");
        int leftVal = sc.nextInt();
        root.left = new Node(leftVal);

         System.out.println("Enter left child of" + rootVal+ ": ");
        int rightVal = sc.nextInt();
        root.left = new Node(rightVal);
        

        System.out.println("\n Inorder Traversal");
        inorder(root);

        int h = height(root);
        System.out.println("\n Height of Binary Tree:"+h);

        sc.close();
    }
}