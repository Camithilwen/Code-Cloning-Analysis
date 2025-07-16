#include <bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, H, W;
    bool flag = false;
    cin >> N >> H >> W;
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (j + W - 1 <= N) {
                flag = true;
            } else {
                flag = false;
            }

            if (flag && i + H - 1 <= N) {
                ++count;
            }
        }
    }
    cout << count << endl;
    return 0;
}