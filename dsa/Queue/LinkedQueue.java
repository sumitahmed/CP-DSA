import java.util.Scanner;

class Node
{
    int data;
    Node next;
}

public class LinkedQueue
{
    static Node front = null;
    static Node rear = null;

    static void enqueue(int item)
    {
        Node newnode = new Node();

        newnode.data = item;
        newnode.next = null;

        if (front == null)
        {
            front = rear = newnode;
        }
        else
        {
            rear.next = newnode;
            rear = newnode;
        }
    }

    static void dequeue()
    {
        if (front == null)
        {
            System.out.println("Queue Underflow");
            return;
        }

        Node ptr = front;
        System.out.println("Deleted element: " + ptr.data);

        front = front.next;

        if (front == null)
            rear = null;

        ptr = null;
    }

    static void display()
    {
        if (front == null)
        {
            System.out.println("Queue Underflow");
            return;
        }

        Node ptr = front;

        System.out.print("Queue elements: ");

        while (ptr != null)
        {
            System.out.print(ptr.data + " ");
            ptr = ptr.next;
        }

        System.out.println();
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int choice, item;

        while (true)
        {
            System.out.println("\nLINKED QUEUE MENU");
            System.out.println("1. Insert");
            System.out.println("2. Delete");
            System.out.println("3. Display");
            System.out.println("4. Exit");

            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice)
            {
                case 1:
                    System.out.print("Enter element: ");
                    item = sc.nextInt();
                    enqueue(item);
                    break;

                case 2:
                    dequeue();
                    break;

                case 3:
                    display();
                    break;

                case 4:
                    System.exit(0);

                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}