/* Node is defined as :
class Node
int data;
Node left;
Node right;

*/

static Node Insert(Node root,int value) {
  if(root == null){
    Node newNode = new Node();
    newNode.data = value;
    return newNode;
  }

  if(root.data > value){
    root.left = Insert(root.left, value);
  }else if(root.data < value){
    root.right = Insert(root.right, value);
  }

  return root;
}

// static Node Insert(Node root,int value) {
//   Node nextNode = null;
//
//   if(root.data > value){
//     nextNode = root.left;
//   }else if(root.data < value){
//     nextNode = root.right;
//   }else{
//     return root;
//   }
//
//   if(nextNode == null){
//     Node newNode = new Node();
//     newNode.data = value;
//     nextNode = newNode;
//   }else{
//     Insert(nextNode, value);
//   }
//
//   return root;
// }
