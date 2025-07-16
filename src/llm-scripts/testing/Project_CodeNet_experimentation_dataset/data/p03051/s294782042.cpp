#include<bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    unsigned long N;
    cin >> N;
    vector<pair<pair<unsigned long, unsigned long>, unsigned long>> tapi(1048576, {{1, 0}, 0});
    unsigned long ans{0}, t{500000004}, a{0}, z{0}, A;
    while(cin >> A)if(a ^= A){
        (tapi[a].first.second += (tapi[a].first.first += tapi[a].first.second * (z - tapi[a].second)) %= MOD) %= MOD;
        ans += tapi[a].first.first;
        tapi[a].second = z;
    }else ++z, (t *= 2) %= MOD;
    cout << (a ? tapi[a].first.first : (ans + t) % MOD) << endl;
    return 0;
}