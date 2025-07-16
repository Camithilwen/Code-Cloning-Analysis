#include<bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    unsigned long N;
    cin >> N;
    vector<unsigned long> a(N + 1);
    for(unsigned long i = 1, A; i <= N; ++i){
        cin >> A;
        a[i] = a[i - 1] ^ A;
    }
    auto f = [&MOD](auto& a, auto k){(a.second += (a.first += a.second * k) %= MOD) %= MOD; return a.first;};
    if(a.back()){
        unsigned long k = 0;
        pair<unsigned long, unsigned long> p{1, 0};
        for(const auto i : a)
            if(i == a.back())f(p, k), k = 0;
            else if(!i) ++k;
        cout << p.first << endl;
    }else{
        vector<pair<pair<unsigned long, unsigned long>, unsigned long>> tapi(1048576, {{1, 0}, 0});
        vector<unsigned long> zeros(N + 2);
        unsigned long ans{0}, t{250000002};
        for(unsigned long i = 0; i <= N; ++i){
            zeros[i + 1] = zeros[i] + !a[i];
            if(a[i]){
                ans += f(tapi[a[i]].first, zeros[i + 1] - zeros[tapi[a[i]].second]);
                tapi[a[i]].second = i + 1;
            }else (t *= 2) %= MOD;
        }
        cout << (ans + t) % MOD << endl;
    }
    return 0;
}