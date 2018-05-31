// Complete the getNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode next;
 * }
 *
 */
static int getNode(SinglyLinkedListNode head, int positionFromTail) {
  SinglyLinkedListNode node = head;
  SinglyLinkedListNode nodeForTail = head.next;

  int index = 0;
  while(index < positionFromTail){
    nodeForTail = nodeForTail.next;
    index++;
  }

  while(nodeForTail != null){
    node = node.next;
    nodeForTail = nodeForTail.next;
  }

  return node.data;
}
