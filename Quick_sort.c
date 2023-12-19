#include<stdio.h>

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
  int n, i;
  printf("Enter the array size: \n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the array elements: \n");
  for(i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  quick_sort(arr, 0, n-1);
  printf("The sorted array is: \n");
  for(i=0; i<n; i++) {
    printf(" %d ", arr[i]);
  }
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int q = partition(arr, low, high);
    quick_sort(arr, low, q-1);
    quick_sort(arr, q+1, high);
  }
}

int partition(int arr[], int low, int high) {
  int i, j;
  int pivot = arr[high];
  i = low - 1;
  for (j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i+1];
  arr[i+1] = arr[high];
  arr[high] = temp;
  return (i+1);
}

