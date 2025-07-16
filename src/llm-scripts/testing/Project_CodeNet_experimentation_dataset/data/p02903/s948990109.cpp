#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int H,W,A,B; cin >> H >> W >> A >> B;
    rep(i,H) {
        rep(j,W) {
            if (i < B) {
                cout << ((j < A) ? 0 : 1);
            } else {
                cout << ((j < A) ? 1 : 0);
            }
        }
        cout << endl;
    }
}
