#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf 1e9
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mod 1000000007
#define pb push_back
#define all(s) s.begin(),s.end()
#define pie 3.14159265358979323846
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=b-1;i>=a;i--)
#define gcd __gcd
#define con continue
#define pii pair<ll,ll>
const ll N=5e5+6;
ll seg[4*N];
void build(ll s,ll e,ll idx,ll a[]){
    if(s==e){
       //cout<<s<<" ";
       seg[idx]=a[s];
       return;
    }
    ll mid=(s+e)/2;
    build(s,mid,2*idx+1,a);
    build(mid+1,e,2*idx+2,a);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    return ;
}
void update(ll s,ll e,ll idx,ll pos,ll val){
    if(s==e){
       seg[idx]=val;
       return;
    }
    ll mid=(s+e)/2;
    if(pos<=mid)
    update(s,mid,2*idx+1,pos,val);
    else
    update(mid+1,e,2*idx+2,pos,val);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    return ;
}
ll query(ll s,ll e,ll idx,ll l,ll r){
   if(s>=l&&e<=r)return seg[idx];
   if(s>r||e<l)return 0;
   ll mid=(s+e)/2;
   return query(s,mid,2*idx+1,l,r)+query(mid+1,e,2*idx+2,l,r);
}
signed main(){
    FASTIO;
    ll tt=1;
    //cin>>tt;
    while(tt--){
         ll n,q,x,l,r;cin>>n>>q;
         ll a[n];
         for(ll i=0;i<n;i++){
            cin>>a[i];
         }
         build(0,n-1,0,a);
         while(q--){
            cin>>x;
            if(x){
               cin>>l>>r;
               cout<<query(0,n-1,0,l,r-1)<<"\n";
            }
            else{
               cin>>l>>x;
               a[l]+=x;
               update(0,n-1,0,l,a[l]);
            }
         }
    }
}
