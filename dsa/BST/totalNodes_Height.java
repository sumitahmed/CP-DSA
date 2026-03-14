// Wap to identify to calculate total no of nodes and height of binary search tree

// Time 20 min

import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class A {
    static int height(Node root) {
        if (root == null) {
            return 0;
        }
        return Math.max(height(root.left), height(root.right)) + 1;
    }

    static int countNode(Node root) {
        if (root == null) {
            return 0;
        }
        return countNode(root.left) + countNode(root.right) + 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root = new Node(5);
        root.left = new Node(3);
        root.right = new Node(10);
        root.left.left = new Node(1);
        root.right.left = new Node(7);

        System.out.println("Height of the tree: " + height(root));
        System.out.println("Total number of nodes: " + countNode(root));
        sc.close();
    }
}