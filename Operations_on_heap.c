#include <stdio.h>
#include <stdlib.h>
int n = 0;
void create_max_heap(int arr[]);
void increase_key(int arr[]);
void insert_key(int arr[]);
void decrease_key(int arr[]);
void delete_key(int arr[]);
void heap_sort(int arr[]);
void display(int arr[]);
void max_heapify(int arr[], int id);
void increase(int arr[], int id, int key);
int main() {
  int ch = 0, arr[20];
  while (ch != 7) {
    printf("Please Select \n");
    printf(
        "\n1.Create Max Heap\n2.Increase Key\n3.Insert in max heap\n4.Decrease "
        "Key\n5.Delete from max heap\n6.Heap Sort\n7.Exit\n");
    scanf("%d", &ch);
    printf("\n");
    switch (ch) {
    case 1:
      create_max_heap(arr);
      break;
    case 2:
      increase_key(arr);
      break;
    case 3:
      insert_key(arr);
      break;
    case 4:
      decrease_key(arr);
      break;
    case 5:
      delete_key(arr);
      break;
    case 6:
      heap_sort(arr);
      break;
    case 7:
      exit(0);
    default:
      printf("Invalid Choice\n");
    }
  }
  return 0;
}
void create_max_heap(int arr[]) {
	int i;
  printf("Enter the array size \n");
  scanf("%d", &n);
  printf("Enter the array elements \n");
  for ( i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("The array is:\n");
  display(arr);
  int last_non_leaf = (n - 1) / 2;
  for (i = last_non_leaf; i >= 0; i--) {
    max_heapify(arr, i);
  }
  printf("The heap is:\n");
  display(arr);
}
void increase_key(int arr[]) {
  int id = 0, key = 0;
  printf("Enter the index of the element to be increased:");
  scanf("%d", &id);
  printf("Enter the key");
  scanf("%d", &key);
  printf("\n");
  increase(arr, id, key);
  printf("The heap after increasing key:\n");
  display(arr);
}
void insert_key(int arr[]) {
  int key = 0;
  printf("Enter the key to be inserted:\n");
  scanf("%d", &key);
  printf("\n");
  n++;
  arr[n - 1] = -99999;
  int id = n - 1;
  increase(arr, id, key);
  printf("After insertion the heap is:\n");
  display(arr);
}
void decrease_key(int arr[]) {
  int id = 0, key = 0;
  printf("Enter the index of the element to be decreased:\n");
  scanf("%d", &id);
  printf("Enter the key\n");
  scanf("%d", &key);
  printf("\n");
  if (arr[id] < key) {
    printf("Error: The node is already lesser than the key\n");
    return;
  }
  arr[id] = key;
  max_heapify(arr, id);
  printf("The heap after decreasing key:\n");
  display(arr);
}
void delete_key(int arr[]) {
  int id = 0;
  printf("Enter the index of the key to be deleted\n");
  scanf("%d", &id);
  printf("\n");
  int del_ele = arr[id];
  arr[id] = arr[n - 1];
  n--;
  max_heapify(arr, id);
  printf("%d deleted \n", del_ele);
  printf("The heap after deletion:\n");
  display(arr);
}
void display(int arr[]) {
	int i;
  for ( i = 0; i < n; i++) {
    printf(" %d ", arr[i]);
  }
  printf("\n");
}
void heap_sort(int arr[]) {
  int copy = n,i;
  for (i = n - 1; i >= 1; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    n--;
    max_heapify(arr, 0);
  }
  n = copy;
  printf("The sorted array is:\n");
  display(arr);
}
void max_heapify(int arr[], int i) {
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
    max_heapify(arr, largest);
  }
}
void increase(int arr[], int id, int key) {
  if (arr[id] > key) {
    printf("Error: The node is already greater than the key\n");
    return;
  }
  arr[id] = key;
  while (id > 0 && arr[(id - 1) / 2] < arr[id]) {
    int temp = arr[(id - 1) / 2];
    arr[(id - 1) / 2] = arr[id];
    arr[id] = temp;
    id = (id - 1) / 2;
  }
}
