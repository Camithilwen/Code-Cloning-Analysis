
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
using namespace std;

#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define INF               1e18
#define ff                first
#define ss                second
#define vi                vector<int>
#define pii               pair<int,int>
#define mii               map<int,int>
#define endl              "\n"
#define GCD(x,y)          (__gcd((x), (y)))
#define LCM(x,y)          (((x)/__gcd((x), (y)))*(y))
#define debug(x)          cout<<#x<<" is "<<(x)<<endl
#define mem(a,x)          memset(a,x,sizeof(a))
#define rep(i,a,b)        for(long long i=a;i<b;i++)
#define sp(ans,p)         fixed <<setprecision(p)<<ans;
#define IOS ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

constexpr int N = 5e5 + 5;
constexpr int BLOCK = 710;

struct query
{
    int l;
    int r;
    int i;
};

query Q[N];
int ar[N] , ans[N];
int fre[N];
int cntdist = 0;
mii m;

//enhanced comparator
bool comp(query a, query b)
{
    if (a.l / BLOCK != b.l / BLOCK)
    {
        return a.l < b.l;
    }
    if ((a.l / BLOCK) & 1)
    {
        return a.r < b.r;
    }
    return a.r > b.r;
}

void add(int pos)
{
    if (fre[ar[pos]] == 0)
    {
        cntdist++;
    }
    fre[ar[pos]]++;
}

void remove(int pos)
{
    if (fre[ar[pos]] == 1)
    {
        cntdist--;
    }
    fre[ar[pos]]--;
}


void solve()
{
    int n , q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> ar[i];


    for (int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i , Q[i].l-- , Q[i].r--;
    }

    sort(Q , Q + q , comp);

    //why ML = 0 , and MR = -1?
    int ML = 0 , MR = -1;
    for (int i = 0; i < q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;

        while (ML > L)
            ML-- , add(ML);

        while (MR < R)
            MR++ , add(MR);

        while (ML < L)
            remove(ML) , ML++;

        while (MR > R)
            remove(MR) , MR--;

        ans[Q[i].i] = cntdist;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
    return;
}


signed main()
{
    IOS;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // sieve();
    int t = 1;
    // cin >> t;
    while (t--)   solve();
    return 0;
}