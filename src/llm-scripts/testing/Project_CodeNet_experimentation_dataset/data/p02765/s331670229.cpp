#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, r;
    cin >> n >> r;
    int rate;
    if (n > 10) {
        rate = r;
    } else {
        rate = r + (100 * (10 - n));
    }
    cout << rate << endl;
    return 0;
}