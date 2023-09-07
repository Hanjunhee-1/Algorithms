#include <stdio.h>

void print(int* arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}

void binaryInsertion(int* arr, int size) {
    for (int i=1; i<size; i++) {
        int key = arr[i];
        int start = 0;
        int end = i - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (key < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        for (int j=i-1; j>=start; j--) {
            arr[j+1] = arr[j];
        }
        arr[start] = key;
    }
}

int main() {
    int arr[10] = {5, 3, 1, 2, 4, 10, 9, 6, 8, 7};
    int size = sizeof(arr) / sizeof(int);

    binaryInsertion(arr, size);
    print(arr, size);
    return 0;
}