class Node
{
int data;
Node left,right;
Node(int d)
{
data=d;left=right=null;
}
}
class A
{
static int countNodes(Node root)
{
if(root==null)
{
return 0;
}
return 1+countNodes(root.left)+countNodes(root.right);
}
static boolean isComplete(Node root,int index,int total)
{
if(root==null)
{
return true;
}
if(index>=total)
{
return false;
}
return isComplete(root.left,2*index+1,total)&&isComplete(root.right,2*index+2,total);
}
static boolean isHeap(Node root)
{
if(root.left==null&&root.right==null)
{
return true;
}
if(root.right==null)return root.data<=root.left.data&&isHeap(root.left);
return root.data<=root.left.data&&root.data<=root.right.data&&isHeap(root.left)&&isHeap(root.right);
}
static boolean isMinHeap(Node root)
{
int totalNodes=countNodes(root);
return isComplete(root,0,totalNodes)&&isHeap(root);
}
public static void main(String[] args)
{
Node root=new Node(5);
root.left=new Node(10);
root.right=new Node(15);
root.left.left=new Node(20);
root.left.right=new Node(25);
root.right.left=new Node(30);
if(isMinHeap(root))
{
System.out.println("The binary tree is a Min Heap");
}
else 
{
System.out.println("The binary tree is NOT a Min Heap");
}
}
}