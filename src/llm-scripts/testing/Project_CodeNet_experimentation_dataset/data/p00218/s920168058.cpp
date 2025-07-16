#include <iostream>

char jukuClass(int, int, int);
int main()
{
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            int pm, pe, pj;
            std::cin >> pm >> pe >> pj;
            std::cout << jukuClass(pm, pe, pj) << std::endl;
        }
    }
    return 0;
}
char jukuClass(int pm, int pe, int pj)
{
    if (pm == 100 || pe == 100 || pj == 100) {
        return 'A';
    } else if ((pm + pe) / 2.0 >= 90) {
        return 'A';
    } else if ((pm + pe + pj) / 3.0 >= 80) {
        return 'A';
    } else if ((pm + pe + pj) / 3.0 >= 70) {
        return 'B';
    } else if (((pm + pe + pj) / 3.0 >= 50) && (pm >= 80 || pe >= 80)) {
        return 'B';
    } else {
        return 'C';
    }
}