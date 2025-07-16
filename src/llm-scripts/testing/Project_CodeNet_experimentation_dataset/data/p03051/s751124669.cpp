#include<bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    vector<unsigned long> tapi(1048576, 1), tapu(1048576), tape(1048576);
    unsigned long ans{0}, t{500000004}, a{0}, z{0}, A;cin >> A;
    while(cin >> A)if(a ^= A){
        (tapu[a] += (tapi[a] += tapu[a] * (z - tape[a])) %= MOD) %= MOD;
        ans += tapi[a];
        tape[a] = z;
    }else ++z, (t *= 2) %= MOD;
    cout << (a ? tapi[a] : (ans + t) % MOD) << endl;
    return 0;
}