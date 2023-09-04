# 삽입 정렬

- `삽입 정렬` 은 배열이 이미 정렬이 된 상태라고 가정합니다. 정렬된 배열의 의미는 길이가 1인 배열이라도 정렬이 되어있는 상태이기 때문에 정렬된 배열이라고 할 수 있습니다. 

- 기본 로직의 경우에는 아래와 같이 진행됩니다.

    1. 길이가 n 인 배열에서 길이를 1부터 시작하여 정렬을 시작합니다.

    2. 길이가 1인 배열은 이미 정렬이 완료된 배열입니다. 정렬이 완료된 배열의 가장 마지막 데이터 바로 옆에 있는 데이터를 정렬이 완료된 배열 속으로 삽입합니다. 

    3. 예를 들어, `5 4 3 2 1` 을 삽입 정렬로 오름차순 정렬을 해준다고 하면 처음 `5` 는 정렬이 완료된 배열인 것입니다. 그리고 정렬이 완료된 배열의 알맞은 위치에 `4` 를 삽입합니다. 그러면 `4 5 3 2 1` 이 됩니다. 이번에는 `4 5` 는 정렬이 완료된 배열이고 `3` 을  정렬이 완료된 배열의 알맞은 위치에 삽입합니다. 이러한 과정을 반복합니다. <br/><br/><br/>

- `삽입 정렬` 의 시간복잡도는 n 사이즈의 배열이 주어졌을 때 매번 정렬된 배열을 탐색하기 때문에 `O(n^2)` 입니다. 