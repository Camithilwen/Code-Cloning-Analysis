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

ll ans;
int N, M, cnt = 0;
constexpr ll th = 1LL<<45;
char S[200000];

int main() {
    scanf("%d%s", &N, S);
    M = N << 1;
    ans = fact.fact[N];
    char *E = S + M, *C = S;
    while(C < E) {
		if((*C++^cnt)&1) {
            ans = ans * cnt % MOD;
            if(--cnt < 0) break;
        } else ++cnt;
	}
    printf("%lld\n", cnt == 0 ? ans : 0);
    return 0;
}
