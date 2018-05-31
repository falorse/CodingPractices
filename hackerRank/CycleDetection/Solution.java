/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

boolean hasCycle(Node head) {
  if(head == null || head.next == null){
    return false;
  }

  Node slowNode = head;
  Node fastNode = head.next;

  while(fastNode != null && fastNode.next != null){
    if(slowNode == fastNode){
      return true;
    }
    slowNode = slowNode.next;
    fastNode = fastNode.next.next;
  }

  return false;
}
