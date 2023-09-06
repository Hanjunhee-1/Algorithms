#include <stdio.h>

void print(int* arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}

void merge(int* arr, int* left, int* right, int leftSize, int rightSize) {
    int l = 0;  // 왼쪽 배열 시작 위치
    int r = 0;  // 오른쪽 배열 시작 위치
    int o = 0;  // 저장할 배열 시작 위치

    // left 와 right 에서 하나하나씩 확인해가면서 arr 에 저장
    while (l < leftSize && r < rightSize) {
        if (left[l] < right[r]) {
            arr[o++] = left[l++];
        } else {
            arr[o++] = right[r++];
        }
    }

    // 위의 while 문이 끝났다면 왼쪽 배열과 오른쪽 배열 중 하나는 값들이 남아있기에 아래의 과정이 필요.
    // 왼쪽과 오른쪽 각각에 대해 옮겨주는 작업 실행
    while (l < leftSize) {
        arr[o++] = left[l++];
    }

    while (r < rightSize) {
        arr[o++] = right[r++];
    }
}

void mergeSort(int* arr, int size) {
    if (size > 1) {
        // 중간 위치
        int mid = size / 2;

        // 기존의 배열을 반으로 나눠주는 과정
        int left[mid];
        int right[size - mid];

        for (int i=0; i<mid; i++) {
            left[i] = arr[i];
        }

        for (int i=mid; i<size; i++) {
            right[i - mid] = arr[i];
        }

        // 왼쪽 배열과 오른쪽 배열에 대해 재귀 호출
        mergeSort(left, mid);
        mergeSort(right, size - mid);

        // 마무리로 merge
        merge(arr, left, right, mid, size - mid);
    }
}

int main() {
    int arr[10] = {5, 3, 1, 2, 4, 10, 9, 6, 8, 7};
    int size = sizeof(arr) / sizeof(int);

    mergeSort(arr, size);
    print(arr, size);

    return 0;
}