#include <stdio.h>

void swap(int*, int*);
void print(int*, int);
void quick(int*, int, int);
int partition(int*, int, int);

int main() {
    int arr[10] = {1, 8, 10, 2, 6, 4, 9, 5, 3, 7};

    quick(arr, 0, 9);
    print(arr, sizeof(arr)/sizeof(int));
}

void swap(int* a, int* b)  {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int* arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
}

void quick(int* arr, int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);

        quick(arr, left, p-1);
        quick(arr, p, right);
    }
}

int partition(int* arr, int left, int right) {
    int pivot = arr[(left+right)/2]; // pivot 값은 배열에서 중간에 위치한 값으로 합니다.
    int start = left;                // start 는 맨 왼쪽의 index 값입니다.
    int end = right;                 // end 는 맨 오른쪽의 index 값입니다.

    while (start <= end) {
        while (arr[start] < pivot) start++; // arr[start] 가 pivot 보다 작다면 다음 index 로 넘어갑니다.
        while (arr[end] > pivot) end--;     // arr[end] 가 pivot 보다 크다면 다음 index 로 넘어갑니다. 
        
        // 위의 반복문이 끝나고 arr[start] 와 arr[end] 를 서로 바꿔줍니다. 
        // 만약 pivot 이 이미 작은 값들과 큰 값들에 대해서 잘 나눠주고 있다면 pivot 과 pivot 을 바꾸는 의미없는 연산을 하게 되기도 합니다...
        if (start <= end) {
            swap(&arr[start], &arr[end]);
            start++;
            end--;
        }
    }
    return start;
}