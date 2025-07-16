#include <bits/stdc++.h>


using namespace std;

using ll = long long;


int main(void) {
    ll N, M;
    cin >> N >> M;
    ll even_max_len = M % 2 == 0 ? M : M - 1;
    ll odd_max_len = M % 2 == 1 ? M : M - 1;
    for (ll i = M; i > 0; i--) {
        if (i % 2 == 0) {
            ll j = (even_max_len - i) / 2;
            printf("%lld %lld\n", 1 + j, 1 + j + i);
        } else {
            ll base = even_max_len + 2;
            ll j = (odd_max_len - i) / 2;
            printf("%lld %lld\n", base + j, base + j + i);
        }
    }
}
