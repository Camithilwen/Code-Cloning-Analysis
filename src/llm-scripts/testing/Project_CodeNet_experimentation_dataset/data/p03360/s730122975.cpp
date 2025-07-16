#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    int X = max({A, B, C});
    int Y = 1;
    rep(i, K) Y *= 2;
    cout << A + B + C + X * (Y - 1) << "\n";
}