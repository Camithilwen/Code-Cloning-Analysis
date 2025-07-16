#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N = 0;
    cin >> N;
    ll M = 0;
    cin >> M;
    vector<ll> p(M,0);
    vector<string> S(M);
    for(ll i = 0; i < M; i++) {
        cin >> p.at(i);
        cin >> S.at(i);
    }


    
    vector<int> A(N,0);
    vector<bool> B(N,0);
    ll sum = 0;
    ll ans = 0;
    for (size_t i = 0; i < M; i++) {
        if(S.at(i) == "AC" && !B.at(p.at(i) - 1)) {
            ans++;
            sum += A.at(p.at(i) - 1);
            B.at(p.at(i) - 1) = 1;
        } else if (S.at(i) == "WA" && !B.at(p.at(i) - 1)) {
            A.at(p.at(i) - 1)++;
        }
    }
    
    cout << ans << ' ' << sum << endl;

    return 0;
}