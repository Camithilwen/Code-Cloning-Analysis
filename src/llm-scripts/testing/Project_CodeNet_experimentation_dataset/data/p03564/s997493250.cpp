#include <stdio.h>

int main (){

    int G, N;
    scanf("%d %d", &G, &N);
    int z = 1;

for (int i = 0; i < G; i++) {
        if (2 * z <= z + N) {
            z *= 2;
        } else {
            z += N;
        }
    }
    printf("%d", z);


    return 0;
}