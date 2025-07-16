#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
long long digits(long long num) {
    long long digit = num;
    int       d_sum = 0;
    while (digit > 0) {
        ++d_sum;
        digit /= 10;
    }
    return d_sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    cin >> N;
    long long ans = INF;
    for (long long A = 1; A < sqrt(N) + 1; ++A) {
        if (N % A == 0) { ans = min(ans, max(digits(A), digits(N / A))); }
    }
    cout << ans << endl;
}
