#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int H, W, N;
    cin >> H >> W >> N;
    int MAX = max(H, W);
    ans = (N + MAX - 1) / MAX;
    cout << ans << endl;
}