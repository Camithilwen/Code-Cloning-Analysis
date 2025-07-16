#include <stdio.h>

void dividing(int pm, int pe, int pj);

int main(void)
{
    int students_number;
    int pm[10000], pe[10000], pj[10000];
    scanf("%d", &students_number);
    while (1) {
        if (students_number == 0) {
            break;
        } else {
            for (int i = 0; i < students_number; ++i) {
                scanf("%d %d %d", &pm[i], &pe[i], &pj[i]);
            }
            for (int i = 0; i < students_number; ++i) {
                dividing(pm[i], pe[i], pj[i]);
            }
            scanf("%d", &students_number);
        }
    }
    return 0;
}

void dividing(int pm, int pe, int pj)
{
    char rank;
    if (pm == 100 || pe == 100 || pj == 100) {
        rank = 'A';
    } else if (pm + pe >= 90 * 2) {
        rank = 'A';
    } else if (pm + pe + pj >= 80 * 3) {
        rank = 'A';
    } else if (pm + pe + pj >= 70 * 3) {
        rank = 'B';
    } else if (pm + pe + pj >= 50 * 3 && (pm >= 80 || pe >= 80)) {
        rank = 'B';
    } else {
        rank = 'C';
    }
    printf("%c\n", rank);
}