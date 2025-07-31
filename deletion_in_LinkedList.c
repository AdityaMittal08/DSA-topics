#include <stdio.h>
#include <stdlib.h>

//creation of linked list
struct Node{
  int data;
  struct Node * next;
};

//traversal to print the elements
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//Case1: deletion at beginning

struct Node* deleteAtFirst(struct Node * head){  //returning struct node*
    struct Node* ptr = head;
    
    head = head -> next;
    free(ptr);
    return head;
}

//Case2: deletion at an index
struct Node* deleteAtIndex(struct Node *head, int index){
  struct Node* p = head;
  struct Node* q = head -> next;

  for (int i = 0; i < index -1; i++)
  {
    p = p->next;
    q = q->next;
  }

  p ->next = q->next;
  free(q);
  return head;
}

//Case3: deletion at end
struct Node * deleteAtEnd(struct Node *head){
  struct Node * p = head;
  struct Node * q = head -> next;
  while(q -> next != NULL ){
    p = p -> next;
    q = q-> next;
  }

  p->next = NULL;
  free(q);
  return head;
  
}

//Case4: deleting the element with a given value
struct Node * deleteOnValue(struct Node *head, int value){
  struct Node * p = head;
  struct Node * q = head ->next;
  while(q -> data !=value && q ->next != NULL)
  {
    p = p -> next;
    q = q -> next;
  }

    if (q-> data == value){
      p -> next = q ->next;
      free (q);
    }
  
  return head;
}

int main(){
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;
  struct Node *fifth;

  // Allocate memory for nodes in the linked list in heap
  head  = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));
  fifth = (struct Node *)malloc(sizeof(struct Node));

  // Assign data and link nodes
  // Link first node with the second node
  head->data = 7;
  head->next = second;

   // Link second node with the third node
  second->data = 11;
  second->next = third;

  // Link third node with the fourth node
  third->data = 66;
  third->next = fourth;
  
  // Link fourth node with the fifth node
  fourth->data = 79;
  fourth->next = fifth;  
  
  fifth->data = 22;
  fifth->next = NULL;   // End of the list

  printf("Before Deletion\n");
  linkedListTraversal(head);

  head = deleteAtFirst(head);

  printf("After Deletion at beginning\n");
  linkedListTraversal(head);

  head = deleteAtIndex(head, 2);

  printf("After Deletion at Index \n");
  linkedListTraversal(head);

  head = deleteAtEnd(head);

  printf("After Deletion at the end \n");
  linkedListTraversal(head);

  head = deleteOnValue(head, 66);

  printf("After Deletion of the given value\n");
  linkedListTraversal(head);

  return 0;
}