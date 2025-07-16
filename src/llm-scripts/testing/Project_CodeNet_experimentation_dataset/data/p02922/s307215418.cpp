#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, cnt = 0, plug = 1;
    cin >> a >> b;

    while(plug < b) {
        plug--;
        plug += a;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
