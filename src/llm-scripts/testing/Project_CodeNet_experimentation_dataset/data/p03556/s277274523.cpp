#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    ll n;
    cin >> n;
    vector<ll> sq;
    ll cnt = 1;
    while (cnt * cnt <= n)
    {
        sq.push_back(cnt*cnt);
        cnt++;
    }
    sort(sq.begin(), sq.end());
    cout << sq[sq.size() - 1] << endl;
    return 0;
}