#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int H, W; cin >> H >> W;
    int A, B; cin >> A >> B;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i < B && j < A ) || (B <= i && A <= j)) cout << '0';
            else cout << '1';
        }
        cout << '\n';
    }
    cout << endl;
}