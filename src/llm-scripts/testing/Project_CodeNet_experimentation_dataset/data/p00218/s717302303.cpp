#include <stdio.h>

int main(void)
{
    int n, pm, pe, pj;
    char c;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        } else {
            for(int i = 0; i < n; ++i) {
                scanf("%d %d %d", &pm, &pe, &pj);
                if (pm == 100 || pe == 100 || pj == 100 || (pm + pe) / 2 >= 90 || (pm + pe + pj) / 3 >= 80) {
                    c = 'A';
                } else if (((pm + pe + pj) / 3 >= 70) || ((pm + pe + pj) / 3 >= 50 && (pm >= 80 || pe >= 80))) {
                    c = 'B';
                } else {
                    c = 'C';
                }
                printf("%c\n", c);
            }
        }
    }
        return 0;
}