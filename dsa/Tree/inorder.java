// repeat step 2-4 while tree!= null
//      inorder(tree->left)
//      inorder(tree->data)
//      inorder(tree->right)
// end

import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    public Node(int item) {
        data = item;
        left = right = null;
    }
}

class BinarySearchTree {
    Node root;

    // Logic: Standard BST Insertion
    Node insert(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }
        if (data < root.data)
            root.left = insert(root.left, data);
        else if (data > root.data)
            root.right = insert(root.right, data);
        
        return root;
    }

    // ALGO: Inorder (Left -> Data -> Right)
    void inorder(Node tree) {
        if (tree != null) {
            inorder(tree.left);
            System.out.print(tree.data + " ");
            inorder(tree.right);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BinarySearchTree bst = new BinarySearchTree();

        System.out.print("Enter number of nodes: ");
        int n = sc.nextInt();

        System.out.println("Enter " + n + " values to build the BST:");
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            bst.root = bst.insert(bst.root, val);
        }

        System.out.println("\nInorder traversal result (Sorted Order):");
        bst.inorder(bst.root);
        
        sc.close();
    }
}