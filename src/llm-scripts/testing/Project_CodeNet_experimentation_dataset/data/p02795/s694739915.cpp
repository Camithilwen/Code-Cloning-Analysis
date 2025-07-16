#include<stdio.h>

int main() {
    int x, y, z, res;
    scanf("%d%d%d", &x, &y, &z);
    if(x>=y) {
        if(z%x == 0) {
            res = z/x;
        } else {
            res = z/x+1;
        }
    } else {
        if(z%y == 0) {
            res = z/y;
        } else {
            res = z/y+1;
        }
    }

    printf("%d", res);
    return 0;
}