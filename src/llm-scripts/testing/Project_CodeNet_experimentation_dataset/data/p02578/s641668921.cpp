#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<int>;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int a, b = 0;
    long long int ans = 0;
    rep(i,n) {
        cin >> a;
        if (a>b) b = a;
        else ans += b-a;
    }
    cout << ans << endl;
    return 0;
}
