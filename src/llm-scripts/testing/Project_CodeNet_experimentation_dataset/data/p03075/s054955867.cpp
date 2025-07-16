#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int a, b, c, d, e, k;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> d >> e >> k;
    bool flg = true;
    if(e - a > k) {
        flg = false;
    }

    if(flg) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}
