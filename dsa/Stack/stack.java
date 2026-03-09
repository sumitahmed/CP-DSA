import java.util.Scanner;

class StackMenu {

    static final int SIZE = 5;
    static int stack[] = new int[SIZE];
    static int top = -1;

    static Scanner sc = new Scanner(System.in);

    static void push() {

        if (top == SIZE - 1) {
            System.out.println("Stack Overflow");
            return;
        }

        System.out.print("Enter element: ");
        int item = sc.nextInt();

        top++;
        stack[top] = item;
    }

    static void pop() {

        if (top == -1) {
            System.out.println("Stack Underflow");
            return;
        }

        System.out.println("Popped element: " + stack[top]);
        top--;
    }

    static void peek() {

        if (top == -1) {
            System.out.println("Stack is Empty");
            return;
        }

        System.out.println("Top element: " + stack[top]);
    }

    static void display() {

        if (top == -1) {
            System.out.println("Stack is Empty");
            return;
        }

        System.out.println("Stack elements:");

        for (int i = top; i >= 0; i--) {
            System.out.println(stack[i]);
        }
    }

    public static void main(String[] args) {

        int choice;

        while (true) {

            System.out.println("\n--- STACK MENU ---");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Display");
            System.out.println("5. Exit");

            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch(choice) {

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