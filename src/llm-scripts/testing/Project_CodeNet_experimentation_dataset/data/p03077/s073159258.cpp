#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    ll N;
    cin >> N;
    vector<ll> V(5);
    ll min_v = 1e16;
    for(int i=0; i<5; i++) {
        cin >> V[i];
        min_v = min(min_v, V[i]);
    }
    ll X = N/min_v;
    if(N % min_v == 0) {
        X--;
    }
    cout << 5 + (ll)(X) << endl;
}