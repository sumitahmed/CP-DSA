class Node
{
int data;
Node left,right;
Node(int d){data=d;left=right=null;
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
if(root.right==null)
{
return root.data>=root.left.data&&isHeap(root.left);
}
return root.data>=root.left.data&&root.data>=root.right.data&&isHeap(root.left)&&isHeap(root.right);
}
static boolean isMaxHeap(Node root)
{
int totalNodes=countNodes(root);
return isComplete(root,0,totalNodes)&&isHeap(root);
}
public static void main(String args[])
{
Node root=new Node(10);
root.left=new Node(9);
root.right=new Node(8);
root.left.left=new Node(7);
root.left.right=new Node(6);
root.right.left=new Node(5);
if(isMaxHeap(root))
{
System.out.println("The binary tree is a Max Heap");
}
else
{
System.out.println("The binary tree is NOT a Max Heap");
}
}
}