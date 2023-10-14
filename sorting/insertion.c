#include <stdio.h>

void print(int* arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}

void insertion(int* arr, int size) {
    int key, j;
    for (int i=1; i<size; i++) {
        key = arr[i];
        j = i - 1;
        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j -= 1;
        }

        arr[j+1] = key;
    }
}

void insertion2(int* arr, int size) {
    int key, j;
    
    for (int i=1; i<size; i++) {
        key = arr[i];
        
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j+1] = arr[j];
        }

        arr[j+1] = key;
    }
}

int main() {
    int arr[10] = {5, 3, 1, 2, 4, 10, 9, 6, 8, 7};
    int size = sizeof(arr) / sizeof(int);

    insertion2(arr, size);
    print(arr, size);
    return 0;
}