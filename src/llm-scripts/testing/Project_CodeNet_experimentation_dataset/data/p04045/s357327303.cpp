#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k;
    vector <int> am;
    vector <int> dig(10, 0);

    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        ++dig[t];
    }

    bool flag = false;
    int N = n;
    while (!flag) {
        n = N;
        flag = true;
        while (n > 0) {
            if (dig[n % 10]) {
                flag = false;
                n = 0;
                ++N;
            } else {
                n /= 10;
            }
        }
    }
    cout << N;
}

int main() {

    solve();
    return 0;
}
