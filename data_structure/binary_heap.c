#include <stdio.h>

// root 노드 -> 0번째 index
// parent 노드(i 번째 index 일 때) 의 left child node -> 2*i
// parent 노드(i 번재 index 일 때) 의 right child node -> 2*i + 1
// child 노드(i 번째 index 일 때) 의 parent node -> i / 2
void build(int *);
void min_heapify(int *, int);
int extract_min(int *);
void insert_value(int *, int);
void swap(int*, int*);
void print(int*, int);

int arr[10] = {5, 3, 1, 2, 4, 10, 9, 6, 8, 7};
int size = 10;

int main() {
    print(arr, size);
    build(arr);
    print(arr, size);
}

void build(int* arr) {
    for (int i=0; i<size/2; i++) {
        min_heapify(arr, i);
    }
}

void min_heapify(int* arr, int key) {
    int largest = key;
    int left = 2*largest + 1;
    int right = 2*largest + 2;
    
    if (left <= size && arr[left] < arr[largest]) {
        largest = left;
    } 
    if (right <= size && arr[right] < arr[largest]) {
        largest = right;
    }

    if (largest != key) {
        swap(&arr[key], &arr[largest]);
        min_heapify(arr, largest);
    }
}

int extract_min(int* arr) {
    return 0;
}

void insert_value(int* arr, int value) {

}

void swap(int* data1, int* data2) {
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

void print(int* arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}