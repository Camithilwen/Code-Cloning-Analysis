#include <bits/stdc++.h>
#ifdef local
#define debug(a...) qqbx(#a, a)
template <typename H, typename ...T> void qqbx(const char *s, const H &h, T&&...a) {
    for(; *s && *s != ','; ++s) if(*s != ' ') std::cerr<<*s;
    std::cerr<<" = "<<h<<(sizeof...(T) ? ", " : "\n");
    if constexpr(sizeof...(T)) qqbx(++s, a...);
}
#else
#define debug(...) ((void)0)
#endif // local
#define pb emplace_back
#define all(v) begin(v),end(v)

using namespace std;
const int MOD = 1000000007, N = 200025, inf = 2e9;
int a[N], b[N], ca[N], cb[N];
int A[N], B[N];
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) ++ca[a[i]];
    for(int i = 0; i < n; i++) ++cb[b[i]];
    for(int i = 1; i <= n; i++) if(ca[i] + cb[i] > n) return cout << "No\n", 0;
    for(int i = 1; i <= n; i++) ca[i] += ca[i-1];
    for(int i = 1; i <= n; i++) cb[i] += cb[i-1];
    int mx = 0;
    for(int i = 1; i <= n; i++) mx = max(mx, ca[i] - cb[i-1]);
    cout << "Yes\n";
    for(int i = 0; i < n; i++)
        cout << b[(i+n-mx)%n] << ' ';
    cout << '\n';
}
