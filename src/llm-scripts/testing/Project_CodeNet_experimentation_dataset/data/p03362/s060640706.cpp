#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N;
bool prime[55556];
vector<ll> v;

signed main(){
    cin >> N;
    for(ll i = 2; i <= 55555; i++) prime[i] = true;
    for(ll i = 2; i <= 55555; i++){
        if(prime[i] == false) continue;
        if(i % 5 == 1) v.push_back(i);
        for(ll j = 2; i * j <= 55555; j++) prime[i * j] = false;
    }
    REP(i, N){
        cout << v[i];
        if(i == N - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}