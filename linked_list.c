#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node * next;
};

void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
  struct Node *head;
  struct Node *second;
  struct Node *third;

  // Allocate memory for nodes in the linked list in heap
  head  = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));

  // Assign data and link nodes
  // Link first node with the second node
  head->data = 7;
  head->next = second;

   // Link first node with the second node
  second->data = 11;
  second->next = third;

  // Link second node with the third node
  third->data = 66;
  third->next = NULL; // End of the list

  linkedListTraversal(head);

  return 0;
}