#include <stdio.h>
#include <stdlib.h>

struct myArray{
  int total_size; //memory to be reserved for the array
  int used_size; //memory to be used in the array
  int *ptr;
};

void createArray(struct myArray * a, int tSize, int uSize) {
  a->total_size = tSize;
  a->used_size = uSize;
  a->ptr = (int *) malloc(tSize*sizeof(int));
}

void show(struct myArray * a) { //function to display the array elements
  for(int i = 0; i < a->used_size; i++) {
    printf("%d ", (a->ptr)[i]);
  }
  printf("\n");
}

void setValue(struct myArray * a) { //function to set values in the array
  int n;
  for(int i = 0; i < a->used_size; i++) {
    printf("Enter element %d: ", i+1);
    scanf("%d", &n);
    (a->ptr)[i] = n;
  }
}

int main(){
  struct myArray marks;
  createArray(&marks, 10, 2);
  printf("We are running setValue function\n");
  setValue(&marks);

  printf("We are running show function\n");
  show(&marks);
  return 0;
}