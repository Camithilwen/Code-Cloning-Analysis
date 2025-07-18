#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(long long N, std::string S, long long Q, std::vector<long long> k)
{

    for (ll i = 0; i < Q; i++) {
        ll D = 0;
        ll M = 0;
        ll DM = 0;
        ll DMC = 0;
        ll ans = 0;
        for (ll j = 0; j < N; j++) {
            if (j - k[i] >= 0) {
                if (S[j - k[i]] == 'D') {
                    D--;
                    DM -= M;
                }
                if (S[j - k[i]] == 'M') {
                    M--;
                }
            }
            if (S[j] == 'D') {
                D++;
            }
            if (S[j] == 'M') {
                M++;
                DM += D;
            }
            if (S[j] == 'C') {
                DMC += DM;
            }
            ans = max(ans, DMC);
        }
        cout << ans << "\n";
    }
}

// Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main()
{
    long long N;
    scanf("%lld", &N);
    std::string S;
    std::cin >> S;
    long long Q;
    scanf("%lld", &Q);
    std::vector<long long> k(Q - 1 - 0 + 1);
    for (int i = 0; i < Q - 1 - 0 + 1; i++) {
        scanf("%lld", &k[i]);
    }
    solve(N, S, Q, std::move(k));
    return 0;
}
