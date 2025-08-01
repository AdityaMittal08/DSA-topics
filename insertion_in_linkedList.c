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

//Case1: insert at beginning

struct Node* insertAtFirst(struct Node * head, int data){  //returning struct node*
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
    
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

//Case2: insert at an index
struct Node* insertAtIndex(struct Node *head, int data, int index){
  struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
  struct Node* p = head;

  int i = 0;
  while(i != index - 1){
    p = p->next;
    i++;
  }

  ptr -> data = data;
  ptr -> next = p ->next;
  p -> next = ptr;
  return head;
}

//Case3: insert at end
struct Node * insertAtEnd(struct Node *head, int data){
  struct Node * ptr = (struct Node*)malloc(sizeof(struct Node*));
  struct Node * p = head;

  while(p ->next != NULL){
    p = p->next;
  }
  
  ptr->data = data;
  p->next = ptr;
  ptr -> next = NULL;
  return head;
}

//Case4: insertioan after a node using previous node
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode,  int data){
  struct Node * ptr = (struct Node*)malloc(sizeof(struct Node*)); 
  ptr->data = data;
  
  ptr->next = prevNode ->next;
  prevNode->next = ptr;
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
  
  fourth->data = 79;
  fourth->next = NULL;  // End of the list

  printf("Before Insertion \n");
  linkedListTraversal(head);

  head = insertAtFirst(head, 56);

  printf("After Insertion at beginning\n");
  linkedListTraversal(head);

  head = insertAtIndex(head, 12, 4);

  printf("After Insertion at Index \n");
  linkedListTraversal(head);

  head = insertAtEnd(head, 54);

  printf("After Insertion at the end \n");
  linkedListTraversal(head); //insert at second node as defined in int main()

  head = insertAfterNode(head, second, 45);

  printf("After Insertion after the node \n");
  linkedListTraversal(head);

  return 0;
}