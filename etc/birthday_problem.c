# include <stdio.h>

float birthday(int n);

int main() {
    int n=0;
    float result=1;
    printf("How many people: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        result = result * birthday(i);
    }

    printf("%.2f\n", (float)100 - result*100);
    return 0;
}

float birthday(int n) {
    return ((float)(365 - n)/365);
}