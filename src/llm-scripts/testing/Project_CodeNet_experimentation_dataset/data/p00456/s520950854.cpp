#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int scores[2] = {0, 0};
    int points[2][10];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> points[i][j];
        }
        sort(points[i], points[i]+10);
        for (int j = 0; j < 3; ++j) {
            scores[i] += points[i][9 - j];
        }
    }
    cout << scores[0] << ' ' << scores[1] << endl;
    return 0;
}