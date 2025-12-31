// Write a program to implement enqueue and de queue  operation of a linear queue by using stack

// Time 20 min
import java.util.Stack;
class Mintu
{
    static class mQueue
    {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        void enqueue(int x)
        {
            while(!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
            s1.push(x);
            while(!s2.isEmpty())
            {
                s1.push(s2.pop());
            }
        }
        void dequeue()
        {
            if(s1.isEmpty())
            {
                return; 
            }
            s1.pop();
        }
        int front()
        {
            if(s1.isEmpty())
            {
                return -1; 
            }
            return s1.peek();
        }
        int size()
        {
            return s1.size();
        }
    }
    public static void main(String args[])
    {
        mQueue q = new mQueue();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        System.out.println("Front: " + q.front()); 
        System.out.println("Size: " + q.size());   
        q.dequeue();
        System.out.println("Front: " + q.front());
        System.out.println("Size: " + q.size());
    }
}