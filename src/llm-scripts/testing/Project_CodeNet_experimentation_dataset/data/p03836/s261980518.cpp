#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long sx, long long sy, long long tx, long long ty){
    ll dx = (tx - sx);
    ll dy = (ty - sy);
    string ans = "";
    ans = ans + string(dy, 'U') + string(dx, 'R');
    ans = ans + string(dy, 'D') + string(dx, 'L');
    ans = ans + 'L' + string(dy+1, 'U') + string(dx+1, 'R') + 'D';
    ans = ans + 'R' + string(dy+1, 'D') + string(dx+1, 'L') + 'U';
    cout << ans << endl;
    return;
}

int main(){
    long long sx;
    scanf("%lld",&sx);
    long long sy;
    scanf("%lld",&sy);
    long long tx;
    scanf("%lld",&tx);
    long long ty;
    scanf("%lld",&ty);
    solve(sx, sy, tx, ty);
    return 0;
}
