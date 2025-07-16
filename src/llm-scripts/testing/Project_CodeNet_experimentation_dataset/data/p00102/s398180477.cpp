#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        int table[11][11] = {};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> table[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += table[i][j];
            }
            table[i][n] = sum;
        }
        for (int i = 0; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += table[j][i];
            }
            table[n][i] = sum;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                printf("%5d",table[i][j]);
            }
            printf("\n");
        }
    }
}