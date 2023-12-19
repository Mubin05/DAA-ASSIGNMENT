#include <stdio.h>
void create_max_heap(int arr[], int n);
void max_heapify(int arr[], int n, int i);
int main() {
  int n, i;
  printf("Enter the array size\n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the array elements\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("The array is\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  create_max_heap(arr, n);
  printf("The max heap is:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
void create_max_heap(int arr[], int n) {
	int i;
  int lnl = (n - 1) / 2;
  for (i = lnl; i >= 0; i--)
   {
    max_heapify(arr, n, i);
  }
}
void max_heapify(int arr[], int n, int i) {
  int lc, rc, largest;
  lc = 2 * i + 1;
  rc = 2 * i + 2;
  if (lc < n && arr[lc] > arr[i]) {
    largest = lc;
  } else {
    largest = i;
  }
  if (rc < n && arr[rc] > arr[largest]) {
    largest = rc;
  }
  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    max_heapify(arr, n, largest);
  }
}
