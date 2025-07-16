#include <stdio.h>

int main() {
    int n, row, col;
    scanf("%d", &row);
    scanf("%d", &col);
    scanf("%d", &n);
    
    int temp;
    int count = 0;

    if (row > col) {
        temp = row;
    } else {
        temp = col;
    }

    for (int i = 0; i < n; i = i + temp) {
        count++;
    }

    printf("%d\n", count);

    return 0;
}