#include <stdio.h> 
#include <stdlib.h> 

void merge(int *arr, int left, int mid, int right) 
{ 
  int i, j, k; 
  // left == 0 && right == 5
  int leftSide = mid - left + 1; 
  // {1,2,3,4,5} -> mid == 3 -> 3-0+1 leftSide == 4;
  int rightSide = right - mid; 
  // {1,2,3,4,5} -> mid == 3 -> 5-3 rightSide == 1;
  
  // Create temp arrays 
  int L[rightSide], R[leftSide]; 

  for (i = 0; i < leftSide; i++) 
    L[i] = arr[left + i]; 
  //1+0,1+1,1+2,1+3 == {1,2,3,4}
  for (j = 0; j < rightSide; j++) 
    R[j] = arr[mid + 1 + j]; 
  //4+1 = {5}

  i = 0; 
  j = 0; 

  k = left; 

  //leftSide == 4 && rightSide == 1
  // k = 0;
  
  while (i < leftSide && j < rightSide) { 
    if (L[i] <= R[j]) 
      //{1,2,3,4} <= {5}
    { 
      arr[k] = L[i]; 
      i++; 
    } 
    else { 
      arr[k] = R[j]; 
      j++; 
    } 
    k++; 
  } 
  while (i < leftSide) { 
    arr[k] = L[i]; 
    i++; 
    k++; 
  } 

  while (j < rightSide) { 
    arr[k] = R[j]; 
    j++; 
    k++; 
  } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
  if (l < r) { 
    int m = l + (r - l) / 2; 
    // {3,1,2,5} && l = 0, h = 4, m = 2
    // mergeSort ({3,1,2,5},0,2)
    // mergeSort ({3,1} 0,1)
    // merge Sort({3} 0,0)
    // mergeSort ({3,1,2,5},3,4)
    //mergeSort ({2,5}3,4)
    //mergeSort({5}4,4)
    // merge({3,1,2,5} , 0,2,4)
    mergeSort(arr, l, m); 
    mergeSort(arr, m + 1, r); 
    // 3,{3,1}
    merge(arr, l, m, r); 
  } 
} 

// UTILITY FUNCTIONS 
// Function to print an array 

int BinarySearch(int *array, int *barray, int n) {
  int low = 0;
  int high = n;
  int counter = 0;
  int i = 0;

  while (low <= high) {
    int target = array[i];
    int mid = (low + high) / 2;

    if (i > 4) {
      return 0;
    }

    if (barray[mid] == target) {
      counter++;
      i++;
    } else if (barray[mid] > target) {
      high = mid - 1;
    } else if (barray[mid] < target) {
      low = mid + 1;
    }
  }
  if (counter < 4) {
    printf("Not every element is included in barray :(\n");
    return 0;
  }
  printf("Every element is included in barray :)\n");
  return 1;
}

int main(void) {
  int Aarray[] = {1, 2, 2, 4};
  int Bbarray[] = {1, 4, 8, 2};
  int n = 4;
  BinarySearch(Aarray, Bbarray, n);
  return 0;
}