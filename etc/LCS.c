#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 50

typedef struct Stack
{
    char buf[MAX_LENGTH];
    int top;
} Stack;

void push(Stack* stack, char value) {
    stack->buf[++(stack->top)] = value;
}

char pop(Stack* stack) {
    return stack->buf[(stack->top)--];
}

int max(int a, int b) {
    return a >= b ? a : b;
}

// find and return Longest Common Subsequence of two strings
char* LCS(char* input1, char* input2) {
    int len1 = strlen(input1);
    int len2 = strlen(input2);
    char* result = (char*) malloc(MAX_LENGTH);
    struct Stack stack;
    stack.top = -1;

    int** table = (int**) malloc ((len1+1) * sizeof(int*));
    for (int i=0; i<len1+1; i++) {
        table[i] = (int*) malloc((len2+1) * sizeof(int));
    }

    for (int i=0; i<len1; i++) {
        for (int j=0; j<len2; j++) {
            if (input1[i] == input2[j])
                table[i+1][j+1] = table[i][j] + 1;
            else 
                table[i+1][j+1] = max(table[i][j+1], table[i+1][j]);
        }
    }

    int x = len1, y = len2;
    while (table[x][y] != 0) {
        if (table[x][y] == table[x][y-1]) y--;
        else if (table[x][y] == table[x-1][y]) x--;
        else if (table[x][y] - 1 == table[x-1][y-1]) {
            x--;
            y--;
            push(&stack, input1[x]);
        }
    }

    int cnt = stack.top + 1;
    if (cnt > -1) {
        for (int i=0; i<cnt; i++) {
            result[i] = pop(&stack);
        }
    }
    result[cnt] = '\0';

    free(table);
    return result;
}

int main() {
    char* input1 = (char*) malloc(MAX_LENGTH);
    char* input2 = (char*) malloc(MAX_LENGTH);

    printf("Enter two strings\n");
    scanf("%s", input1);
    scanf("%s", input2);

    printf("LCS of your inputs: %s\n", LCS(input1, input2));
}