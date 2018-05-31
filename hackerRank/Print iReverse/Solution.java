// Complete the reversePrint function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode next;
 * }
 *
 */
static void reversePrint(SinglyLinkedListNode head) {
  SinglyLinkedListNode node = head;
  List<Integer> list = new ArrayList<Integer>();

  while(node != null){
    list.add(node.data);
    node = node.next;
  }

  for(int i = list.size() - 1; i > -1 ; i--){
    System.out.println(list.get(i));
  }
}
