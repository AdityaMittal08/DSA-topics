#include <stdio.h>

int binarySearch(int arr[], int size, int element) {
  int low, mid, high; //low and high are indices for the search range
  // Initialize low and high
  low = 0;
  high = size - 1;

  //start searching
  while(low<=high){
    mid = (low + high)/2;
    if(arr[mid] == element){
      return mid;
    }
    if(arr[mid] < element){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  //searching end
  return -1; // Return -1 if not found
}

int main(){
  int arr[] = {7, 8, 12, 27, 88}; //sorted array for binary search
  int size = sizeof(arr) / sizeof(arr[0]);
  int element;

  printf("Enter the element to search: ");
  scanf("%d", &element);

  int searchIndex = binarySearch(arr, size, element);

  if (searchIndex != -1) {
    printf("Element found at index: %d\n", searchIndex);
  } else {
    printf("Element not found.\n");
  }
  
  return 0;
}