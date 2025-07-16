#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B, K;
int main() {
    cin >> A >> B >> K;

    for (int i = 1; i <= K; i++) {
        if (i % 2 == 1) {
            // 高橋
            if (A % 2 == 1) {
                A--;
            }
            ll tmp = A / 2;
            B += tmp;
            A -= tmp;
        } else {
            // 青木
            if (B % 2 == 1) {
                B--;
            }
            ll tmp = B / 2;
            A += tmp;
            B -= tmp;
        }
    }

    cout << A << " " << B << endl;;
}