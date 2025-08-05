#include <stdio.h>
#include <Stdlib.h>

struct stack {
 int size;
 int top;
 int *arr;
};

// checks if the stack is full or not
int isFull(struct stack* ptr){
  if(ptr->top == ptr->size - 1){
    return 1;
  }
  else{
    return 0;
  }
}

// checks if the stack is empty or not
int isEmpty(struct stack *ptr){
  if(ptr->top == -1){
    return 1;
  }
  else{
    return 0;
  }
}

// function which pushes the element in stack
void push(struct stack *ptr, int value){
  if(isFull(ptr)){
    printf("Stack overflow \n");
  }
  else{
    ptr -> top++;
    ptr -> arr[ptr->top] = value;
  }
}


// function which pops the element from the stack
int pop(struct stack *ptr){
  if(isEmpty(ptr)){
    printf("stack underflow \n");
    return -1;
  }
  else {
    int value = ptr -> arr[ptr-> top];
    ptr ->top--;
    return value;
  }
}

// peek the value at a position of the stack
int peek(struct stack * sp, int i){
  int arrayInd = sp ->top - i + 1;
  if(arrayInd < 0){
    printf("Not a valid position for the stack");
    return -1;  
  }
  else {
    return sp -> arr[arrayInd];
  }
}

// returns top element of stack
int stackTop(struct stack * sp){
  return sp->arr[sp->top];
}

// return bottom value of stack
int stackBottom(struct stack *sp){
  return sp->arr[0];

}
int main(){
  struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
  sp -> size = 10;
  sp -> top = -1;
  sp -> arr = (int*)malloc(sp->size * sizeof(int));
  printf("Stack has been created successfully \n");

  printf("Stack is empty? %d \n", isEmpty(sp));
  printf("Stack is full? %d \n", isFull(sp));
  push(sp, 23);
  push(sp, 54);
  push(sp, 12);
  push(sp, 67);
  push(sp, 26);
  push(sp, 47);
  push(sp, 87);
  push(sp, 9);
  push(sp, 34);
  push(sp, 24); // ---> pushed 10 values
  push(sp, 57); // stack overflow since size of the stack is 10
  printf("After pushing, Full : %d \n", isFull(sp));
  printf("After pushing, Empty : %d \n", isEmpty(sp));

  // follows the rule of LIFO or FILO
  printf("Popped %d from the stack \n", pop(sp));
  printf("Popped %d from the stack \n", pop(sp));

  for (int j = 1; j <= sp->top + 1; j++){ // printing all the values from the stack
  printf("The value at position %d is %d \n", j, peek(sp, j));
  }

  printf("The value of the topmost element is %d \n", stackTop(sp));
  printf("The value of the bottom most element is %d \n", stackBottom(sp));

  return 0;
}