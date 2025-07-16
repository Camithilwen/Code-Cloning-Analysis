#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int k, x;
    cin >> k >> x;
    for(int i =  x - k + 1; i < x + k; i++) {
        cout << i << " ";
    }
    return 0;
}
