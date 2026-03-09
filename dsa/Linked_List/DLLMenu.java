import java.util.Scanner;

class Node {
    int data;
    Node prev;
    Node next;
}

public class DLLMenu {

    static Node start = null;

    static void traverse() {

        Node ptr = start;

        if(start == null) {
            System.out.println("List is empty");
            return;
        }

        while(ptr != null) {
            System.out.print(ptr.data+" ");
            ptr = ptr.next;
        }
        System.out.println();
    }

    static void insertBegin(int val) {

        Node newNode = new Node();

        newNode.data = val;
        newNode.prev = null;
        newNode.next = start;

        if(start != null)
            start.prev = newNode;

        start = newNode;
    }

    static void insertEnd(int val) {

        Node newNode = new Node();
        newNode.data = val;
        newNode.next = null;

        if(start == null) {
            newNode.prev = null;
            start = newNode;
            return;
        }

        Node ptr = start;

        while(ptr.next != null)
            ptr = ptr.next;

        ptr.next = newNode;
        newNode.prev = ptr;
    }

    static void insertAfter(int num,int val) {

        Node ptr = start;

        while(ptr != null && ptr.data != num)
            ptr = ptr.next;

        if(ptr == null) {
            System.out.println("Value not found");
            return;
        }

        Node newNode = new Node();

        newNode.data = val;
        newNode.next = ptr.next;
        newNode.prev = ptr;

        if(ptr.next != null)
            ptr.next.prev = newNode;

        ptr.next = newNode;
    }

    static void insertBefore(int num,int val) {

        Node ptr = start;

        while(ptr != null && ptr.data != num)
            ptr = ptr.next;

        if(ptr == null) {
            System.out.println("Value not found");
            return;
        }

        Node newNode = new Node();

        newNode.data = val;
        newNode.prev = ptr.prev;
        newNode.next = ptr;

        if(ptr.prev != null)
            ptr.prev.next = newNode;
        else
            start = newNode;

        ptr.prev = newNode;
    }

    static void deleteBegin() {

        if(start == null) {
            System.out.println("UNDERFLOW");
            return;
        }

        start = start.next;

        if(start != null)
            start.prev = null;
    }

    static void deleteEnd() {

        if(start == null) {
            System.out.println("UNDERFLOW");
            return;
        }

        if(start.next == null) {
            start = null;
            return;
        }

        Node ptr = start;

        while(ptr.next != null)
            ptr = ptr.next;

        ptr.prev.next = null;
    }

    static void deleteAfter(int num) {

        Node ptr = start;

        while(ptr != null && ptr.data != num)
            ptr = ptr.next;

        if(ptr == null || ptr.next == null) {
            System.out.println("Deletion not possible");
            return;
        }

        Node temp = ptr.next;

        ptr.next = temp.next;

        if(temp.next != null)
            temp.next.prev = ptr;
    }

    static void deleteBefore(int num) {

        Node ptr = start;

        while(ptr != null && ptr.data != num)
            ptr = ptr.next;

        if(ptr == null || ptr.prev == null) {
            System.out.println("Deletion not possible");
            return;
        }

        Node temp = ptr.prev;

        if(temp.prev != null)
            temp.prev.next = ptr;
        else
            start = ptr;

        ptr.prev = temp.prev;
    }

    static void deleteValue(int num) {

        Node ptr = start;

        while(ptr != null && ptr.data != num)
            ptr = ptr.next;

        if(ptr == null) {
            System.out.println("Value not found");
            return;
        }

        if(ptr.prev != null)
            ptr.prev.next = ptr.next;
        else
            start = ptr.next;

        if(ptr.next != null)
            ptr.next.prev = ptr.prev;
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int ch,val,num;

        while(true) {

            System.out.println("\n1 Traverse\n2 Insert Begin\n3 Insert End\n4 Insert After\n5 Insert Before");
            System.out.println("6 Delete Begin\n7 Delete End\n8 Delete After\n9 Delete Before\n10 Delete Value\n0 Exit");

            ch = sc.nextInt();

            switch(ch) {

                case 1: traverse(); break;

                case 2:
                    val = sc.nextInt();
                    insertBegin(val);
                    break;

                case 3:
                    val = sc.nextInt();
                    insertEnd(val);
                    break;

                case 4:
                    num = sc.nextInt();
                    val = sc.nextInt();
                    insertAfter(num,val);
                    break;

                case 5:
                    num = sc.nextInt();
                    val = sc.nextInt();
                    insertBefore(num,val);
                    break;

                case 6:
                    deleteBegin();
                    break;

                case 7:
                    deleteEnd();
                    break;

                case 8:
                    num = sc.nextInt();
                    deleteAfter(num);
                    break;

                case 9:
                    num = sc.nextInt();
                    deleteBefore(num);
                    break;

                case 10:
                    num = sc.nextInt();
                    deleteValue(num);
                    break;

                case 0:
                    return;
            }
        }
    }
}