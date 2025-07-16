#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 1000000000

int main() {
    int a,b,ans;
    cin >> a >> b;
    ans = (a==b ? 2*a : 2*max(a,b)-1);
    cout << ans << endl;
}