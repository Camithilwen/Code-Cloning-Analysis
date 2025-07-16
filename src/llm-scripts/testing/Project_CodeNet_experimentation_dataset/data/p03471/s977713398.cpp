#include <iostream>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    // 答えを格納するための変数
    int ares = -1, bres = -1, cres = -1;

    // 全探索
    for (int a = 0; a <= N; ++a) {
        // a + b が N 以下の範囲で
        for (int b = 0; a + b <= N; ++b) {
            int c = N - a - b;
            if (10000 * a + 5000 * b + 1000 * c == Y) {
                ares = a;
                bres = b;
                cres = c;
            }
        }
    }
    cout << ares << " " << bres << " " << cres << endl;
}