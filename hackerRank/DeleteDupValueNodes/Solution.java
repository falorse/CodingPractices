// Complete the removeDuplicates function below.

/*
* For your reference:
*
* SinglyLinkedListNode {
*     int data;
*     SinglyLinkedListNode next;
* }
*
*/
static void removeDupSameDataNode(SinglyLinkedListNode dupDataNode){
  SinglyLinkedListNode node = dupDataNode;
  int dupData = dupDataNode.data;

  while(node != null && node.data == dupData) {
    node = node.next;
  }
  dupDataNode.next = node;
}

static SinglyLinkedListNode removeDuplicates(SinglyLinkedListNode head) {
  SinglyLinkedListNode node = head;

  while(node != null && node.next != null) {
    if(node.next.data == node.data) {
      removeDupSameDataNode(node);
    }
    node = node.next;
  }

  return head;
}
