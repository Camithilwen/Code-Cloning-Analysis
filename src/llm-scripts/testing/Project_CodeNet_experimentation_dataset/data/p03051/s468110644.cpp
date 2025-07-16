#include<bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    auto f = [&MOD](auto& a, auto k){(a.second += (a.first += a.second * k) %= MOD) %= MOD; return a.first;};
    unsigned long N;
    cin >> N;
    vector<pair<pair<unsigned long, unsigned long>, unsigned long>> tapi(1048576, {{1, 0}, 0});
    unsigned long ans{0}, t{500000004}, a{0}, z{0};
    for(unsigned long i = 1, A; i <= N; ++i){
        cin >> A;
        if(a ^= A){
            ans += f(tapi[a].first, z - tapi[a].second);
            tapi[a].second = z;
        }else ++z, (t *= 2) %= MOD;
    }
    cout << (a ? tapi[a].first.first : (ans + t) % MOD) << endl;
    return 0;
}