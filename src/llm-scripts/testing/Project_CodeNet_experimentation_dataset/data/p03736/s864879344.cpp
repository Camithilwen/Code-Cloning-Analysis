#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define endl '\n'
using namespace std;
const int N=2e5+100;
ll seg[N*4][2];
ll lazy=0;
void upd(ll nod,ll b,ll l,ll r,ll id,ll val){
    if (r-l==1){
        seg[nod][b]=min(seg[nod][b],val);
        return;
    }
    ll mid=(r+l)/2;
    if (mid>id) upd(nod*2,b,l,mid,id,val);
    else upd(nod*2+1,b,mid,r,id,val);
    seg[nod][b]=min(seg[nod*2][b],seg[nod*2+1][b]);
    return ;
}
ll get(ll nod,ll b,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return (ll)1e15;
    if (l>=L && r<=R) return seg[nod][b];
    ll mid=(r+l)/2;
    return min (get(nod*2,b,l,mid,L,R),get(nod*2+1,b,mid,r,L,R));
}
ll n,a[N],x,y,q;
int32_t main(){
    cin >> n >> q >> x >> y;
    for (int i=1;i<=q;i++){
        cin >> a[i];
    }
    memset(seg,31,sizeof seg);
    a[0]=x;
    upd(1,0,1,N,y,-y);
    upd(1,1,1,N,y,y);
    for (int i=1;i<=q;i++){
        ll z=min(get(1,0,1,N,1,a[i])+a[i],get(1,1,1,N,a[i],N)-a[i]);
        ll t=abs(a[i]-a[i-1]);
     //   cout << z << " " << lazy << endl;
        z+=lazy;
        lazy+=t;
        z-=lazy;
        upd(1,0,1,N,a[i-1],z-a[i-1]);
        upd(1,1,1,N,a[i-1],z+a[i-1]);
    }
    ll ans=(ll)1e15;
    for (int i=1;i<=n;i++){
        ll z=get(1,0,1,N,i,i+1);
        z+=i;
        ll t=get(1,1,1,N,i,i+1);
        t-=i;
        ans=min(ans,min(z,t));
    }
    cout << ans+lazy << endl;
}
