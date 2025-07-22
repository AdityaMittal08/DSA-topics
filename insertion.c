#include <stdio.h>

void display(int arr[], int n){
  //traversal
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
}

int indInsertion(int arr[], int size, int element, int capacity, int index){
  //code for insertion at index
  if(size >= capacity){
    printf("Array is full, cannot insert element.\n");
    return -1;
  }

  if(index < 0 || index > size){
    printf("Invalid index.\n");
    return -1;
  }

  // Shift elements to the right
  // to make space for the new element
  for (int i = size-1; i >= index; i--) {
    arr[i + 1] = arr[i];
  }
  arr[index] = element;
  return 0;

}

int main(){
  int arr[100] = {7, 8, 12, 27, 88}; // Initial array 
  int size = 5, element, capacity = 100, index;

  printf("Enter the element to insert and the index at which to insert (format: element, index): ");
  scanf("%d, %d", &element , &index);

  printf("Array before insertion: ");
  display(arr, size);

  printf("\n"); 

  if (indInsertion(arr, size, element, capacity, index) == -1) {
    return 1; // Exit if insertion failed
  }

  size++; // Increment size after successful insertion

  printf("Array after insertion: ");
  display(arr, size);

  return 0;
}