/*
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
*/
#include<bits/stdc++.h>
#define ALL(x) (x).begin(),(x).end()
#define ll long long
#define db double
#define ull unsigned long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 2e5+5;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int A[maxn],B[maxn];
struct seg_tree{
    ll tr[maxn<<2],lazy[maxn<<2];

    void push_up(int id)
    {
        tr[id] = min(tr[id<<1], tr[id<<1|1]);
    }
    void push_down(int id)
    {
        if(lazy[id]!=0){
            tr[id<<1] += lazy[id],tr[id<<1|1] += lazy[id];
            lazy[id<<1] += lazy[id],lazy[id<<1|1] += lazy[id];
            lazy[id] = 0;
        }
    }
    void update(int id,int stl,int str,int l,int r,ll k)
    {
        if(stl==l && str==r){
            tr[id] += k;
            lazy[id] += k;
            return ;
        }
        push_down(id);
        int mid = (stl+str)>>1;
        if(r<=mid) update(id<<1,stl,mid,l,r,k);
        else if(l>mid) update(id<<1|1,mid+1,str,l,r,k);
        else update(id<<1,stl,mid,l,mid,k),update(id<<1|1,mid+1,str,mid+1,r,k);
        push_up(id);
    }
    ll query(int id,int stl,int str,int l,int r)
    {
        if(stl==l && str==r) return tr[id];
        push_down(id);
        int mid = (stl+str)>>1;
        if(r<=mid) return query(id<<1,stl,mid,l,r);
        else if (l>mid) return query(id<<1|1,mid+1,str,l,r);
        else return min(query(id<<1,stl,mid,l,mid), query(id<<1|1,mid+1,str,mid+1,r));
    }
}dp,rec;
int main()
{
    fastio();
    int n,m; cin>>n>>m;
    rep(i,1,n) cin>>A[i]>>B[i];
    rep(i,1,m) rec.update(1,1,m,i,i,-i);
    rep(i,1,n){
        int R = B[i] + 1;
        if(R<=m){
            ll mi = rec.query(1,1,m,1,B[i]);
            ll now = dp.query(1,1,m,R,R);
            if(now > mi + R){
                dp.update(1,1,m,R,R,mi+R-now);
                ll tmp = rec.query(1,1,m,R,R);
                rec.update(1,1,m,R,R,mi-tmp);
            }
        }
        dp.update(1,1,m,A[i],B[i],inf);
        rec.update(1,1,m,A[i],B[i],inf);
        dp.update(1,1,m,1,m,1);
        rec.update(1,1,m,1,m,1);
        ll ans = dp.tr[1];
        if(ans >= inf) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
