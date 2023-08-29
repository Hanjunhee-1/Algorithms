#include <stdio.h>

void swap(int* data1, int* data2) {
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

void selection(int* arr, int size) {
    for (int i=0; i<size-1; i++) {
        int temp = i;
        for (int j=i+1; j<size; j++) {
            if (arr[temp] >= arr[j]) temp = j;
        }
        swap(&arr[i], &arr[temp]);
    }
}

void print(int* arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}

int main() {
    int arr[10] = {5, 3, 1, 2, 4, 10, 9, 6, 8, 7};
    int size = sizeof(arr) / sizeof(int);

    selection(arr, size);
    print(arr, size);
    return 0;
}