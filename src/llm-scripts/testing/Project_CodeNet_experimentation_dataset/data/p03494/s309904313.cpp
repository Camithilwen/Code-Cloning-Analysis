#include <iostream>
using namespace std;

int N;
int A[210];         // 最大 200 個なので余裕を持って 210 に --- 200 以上ならなんでもよいです

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    int res = 0;

    // 操作が行える限り操作を繰り返す
    while (true) {
        bool exist_odd = false;  // A[i] がすべて偶数かどうかを判定するフラグ
        for (int i = 0; i < N; ++i) {
            if (A[i] % 2 != 0) exist_odd = true;  // 奇数があったらフラグを立てる
        }

        if (exist_odd) break;  // 奇数があったら break

        // 操作を行えるなら操作を実際に行う
        for (int i = 0; i < N; ++i) {
            A[i] /= 2;
        }
        ++res;  // 操作回数をインクリメント
    }

    cout << res << endl;
}