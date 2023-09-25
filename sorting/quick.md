# 퀵 소트

- `퀵 소트` 는 이름에서부터 빠르다는 느낌을 주지만 최악의 경우에는 `O(n^2)` 의 시간 복잡도를 가지는 정렬 알고리즘입니다. 분할정복의 매커니즘을 가지는 정렬 알고리즘입니다. 


# Partition (분할)

- `퀵 소트` 에서 `Partition` 은 pivot 을 정하고 해당 pivot 을 기준으로 작은 값들의 모임과 큰 값들의 모임을 만들어줍니다. 

    1. 전체 배열에서 pivot 을 하나 정합니다. 코드에서는 중간에 위치한 값을 pivot 으로 정했습니다. 

    2. 배열의 첫번째 원소의 자리를 start 라고 둡니다. 배열의 첫번째 원소부터 접근하여 해당 원소가 pivot 보다 작은지 확인합니다. 작다면 계속해서 다음 index 에 대해서도 확인합니다. 크다면 해당 index 에서 멈추고 start 에 해당 index 값을 저장합니다.

    3. 배열의 마지막 원소의 자리를 end 라고 둡니다. 배열의 마지막 원소부터 접근하여 해당 원소가 pivot 보다 큰지 확인합니다. 크다면 계속해서 다음 index 에 대해서도 확인합니다. 작다면 해당 index 에서 멈추고 end 에 해당 index 값을 저장합니다. 

    4. start 와 end 의 위치에 있는 데이터들끼리 서로 바꿔준 뒤에 start 의 값은 1 증가시키고 end 의 값은 1 감소시킵니다.

    5. 위의 과정을 start 가 end 보다 값이 커질 때까지 반복합니다. 

    6. start 가 end 보다 값이 커져서 반복이 종료될 때 해당 start 의 위치값을 가지고 배열의 길이를 반으로 나누어 나눠진 배열에 대해서도 이를 반복합니다. <br/><br/>

- 이를 코드로 작성한다면 아래와 같습니다.
    ```c
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
    ```
    <br/><br/>

# quick (정복)

- 제가 임의로 정한 이름입니다. 이렇게 `partition` 과정을 통해 분할을 계속해주면 알아서 정복됩니다. 

- 코드는 아래와 같습니다.
    ```c
        void quick(int* arr, int left, int right) {
            if (left < right) {
                int p = partition(arr, left, right);

                quick(arr, left, p-1);
                quick(arr, p, right);
            }
        }
    ```
    - `partition` 을 통해서 분할해주고 pivot 의 위치를 받은 다음 다시 `quick` 을 호출하면서 계속 분할해줍니다. <br/><br/><br/>

- 시간 복잡도에 대해서 자세히 알아보면 `partition` 에서 pivot 과 값들을 비교하는 과정에서 `O(n)` 만큼의 시간이 걸리고 이를 계속해서 호출하는 `quick` 에서 `O(log n)` 만큼의 시간이 걸립니다. 총 `O(n log n)` 만큼의 시간이 걸립니다. 하지만 최악의 경우에는 `O(n^2)` 만큼의 시간이 걸립니다. 