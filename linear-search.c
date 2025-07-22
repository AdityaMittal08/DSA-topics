#include <stdio.h>

int linearSearch(int arr[], int size, int element) {
    // Linear search implementation
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main(){
  int arr[] = {12, 5, 9, 15, 88};
  int size = sizeof(arr) / sizeof(arr[0]);
  int element;

  printf("Enter the element to search: ");
  scanf("%d", &element);

  int searchIndex = linearSearch(arr, size, element);
  printf("Element found at index: %d\n", searchIndex);

  return 0;
}