#include <stdio.h>

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

void bubble(int* arr, int size) {
    for (int i=size; i>0; i--) {
        for (int j=0; j<i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[10] = {5, 3, 1, 2, 4, 10, 9, 6, 8, 7};
    int size = sizeof(arr) / sizeof(int);

    bubble(arr, size);
    print(arr, size);
    return 0;
}