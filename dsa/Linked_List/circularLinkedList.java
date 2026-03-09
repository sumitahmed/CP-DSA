import java.util.Scanner;

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class CircularLinkedList {

    static Node start = null;

    static void traverse() {

        if(start == null) {
            System.out.println("List empty");
            return;
        }

        Node ptr = start;

        do {
            System.out.print(ptr.data + " ");
            ptr = ptr.next;
        } while(ptr != start);
    }

    static void insertBegin(int item) {

        Node newnode = new Node(item);

        if(start == null) {
            newnode.next = newnode;
            start = newnode;
            return;
        }

        Node ptr = start;

        while(ptr.next != start)
            ptr = ptr.next;

        newnode.next = start;
        ptr.next = newnode;
        start = newnode;
    }

    static void insertEnd(int item) {

        Node newnode = new Node(item);

        if(start == null) {
            newnode.next = newnode;
            start = newnode;
            return;
        }

        Node ptr = start;

        while(ptr.next != start)
            ptr = ptr.next;

        ptr.next = newnode;
        newnode.next = start;
    }

    static void deleteBegin() {

        if(start == null)
            return;

        Node ptr = start;

        while(ptr.next != start)
            ptr = ptr.next;

        if(start.next == start)
            start = null;
        else {
            ptr.next = start.next;
            start = start.next;
        }
    }

    static void deleteEnd() {

        if(start == null)
            return;

        Node ptr = start;
        Node preptr = null;

        if(start.next == start) {
            start = null;
            return;
        }

        while(ptr.next != start) {
            preptr = ptr;
            ptr = ptr.next;
        }

        preptr.next = start;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int choice,item;

        while(true) {

            System.out.println("\n1 Traverse\n2 Insert Begin\n3 Insert End\n4 Delete Begin\n5 Delete End\n6 Exit");

            choice = sc.nextInt();

            switch(choice) {

                case 1: traverse(); break;

                case 2:
                    item = sc.nextInt();
                    insertBegin(item);
                    break;

                case 3:
                    item = sc.nextInt();
                    insertEnd(item);
                    break;

                case 4: deleteBegin(); break;

                case 5: deleteEnd(); break;

                case 6: return;
            }
        }
    }
}