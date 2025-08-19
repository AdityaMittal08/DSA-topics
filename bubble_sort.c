#include <stdio.h>

void printArray(int* A, int n){
  for(int i = 0; i< n; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}

void BubbleSortwithAdapt(int* A,int n){
  int temp;
  int isSorted;
  for(int i = 0; i < n - 1; i++){ //pass    
    printf("Working on pass number %d\n", i+1);
    isSorted = 1; // making adaptive
    for(int j = 0; j< n-1-i; j++){ //comparison in each pass
      if(A[j] > A[j+1]){
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
        isSorted = 0;
      }
    } 
    if(isSorted){ //helps to break loop if the array is already sorted
      return;
    }
  } 
}
int main(){
  int A[] ={12, 54, 65, 7, 23, 9};
  // int A[] ={7, 9, 12, 23, 54, 65};
  int n = 6;
  printArray(A, n);
   //printing the array before sorting
  BubbleSortwithAdapt(A, n); //sorting the array using bubble sort
  printArray(A, n); //printing the array after sorting
  return 0;
}