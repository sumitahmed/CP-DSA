class Node
{
int data;
Node left, right;
Node(int d) 
{
data = d; left = right = null; 
}
}
class A 
{
static int count(Node root)
{
if (root == null)
{
return 0;
}
return 1 + count(root.left) + count(root.right);
}
static boolean isComplete(Node root, int index, int total)
{
if (root == null)
{
return true;
}
if (index >= total)
{
return false;
}
return isComplete(root.left, 2*index + 1, total) && isComplete(root.right, 2*index + 2, total);
}
public static void main(String[] args) 
{
Node root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
if(isComplete(root, 0, count(root)))
{
System.out.println("Complete Binary Tree");
}
else 
{
System.out.println("Not Complete Binary Tree");
}
}
}