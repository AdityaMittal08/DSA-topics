#include <stdio.h>

void display(int arr[], int n){
  //traversal
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }
}

int indDeletion(int arr[], int size, int capacity, int index){
  //code for deletion at index
  if(index >= capacity){
    printf("Invalid Index\n");
    return -1;
  }

  if(index < 0 || index > size){
    printf("Invalid index.\n");
    return -1;
  }

  // Shift elements to the left
  // to remove space of the element
  for (int i = index; i < size-1; i++) {
    arr[i] = arr[i+1];
  }
  return 0;

}

int main(){
  int arr[100] = {7, 8, 12, 27, 88}; // Initial array 
  int size = 5, capacity = 100, index;

  printf("Enter the index at which to delete: ");
  scanf("%d" , &index);

  printf("Array before deletion: ");
  display(arr, size);

  printf("\n"); 

  if (indDeletion(arr, size, capacity, index) == -1) {
    return 1; // Exit if deletion failed
  }

  size--; // Decrement size after successful deletion

  printf("Array after deletion: ");
  display(arr, size);

  return 0;
}