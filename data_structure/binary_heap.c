#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// 이진 힙 (Binary Heap) 구조체 정의
struct BinaryHeap {
    int *arr; // 이진 힙을 저장할 배열
    int capacity; // 배열의 최대 크기
    int size; // 현재 이진 힙의 크기
};

// 이진 힙 생성 및 초기화
struct BinaryHeap* createHeap(int capacity) {
    struct BinaryHeap* heap = (struct BinaryHeap*)malloc(sizeof(struct BinaryHeap));
    if (!heap) {
        printf("힙 생성 실패: 메모리 부족\n");
        return NULL;
    }

    heap->capacity = capacity;
    heap->size = 0;
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    if (!heap->arr) {
        printf("배열 생성 실패: 메모리 부족\n");
        free(heap);
        return NULL;
    }

    return heap;
}

// 두 노드의 위치를 바꾸는 함수
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 새로운 원소를 이진 힙에 삽입
void insert(struct BinaryHeap* heap, int key) {
    if (heap->size >= heap->capacity) {
        printf("힙이 가득 찼습니다.\n");
        return;
    }

    // 새로운 원소를 배열의 맨 끝에 추가
    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = key;

    // 최소 힙 속성을 유지하기 위해 원소를 올바른 위치로 이동
    while (i > 0 && heap->arr[i] < heap->arr[(i - 1) / 2]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 최소값을 반환하고 제거
int extractMin(struct BinaryHeap* heap) {
    if (heap->size <= 0) {
        printf("힙이 비어 있습니다.\n");
        return -1; // 오류 표시
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // 최소값은 루트에 위치
    int root = heap->arr[0];

    // 루트에 배열의 마지막 원소를 복사하고 크기를 줄임
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // 최소 힙 속성을 유지하기 위해 루트를 아래로 이동
    int i = 0;
    while (1) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;

        if (leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest])
            smallest = leftChild;

        if (rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest])
            smallest = rightChild;

        if (smallest != i) {
            swap(&heap->arr[i], &heap->arr[smallest]);
            i = smallest;
        } else {
            break;
        }
    }

    return root;
}

// 이진 힙을 출력
void printHeap(struct BinaryHeap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct BinaryHeap* heap = createHeap(MAX_HEAP_SIZE);

    insert(heap, 10);
    insert(heap, 9);
    insert(heap, 8);
    insert(heap, 7);
    insert(heap, 6);
    insert(heap, 5);
    insert(heap, 4);
    insert(heap, 3);
    insert(heap, 2);
    insert(heap, 1);

    printf("heap 사이즈: %d\n", heap->size);
    printf("최소값: %d\n", extractMin(heap));
    printHeap(heap);
    printf("heap 사이즈: %d\n", heap->size);

    free(heap->arr);
    free(heap);

    return 0;
}
