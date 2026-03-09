import java.util.Scanner;

class QueueMenu {

    static final int SIZE = 5;

    static int[] queue = new int[SIZE];
    static int front = -1;
    static int rear = -1;

    static void enqueue(Scanner sc)
    {
        if (rear == SIZE - 1)
        {
            System.out.println("Queue Overflow");
            return;
        }

        System.out.print("Enter element: ");
        int item = sc.nextInt();

        if (front == -1 || front > rear)
            front = rear = 0;
        else
            rear = rear + 1;

        queue[rear] = item;
    }

    static void dequeue()
    {
        if (front == -1 || front > rear)
        {
            System.out.println("Queue Underflow");
            return;
        }

        System.out.println("Deleted element: " + queue[front]);
        front = front + 1;
    }

    static void peek()
    {
        if (front == -1 || front > rear)
        {
            System.out.println("Queue Underflow");
            return;
        }

        System.out.println("Front element: " + queue[front]);
    }

    static void display()
    {
        if (front == -1 || front > rear)
        {
            System.out.println("Queue Underflow");
            return;
        }

        System.out.print("Queue elements: ");

        for (int i = front; i <= rear; i++)
            System.out.print(queue[i] + " ");

        System.out.println();
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int choice;

        while (true)
        {
            System.out.println("\nQUEUE MENU");
            System.out.println("1. Enqueue");
            System.out.println("2. Dequeue");
            System.out.println("3. Peek");
            System.out.println("4. Display");
            System.out.println("5. Exit");

            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice)
            {
                case 1:
                    enqueue(sc);
                    break;

                case 2:
                    dequeue();
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
                    System.out.println("Invalid choice");
            }
        }
    }
}