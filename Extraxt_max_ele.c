#include <stdio.h>

int extract_max_ele(int arr[], int *n);
void max_heapify(int arr[], int n, int i);

int main() {
  int n, i;
  printf("Enter the array size: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the array elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("The array is: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  while (n > 0) {
    int max = extract_max_ele(arr, &n);
    printf("Extracted max element: %d\n", max);
  }
  return 0;
}

int extract_max_ele(int arr[], int *n) {
  if (*n <= 0) {
    printf("Heap is empty\n");
    return -1; // Indicate heap is empty with a negative value
  }
  int max = arr[0];
  arr[0] = arr[(*n) - 1];
  (*n)--;
  max_heapify(arr, *n, 0);
  return max;
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

