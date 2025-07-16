#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,inf=1e10;
ll n,ans;
pair<ll,ll> prfx[N],sfx[N],a[N];
inline pair<ll,ll> inter(pair<ll,ll> u,pair<ll,ll> v){
    pair<ll,ll> range = make_pair( max(v.first,u.first) , min(v.second,u.second) );
    range.second = max(range.first,range.second);
    return range;
}
inline void relax(pair<ll,ll> v,pair<ll,ll> u){
    ans = max(ans , v.second - v.first + u.second - u.first);
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i].first>>a[i].second,a[i].second++;
    sort(a,a+n);
    prfx[0]=make_pair(0,inf);
    for(ll i=0;i<n;i++)prfx[i+1]=inter(prfx[i],a[i]);
    sfx[n]=make_pair(0,inf);
    for(ll i=n-1;i>=0;i--)sfx[i]=inter(sfx[i+1],a[i]);
    for(ll i=0;i<n;i++)relax(a[i],inter(prfx[i],sfx[i+1]));
    for(ll i=1;i<n;i++)relax(prfx[i],sfx[i]);
    cout<<ans;
}
