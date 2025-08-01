#include <stdio.h>
#include <stdlib.h>

//creation of linked list
struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};

//traversal to print the elements
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// reverse traversal to print the elements
// Reverse traversal to print the elements
void linkedListTraversalreverse(struct Node *tail){
    struct Node *ptr = tail;
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev; // Use the 'prev' pointer to move backwards
    }
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
  head -> prev = NULL; // link head node to the NULL

   // Link second node with the third node
  second->data = 11;
  second->next = third;
  second-> prev = head; // link second node with the head node

  // Link third node with fourth node
  third->data = 66;
  third->next = fourth;
  third -> prev = second; // link third node with second node
  
  fourth->data = 79;
  fourth->next = NULL;
  fourth -> prev = third; //link fourth node to the third node  // End of the list

  printf("traversal of linked list: \n");
  linkedListTraversal(head);

  printf("reverse traversal of linked list: \n");
  linkedListTraversalreverse(fourth);
  
  return 0;
}