#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

void linkedListTraversal(struct Node *head) {
  struct Node * ptr = head;
  do{
    printf("Element: %d\n", ptr->data); // prints the first head element
    ptr = ptr -> next; // gives a kickstart such that loop doesnt stop at the beginning
  } while (ptr != head);

}

struct Node * insertAtFirst(struct Node *head, int data){
  struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr -> data = data;

  struct Node * p = head -> next;
  while(p->next != head){
    p = p ->next;
  }
  // at this point p points to the last node of this circular linked list

  p ->next = ptr;
  ptr->next = head;
  head = ptr;
  return head;
}

int main(){
  struct Node *head;
  struct Node *second;
  struct Node *third;
  struct Node *fourth;

  // Allocate memory for nodes in the linked list in heap
  head  = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  fourth = (struct Node *)malloc(sizeof(struct Node));

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
  
  // link fourth node to the first node
  fourth->data = 79;
  fourth->next = head; 

  printf("Circular linked list before insertion \n");
  linkedListTraversal(head);

  head = insertAtFirst(head, 19);

  printf("Circular linked list after insertion \n");
  linkedListTraversal(head);

  return 0;
}