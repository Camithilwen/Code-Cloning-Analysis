#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef int_fast64_t ll;

template<int N, typename T, T M>
struct ModFact {
    T fact[N+1];
    constexpr ModFact() : fact() {
        fact[0] = 1;
        for (int i=0; i<N; ++i)
            fact[i+1] = (fact[i]*(i+1))%M;
    }
};
 
ModFact<100000, ll, MOD> fact;

ll N, M, ans = 1, cnt = 1;
constexpr ll th = 1LL<<45;
char S[200000];

int main() {
    scanf("%lld\n", &N);
    M = N << 1;
    fread_unlocked(S, 1, M, stdin);
    if(S[0] == 'B' && S[M-1] == 'B') {
        bool f = false;
        for(size_t i = 0; i < M-1;) {
            if(S[i++] == S[i]) f ^= true;
            if(f) {
                ans *= (cnt << 1) - i;
                if(ans > th) ans %= MOD;
            }
            else if(++cnt > N) break;
        }
        if(cnt != N) ans = 0;
        else ans = ((ans % MOD) * fact.fact[N]) % MOD;
    } else ans = 0;
    printf("%lld\n", ans);
    return 0;
}
