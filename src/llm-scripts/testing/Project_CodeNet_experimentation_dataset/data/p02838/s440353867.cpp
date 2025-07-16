#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    ll digits = 1;
    for(int i = 0; i < 60; i++){
        ll zero = 0, one = 0;
        for(int j = 0; j < n; j++){
            int x = (a[j]>>i) & 1;
            if(x == 0) zero++;
            else one++;
        }
        ll cnt = zero * one;
        cnt %= MOD;
        cnt *= digits;
        cnt %= MOD;
        ans += cnt;
        ans %= MOD;

        digits *= 2L;
        digits %= MOD;
    }

    cout << ans << endl;

    return 0;
}