#include<stdio.h>

void devide(int x, int y, int z)
{
    if((x == 100) || (y == 100) || (z == 100)) {
        printf("A\n");
    } else if ((x + y) >= 90*2) {
        printf("A\n");
    } else if ((x + y + z) >= 80*3) {
        printf("A\n");
    } else if ((x + y + z) >= 70*3) {
        printf("B\n");
    } else if ((x + y + z) >= 50*3) {
        if ((x >= 80) || (y >= 80)){
            printf("B\n");
        } else {
            printf("C\n");
        }
    } else {
        printf("C\n");
    }
}

int main(void)
{
    int pm, pe, pj, num;

    scanf("%d", &num);

    while (num != 0) {
        for (int i = 0; i < num; i++) {
            scanf("%d %d %d", &pm, &pe, &pj);
            devide(pm, pe, pj);
        }

        scanf("%d", &num);
    }

    return 0;
}