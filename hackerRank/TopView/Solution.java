/*

class Node
int data;
Node left;
Node right;
*/

void topViewLeft(Node root){
  if(root == null)
    return;

  topViewLeft(root.left);

  System.out.print(root.data);
  System.out.print(' ');
}

void topViewRight(Node root){
  if(root == null)
    return;

  System.out.print(root.data);
  System.out.print(' ');

  topViewRight(root.right);
}

void topView(Node root) {
  if(root == null)
    return;

  topViewLeft(root.left);

  System.out.print(root.data);
  System.out.print(' ');

  topViewRight(root.right);
}
