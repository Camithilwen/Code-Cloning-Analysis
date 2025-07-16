#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int         int64_t
#define ii          pair<int,int>
#define dd          pair<double,double>
#define vi          vector<int>
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define checkBit(v, p)      (v&(1LL << p))
#define loop(i,a,b) for(int i = a;i < int(b);i++)
#define x           first
#define y           second
#define chkmin(a,b) (a) = min((a), (b))
#define chkmax(a,b) (a) = max((a), (b))
using namespace std;
int inf = 1e9, mod = 1e9;
vi ps;
inline int sum(int l, int r)
{
    return ps[r + 1] - ps[l];
}

inline int diff(int l, int mid, int r)
{
    return abs(sum(mid, r) - sum(l, mid - 1));
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    int n; cin >> n;
    ps.resize(n + 1);
    ps[0] = 0;
    vi arr(n);
    for (int i=0;i<n;i++) cin >> arr[i], ps[i + 1] = ps[i] + arr[i];
    vi l(n, -1),r(n, -1);
    l[1] = 1;
    r[n - 2] = n - 1;
    for(int i = 2,ind = 1, s; i < n;i++)
    {
        s = diff(0, ind, i);
        while(ind <= i && s > diff(0, ind + 1, i)) s = diff(0, ++ind, i);
        l[i] = ind;
    }

    for(int i = n - 3,ind = n - 1, s; i >= 0;i--)
    {
        s = diff(i, ind, n - 1);
        while(ind > i && s > diff(i, ind - 1, n - 1)) s = diff(i, --ind, n - 1);
        r[i] = ind;
    }
    int mini = 2e18;
    for(int i = 2; i < n - 1;i++)
    {
        vi vals(4);
        vals[0] = sum(0, l[i - 1] - 1);
        vals[1] = sum(l[i - 1], i - 1);
        vals[2] = sum(i, r[i] - 1);
        vals[3] = sum(r[i], n - 1);
        mini = min(mini, *max_element(all(vals)) - *min_element(all(vals)));
    }
    cout << mini << endl;
    return 0;
}
