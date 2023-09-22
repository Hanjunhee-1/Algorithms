# 이진 힙

- `이진 힙` 은 최댓값 혹은 최솟값을 찾아내는 연산을 빠르게 하기 위해 완전 이진트리(complete binary tree) 를 기본으로 한 자료구조입니다.

- `이진 힙` 의 속성은 다음과 같습니다.

    1. complete binary tree
    2. 부모 노드의 key 값과 자식 노드의 key 값 사이에는 대소 관계가 존재한다.
        - 만약 부모 노드가 더 크다면 `max_heap` 이라 하고, 더 작다면 `min_heap` 이라 합니다. 
        - 이것은 힙 속성이라고도 불립니다. <br/><br/>

- 앞서 말해듯 `min_heap` 과 `max_heap` 두 가지가 있는데 여기서는 `min_heap` 에 대해서 다루겠습니다. 

- `min_heap` 은 root 노드에 가장 작은 값이 존재합니다. 그리고 항상 부모 노드가 자식 노드보다 작습니다. 

- `min_heap` 을 배열을 통해서 구현하게 된다면 부모 노드의 인덱스가 i 일 때 `왼쪽 자식 노드의 인덱스는 2 * i + 1` 이고 `오른쪽 자식 노드의 인덱스는 2 * i + 2` 입니다. 자식 노드들의 인덱스를 기준으로 부모 노드의 인덱스를 구해보면 부모 노드의 인덱스는 자식 노드의 인덱스가 j 일 때 `(j - 1) / 2` 입니다.


# Heapify

- `Heapify` 는 힙 속성을 유지하는 작업을 말합니다. `min_heap` 에서의 heapify 작업은 다음과 같습니다.

    1. 특정 요소의 값과 그 요소의 자식 노드의 값을 비교합니다.
    2. 만약 자식 노드의 값이 더 작다면 왼쪽과 오른쪽 자식 중에서 가장 작은 값으로 교환합니다.
    3. 힙 속성이 유지될 때까지 1,2 를 반복합니다. <br/><br/><br/>

- 이를 코드로 나타내면 다음과 같습니다.
    ```c
        void heapify(int* arr, int index) {
            // 매개변수로 특정 index 를 받고, 각 자식 노드의 index 를 선언합니다.
            int smallest = index;
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;

            // 왼쪽 자식 노드의 값이 arr[smallest] 보다 작다면 가장 작은 값의 인덱스를 왼쪽 자식 노드의 인덱스 값으로 바꿉니다.
            if (leftChild < HEAP_SIZE && arr[leftChild] < arr[smallest]) smallest = leftChild

            // 오른쪽 자식 노드의 값이 arr[smallest] 보다 작다면 가장 작은 값의 인덱스를 오른쪽 자식 노드의 인덱스 값으로 바꿉니다. 위의 if 문에서 만약 왼쪽 자식 노드의 값이 더 작았다면 smallest 는 leftChild 의 값을 가지게 되고 이는 자식 노드끼리 값을 비교하게 되는 것입니다. 
            if (rightChild < HEAP_SIZE && arr[rightChild] < arr[smallest]) smallest = rightChild

            // 만약 부모 노드가 자식 노드들보다 작다면 smallest 의 값은 변하지 않았을 것입니다. smallest 가 바뀌었다면 원래 arr[index] 와 arr[smallest] 의 값을 서로 바꿔줍니다. 바꿔준 뒤에는 smallest 의 위치에는 원래 부모 노드에 있던 값이 있을 것이고 자식 노드들이 바뀌어 있는 상황이기 때문에 바뀐 것에 대해 다시 heapify 를 진행해줍니다. 
            if (smallest != index) {
                swap(&arr[index], &arr[smallest]);
                heapify(arr, smallest);
            }
        }
    ```
    <br/><br/>

- 이 작업은 완전 이진 트리 구조를 생각해보았을 때 트리의 높이 보다 더 많이 반복될 수 없습니다. 즉, arr 의 크기가 N 일 때, `heapify` 작업은 `O(log N)` 의 시간이 걸립니다. 

- 최솟값을 추출하는 것은 맨 앞에 있는 것만 빼오면 되기 때문에 `O(1)` 의 시간이 걸리지만 힙 속성을 만족시켜주어야 하기 때문에 `heapify` 를 진행하면서 실질적으로는 `O(log N)` 이라는 시간이 걸리게 됩니다. 