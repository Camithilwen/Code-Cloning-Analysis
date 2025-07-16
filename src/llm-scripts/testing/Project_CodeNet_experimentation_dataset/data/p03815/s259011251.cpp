#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

const ll C = 1000000007;

int main(){
    ll x;
    cin >> x;

    ll n = x / 11;
    n *= 2;
    ll m = x % 11;
    if (m > 6) {
        n += 2;
    }
    if(m > 0 && m <= 6) {
        n++;
    }
    cout << n << endl;
}