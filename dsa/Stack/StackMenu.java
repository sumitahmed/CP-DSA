import java.util.Scanner;

class Node
{
    int data;
    Node next;

    Node(int data)
    {
        this.data = data;
        this.next = null;
    }
}

public class StackMenu
{
    static Node top = null;
    static Scanner sc = new Scanner(System.in);

    static void push()
    {
        System.out.print("Enter element: ");
        int item = sc.nextInt();

        Node newNode = new Node(item);

        newNode.next = top;
        top = newNode;
    }

    static void pop()
    {
        if(top == null)
        {
            System.out.println("Stack Underflow");
            return;
        }

        System.out.println("Deleted element: " + top.data);
        top = top.next;
    }

    static void peek()
    {
        if(top == null)
        {
            System.out.println("Stack Underflow");
            return;
        }

        System.out.println("Top element: " + top.data);
    }

    static void display()
    {
        Node ptr = top;

        if(ptr == null)
        {
            System.out.println("Stack is Empty");
            return;
        }

        System.out.println("Stack elements:");

        while(ptr != null)
        {
            System.out.println(ptr.data);
            ptr = ptr.next;
        }
    }

    public static void main(String[] args)
    {
        int choice;

        while(true)
        {
            System.out.println("\n--- STACK MENU ---");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Display");
            System.out.println("5. Exit");

            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch(choice)
            {
                case 1:
                    push();
                    break;

                case 2:
                    pop();
                    break;

                case 3:
                    peek();
                    break;

                case 4:
                    display();
                    break;

                case 5:
                    System.exit(0);

                default:
                    System.out.println("Invalid Choice");
            }
        }
    }
}