// Wap to identify to calculate total no of nodes and height of binary search tree

// Time 20 min

import java.util.*;

class A {
    static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    static Node insert(Node root, int data) {
        if (root == null) {
            return new Node(data);
        }

        if (data < root.data) {
            root.left = insert(root.left, data);
        } else if (data > root.data) {
            root.right = insert(root.right, data);
        }
        return root;
    }

    static int countNodes(Node root) {
        if (root == null) {
            return 0;
        }
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    static int height(Node root) {
        if (root == null) {
            return 0; // height in terms of number of nodes
        }
        return 1 + Math.max(height(root.left), height(root.right));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Node root = null;

        int value1 = sc.nextInt();
        int value2 = sc.nextInt();

        root = insert(root, value1);
        root = insert(root, value2);

        System.out.println("Total number of nodes: " + countNodes(root));
        System.out.println("Height of the tree: " + height(root));

        sc.close();
    }
}