import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedListMenu {

    static Node start = null;

    /* ================= TRAVERSAL ================= */

    static void traverse() {
        Node ptr = start;

        if (ptr == null) {
            System.out.println("List is Empty");
            return;
        }

        while (ptr != null) {
            System.out.print(ptr.data + " -> ");
            ptr = ptr.next;
        }
        System.out.println("NULL");
    }

    /* ================= INSERT AT FIRST ================= */

    static void insertAtFirst(int item) {
        Node newnode = new Node(item);
        newnode.next = start;
        start = newnode;
    }

    /* ================= INSERT AT LAST ================= */

    static void insertAtLast(int item) {
        Node newnode = new Node(item);

        if (start == null) {
            start = newnode;
            return;
        }

        Node ptr = start;
        while (ptr.next != null) {
            ptr = ptr.next;
        }

        ptr.next = newnode;
    }

    /* ================= INSERT AFTER VALUE ================= */

    static void insertAfter(int val, int item) {
        Node ptr = start;

        while (ptr != null && ptr.data != val) {
            ptr = ptr.next;
        }

        if (ptr == null) {
            System.out.println("Value not found");
            return;
        }

        Node newnode = new Node(item);
        newnode.next = ptr.next;
        ptr.next = newnode;
    }

    /* ================= INSERT BEFORE VALUE ================= */

    static void insertBefore(int val, int item) {

        if (start == null)
            return;

        if (start.data == val) {
            insertAtFirst(item);
            return;
        }

        Node ptr = start;

        while (ptr.next != null && ptr.next.data != val) {
            ptr = ptr.next;
        }

        if (ptr.next == null) {
            System.out.println("Value not found");
            return;
        }

        Node newnode = new Node(item);
        newnode.next = ptr.next;
        ptr.next = newnode;
    }

    /* ================= DELETE FIRST ================= */

    static void deleteFirst() {

        if (start == null) {
            System.out.println("Underflow");
            return;
        }

        start = start.next;
    }

    /* ================= DELETE LAST ================= */

    static void deleteLast() {

        if (start == null) {
            System.out.println("Underflow");
            return;
        }

        if (start.next == null) {
            start = null;
            return;
        }

        Node ptr = start;

        while (ptr.next.next != null) {
            ptr = ptr.next;
        }

        ptr.next = null;
    }

    /* ================= DELETE AFTER VALUE ================= */

    static void deleteAfter(int val) {

        Node ptr = start;

        while (ptr != null && ptr.data != val) {
            ptr = ptr.next;
        }

        if (ptr == null || ptr.next == null) {
            System.out.println("Deletion not possible");
            return;
        }

        ptr.next = ptr.next.next;
    }

    /* ================= DELETE BY VALUE ================= */

    static void deleteByValue(int val) {

        if (start == null) {
            System.out.println("Underflow");
            return;
        }

        if (start.data == val) {
            start = start.next;
            return;
        }

        Node ptr = start;

        while (ptr.next != null && ptr.next.data != val) {
            ptr = ptr.next;
        }

        if (ptr.next == null) {
            System.out.println("Value not found");
            return;
        }

        ptr.next = ptr.next.next;
    }

    /* ================= DELETE BEFORE VALUE ================= */

    static void deleteBefore(int val) {

        if (start == null || start.next == null)
            return;

        if (start.next.data == val) {
            start = start.next;
            return;
        }

        Node preptr = null;
        Node ptr = start;
        Node nextptr = start.next;

        while (nextptr != null && nextptr.data != val) {
            preptr = ptr;
            ptr = nextptr;
            nextptr = nextptr.next;
        }

        if (nextptr == null) {
            System.out.println("Value not found");
            return;
        }

        if (preptr == null)
            start = nextptr;
        else
            preptr.next = nextptr;
    }

    /* ================= MENU DRIVER ================= */

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int choice, item, val;

        while (true) {

            System.out.println("\n===== LINKED LIST MENU =====");
            System.out.println("1. Traverse");
            System.out.println("2. Insert at First");
            System.out.println("3. Insert at Last");
            System.out.println("4. Insert After Value");
            System.out.println("5. Insert Before Value");
            System.out.println("6. Delete First");
            System.out.println("7. Delete Last");
            System.out.println("8. Delete After Value");
            System.out.println("9. Delete By Value");
            System.out.println("10. Delete Before Value");
            System.out.println("11. Exit");
            System.out.print("Enter choice: ");

            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    traverse();
                    break;

                case 2:
                    System.out.print("Enter value: ");
                    item = sc.nextInt();
                    insertAtFirst(item);
                    break;

                case 3:
                    System.out.print("Enter value: ");
                    item = sc.nextInt();
                    insertAtLast(item);
                    break;

                case 4:
                    System.out.print("Insert after value: ");
                    val = sc.nextInt();
                    System.out.print("Enter new value: ");
                    item = sc.nextInt();
                    insertAfter(val, item);
                    break;

                case 5:
                    System.out.print("Insert before value: ");
                    val = sc.nextInt();
                    System.out.print("Enter new value: ");
                    item = sc.nextInt();
                    insertBefore(val, item);
                    break;

                case 6:
                    deleteFirst();
                    break;

                case 7:
                    deleteLast();
                    break;

                case 8:
                    System.out.print("Delete after value: ");
                    val = sc.nextInt();
                    deleteAfter(val);
                    break;

                case 9:
                    System.out.print("Delete value: ");
                    val = sc.nextInt();
                    deleteByValue(val);
                    break;

                case 10:
                    System.out.print("Delete before value: ");
                    val = sc.nextInt();
                    deleteBefore(val);
                    break;

                case 11:
                    System.exit(0);

                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}
