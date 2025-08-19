#include <stdio.h>

void printArray(int* A, int n){
  for(int i = 0; i< n; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}

void selectionSort(int* A, int n){
  printf("running selection sort...");
  int indexOfMin;
  int j;
  for(int i=0; i< n; i++){
    indexOfMin = i;
    for(j = i+1; j < n; j++){
      if(A[j] < A[indexOfMin]){
        indexOfMin = j;
      }
      // swap A[i] and A[indexOfMin]
    }
    int temp = A[i];
    A[i] = A[indexOfMin];
    A[indexOfMin] = temp;
  }
}

int main(){
  int A[] = {3, 5, 2, 13, 2};
  int n = 5;

  printArray(A, n);
  selectionSort(A, n);
  printArray(A, n);

  return 0;
}