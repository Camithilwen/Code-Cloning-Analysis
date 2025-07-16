#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld long double
#define f first
#define s second
#define matrix vector<vector<char>>
#define zero(n,m) matrix(n , vector<char>(m,'0'))
#define one(n,m) matrix(n , vector<ll>(m,1))
#define pii pair<int,int>
#define point complex<ld>
#define angle(a) (atan2((a).imag() , (a).real() ))
#define pi acos(-1)
#define X real()
#define Y imag()
const int N = 2e5+5;

ll n , a[N] , b[N] , seg[4*N] , lazy[4*N];
ll st[N] , en[N] , st2[N] , en2[N];
set<ll> stt;

void probagate(int node , int st , int en)
{
    if (lazy[node] != 0)
    {
        seg[node] += lazy[node];
        if (st != en)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node , int st , int en , int l , int r , int val)
{
    probagate(node , st , en);

    if (st > en || st > r || en < l)
        return;

    if (st >= l && en <= r)
    {
        lazy[node] += val;
        return probagate(node , st , en);
    }

    int mid = (st+en)/2;
    update(2*node,st,mid,l,r,val);
    update(2*node+1,mid+1,en,l,r,val);
    seg[node] = max(seg[2*node] , seg[2*node+1]);
}

ll query(int node , int st , int en , int l , int r)
{
    if (st > en || st > r || en < l) return 0;

    probagate(node , st , en);

    if (st >= l && en <= r)
    {
        return seg[node];
    }

    int mid = (st+en)/2;

    return max(query(2*node , st , mid , l , r) , query(2*node+1 , mid+1 , en , l , r));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if (!st[a[i]]) st[a[i]] = i;
        en[a[i]] = i;
    }

    for(int i=1; i<=n; i++)
    {
        cin >> b[i];
        if (!st2[b[i]]) st2[b[i]] = i;
        en2[b[i]] = i;
        stt.insert(b[i]);
    }

    for(ll i=1; i<=n; i++)
    {
        ll l = st[b[i]] , r = en[b[i]];
        if (l > i)
        {
            update(1,0,n-1,0,l-i-1,1);
        }
        l = max(en[b[i]]+1,i) , r = n;
        if (l<=r)
        {
            ll l2 = l-i , r2 = r-i;
            if (l2 <= r2)
            {
                update(1,0,n-1,l2,r2,1);
            }
        }

        //from one to st[b[i]]-1
        l = 1 , r = min(st[b[i]]-1 , i-1);
        if (l<=r)
        {
            ll l2 = n-i+l , r2 = n-i+r;
            if (l2 <= r2)
            {
                update(1,0,n-1,l2,r2,1);
            }
        }

        if (i > en[b[i]])
        {
            l = en[b[i]]+1 , r = i-1;
            if (l<=r)
            {
                ll l2 = n-i+l , r2 = n-i+r;
                if (l2 <= r2)
                {
                    update(1,0,n-1,l2,r2,1);
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if (query(1,0,n-1,i,i) == n)
        {
            cout << "Yes\n";
            for(int j=1; j<=n; j++)
            {
                int newIdx = j + i;
                if (newIdx > n) newIdx -= n;
                a[newIdx] = b[j];
            }
            for(int j=1; j<=n; j++)
                cout << a[j] << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}