#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;

int a[maxn];
ll sum[maxn];

ll rsum(int l, int r)
{
    return sum[r] - sum[l-1];
}

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    int N; cin >> N;
    for (int i=1; i<=N; ++i){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    int l=1, r=3;
    ll ret = 1e18;
    for (int i=2; i<=N-2; ++i){
        r = max(r, i+1);
        while (l<i-1 && rsum(1, l) < rsum(l+1, i)) ++l;
        if (l > 1 && abs(rsum(1, l-1) - rsum(l, i)) < abs(rsum(1, l) - rsum(l+1, i))) --l;
        while (r<N-1 && rsum(i+1, r) < rsum(r+1, N)) ++r;
        if (r > i + 1 && abs(rsum(i+1, r-1) - rsum(r, N)) < abs(rsum(i+1, r) - rsum(r+1, N))) --r;
        vector<ll> vi;
        vi.pb(rsum(1, l)); vi.pb(rsum(l+1, i)); vi.pb(rsum(i+1, r)); vi.pb(rsum(r+1, N));
        sort(vi.begin(), vi.end());
        ret = min(ret, vi[3] - vi[0]);
    }
    cout << ret << '\n';
}
