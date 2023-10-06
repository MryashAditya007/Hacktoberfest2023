[Insert a Node at the Tail of a Linked List] https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem



// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
SinglyLinkedListNode* temp=head;
SinglyLinkedListNode* ins=new SinglyLinkedListNode(data);
ins->next=NULL;
if(head==NULL)
{
head=ins;
return head;
}
else{
while(temp->next){
    temp=temp->next;
}
temp->next=ins;

}
return head;



}

