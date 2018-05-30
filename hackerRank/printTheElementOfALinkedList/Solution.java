static void printLinkedList(SinglyLinkedListNode head) {

  SinglyLinkedListNode node;
  node = head;

  while(node != null){
    System.out.println(node.data);
    node = node.next;
  }
}
