#include<bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD = 998244353;

    string S;
    cin >> S;
    reverse(begin(S), end(S));
    unsigned long K;
    cin >> K;
    K = min<unsigned long>(count(begin(S), end(S), '1'), K);

    vector<vector<unsigned long>> dp(K + 1), tmp(K + 1);
    for(unsigned long i{0}; i <= K; ++i)dp[i] = vector(i + 1, 0UL);
    for(unsigned long i{0}; i <= K; ++i)tmp[i] = vector(i + 1, 0UL);
    dp[0][0] = 1;
    
    unsigned long cnt{0};
    for(const auto& c : S)if(c == '1')++cnt;
    else{
        for(auto&& i : tmp)fill(begin(i), end(i), 0UL);
        for(unsigned long i{0}; i < K; ++i)for(unsigned long j{0}; j + i < K; ++j){
            tmp[j + i + 1][i] = tmp[j + i][i] + dp[j + i][i];
            if(j >= cnt)tmp[j + i + 1][i] -= dp[j - cnt + i][i];
        }
        for(auto&& i : dp)partial_sum(begin(i), end(i), begin(i));
        for(unsigned long i{0}; i <= K; ++i)for(unsigned long j{0}; j <= i; ++j)(dp[i][j] += tmp[i][j]) %= MOD;
        cnt = 0;
    }
    for(auto&& i : dp)partial_sum(begin(i), end(i), begin(i));
    
    unsigned long ans{0};
    for(const auto& i : dp)ans += i.back();
    cout << ans % MOD << endl;
    return 0;
}