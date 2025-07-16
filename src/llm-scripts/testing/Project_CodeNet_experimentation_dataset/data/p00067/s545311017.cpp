#include <iostream>
#include <string>
#include <vector>
using namespace std;

char bd[12][12];

void del(int y, int x) {
    if (0 <= y && y < 12 && 0 <= x && x < 12 && bd[y][x] == '1') {
        bd[y][x] = '0';
        del(y-1, x);
        del(y+1, x);
        del(y, x-1);
        del(y, x+1);
    }
}

int main() {
    while (cin >> bd[0][0]) {
        for (int i=0; i<12; ++i) {
            for (int j=0; j<12; ++j) {
                if (i == 0 && j == 0) continue;
                cin >> bd[i][j];
            }
        }
        int cnt = 0;
        for (int i=0; i<12; ++i) {
            for (int j=0; j<12; ++j) {
                if (bd[i][j] == '1') {
                    del(i, j);
                    cnt ++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}