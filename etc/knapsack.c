#include <stdio.h>
#include <stdlib.h>

int itemCount;
int result=0;

void knapsack(int* weights, int* benefits);
int max(int a, int b);

int main() {
    printf("Knapsack problem\n");

    printf("How many items? ");
    scanf("%d", &itemCount);

    int *weights = (int*) malloc(sizeof(int) * itemCount);
    int *benefits = (int*) malloc(sizeof(int) * itemCount);

    printf("enter weight and benefit value (ex. 5 6)\n");
    for (int i=0; i<itemCount; i++) {
        scanf("%d", &weights[i]);
        scanf("%d", &benefits[i]);
    }

    printf("weights List:\n");
    for (int i=0; i<itemCount; i++) {
        printf("%d ", weights[i]);
    } printf("\n");

    printf("benefits List:\n");
    for (int i=0; i<itemCount; i++)
    {
        printf("%d ", benefits[i]);
    } printf("\n");
    
    knapsack(weights, benefits);
    printf("Sum of benefits: %d\n", result);
}

void knapsack(int* weights, int* benefits) {
    int maxWeight=0;
    printf("Max weight of your knapsack: ");
    scanf("%d", &maxWeight);

    // (maxWeight+1) * (itemCount+1) 크기의 2차원 배열 동적 할당
    int** DP = (int**) malloc(sizeof(int*) * maxWeight+1);
    for (int i=0; i<maxWeight+1; i++) {
        DP[i] = (int*) malloc(sizeof(int) * itemCount+1);
    }

    // DP 배열에 benefit 을 저장하면서 구함.

    for (int i=1; i<itemCount+1; i++) {
        for (int w=1; w<maxWeight+1; w++) {
            // 현재 배낭에 넣을 수 있는 무게가 w 인데 현재 item 의 무게가 w 보다 작거나 같은 경우
            // 아닌 경우에는 이전 benefit 값 그대로 다시 넣음
            if (weights[i-1] <= w) {

                // 이전에 넣었던 benefit 에서 현재 새로 넣으려는 benefit 을 더했을 때 이전에 넣었던 benefit 보다 크다면 업데이트
                // 아니면 그냥 이전 benefit 그대로 다시 넣음
                if (benefits[i-1] + DP[w-weights[i-1]][i-1] > DP[w][i-1]) {
                    DP[w][i] = benefits[i-1] + DP[w-weights[i-1]][i-1];
                } else {
                    DP[w][i] = DP[w][i-1];
                }
            } else {
                DP[w][i] = DP[w][i-1];
            }
        }
    }

    for (int i=0; i<=maxWeight; i++) {
        for (int j=0; j<=itemCount; j++)
        {
            printf("%d ", DP[i][j]);
        }
        printf("\n");
    }

    result = DP[maxWeight][itemCount];
}

int max(int a, int b) {
    return a >= b ? a : b;
}