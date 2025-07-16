#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int N, K;
vector<int> D;

void dfs(int n) {
    bool flag = false;
    int tmp = n;
    while (tmp > 0) {
        for (int i = 0; i < K; i++) {
            if (tmp % 10 == D[i]) {
                flag = true;
                break;
            }
        }
        if (flag == true) break;
        tmp /= 10;
    }
    if (flag == true) dfs(n + 1);
    if (flag == false) cout << n << endl;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        D.push_back(d);
    }
    dfs(N);
    return 0;
}