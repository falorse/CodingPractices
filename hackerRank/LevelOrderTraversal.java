/*

  class Node
    int data;
    Node left;
    Node right;
*/
// void levelOrder(Node root) {
//   LinkedList<Node> list = new LinkedList<Node>();
//   list.add(root);
//
//   while(!list.isEmpty()){
//     Node node = list.remove(0);
//     System.out.print(node.data);
//     System.out.print(' ');
//
//     if(node.left != null)
//       list.add(node.left);
//     if(node.right != null)
//       list.add(node.right);
//   }
// }

/*

  class Node
    int data;
    Node left;
    Node right;
*/


void levelOrder(Node root) {
  Queue<Node> q = new LinkedList<Node>();
  q.add(root);

  while(!q.isEmpty()){
    Node node = q.poll();
    System.out.print(node.data);
    System.out.print(' ');

    if(node.left != null)
      q.add(node.left);
    if(node.right != null)
      q.add(node.right);
  }
}
