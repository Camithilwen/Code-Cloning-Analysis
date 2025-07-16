#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x);
int main(){
    ll n, a, b;
    sc(n) sc(a) sc(b)
    ll X[n];
    for (int i = 0; i < n; i++) sc(X[i])
    ll x,ans = 0;
    for (int i = 0; i < n - 1; i++){
        x = (X[i + 1] - X[i]) * a;
        ans += min(x, b);
    }
    cout << ans << endl;
    return 0;
}