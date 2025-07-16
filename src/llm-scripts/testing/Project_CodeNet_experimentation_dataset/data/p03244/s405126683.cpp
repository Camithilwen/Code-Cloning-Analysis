///\/\/\/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, ll>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    nvarep(n,v);
    map<int,int>fm,bm;
    rep(i,0,n){
        if(i%2==0)fm[v[i]]++;
        else bm[v[i]]++;
    }
    vector<p>f,b;
    irep(i,fm){
        f.pb(mp(i->second,i->first));
    }
    irep(i,bm){
        b.pb(mp(i->second,i->first));
    }
    f.pb(mp(0,0));
    b.pb(mp(0,0));
    sort(range(f));
    reverse(range(f));
    sort(range(b));
    reverse(range(b));
    if(f[0].second==b[0].second){
        cout<<n-max(f[0].first+b[1].first,f[1].first+b[0].first)<<nnn;
    }else{
        cout<<n-f[0].first-b[0].first<<nnn;
    }
    return 0;
}