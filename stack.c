#include <stdio.h>
#include <stdlib.h>

struct stack {
  int size;
  int top;
  int *arr;
};

int isEmpty(struct stack *ptr){
  if(ptr->top == -1){
    return 1;
  }
  else{
    return 0;
  }
}

int isFull(struct stack *ptr){
  if(ptr->top == ptr->size - 1){
    return 1;
  }
  else{
    return 0;
  }
}

int main(){
  // struct stack s;
  // s.size = 80;
  // s.top = -1;
  // s.arr = (int*)malloc(s.size*sizeof(int));

  struct stack *s;
  s->size = 80;
  s->top = -1;
  s->arr = (int*)malloc(s->size*sizeof(int));

  // s->arr[0] = 7;
  // s -> top++;

  //check if stack is empty
  if(isEmpty(s)){
    printf("Stack is empty");
  }
  else {
    printf("Stack is not empty");
  }

  return 0;
}