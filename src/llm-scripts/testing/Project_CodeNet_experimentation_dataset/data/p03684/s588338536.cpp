#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 2000005
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define vi vector<ll>
#define vp vector<pii>
#define all(v) v.begin(),v.end()
#define sz(x) (ll)x.size()
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
typedef long long ll;
using namespace std;
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

ll mexp(ll a, ll b){
    ll ans=1;
    a%=MOD;
    while(b){
        if(b&1) ans=ans*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return ans;
}

const int N = 100005;

bool cmp1(pair<int,pair<int,int>>a, pair<int,pair<int,int>>b){
    return a.S.F<b.S.F;
}

bool cmp2(pair<int,pair<int,int>>a, pair<int,pair<int,int>>b){
    return a.S.S<b.S.S;
}

pair<int,pair<int,int>>c[N];
int par[N],siz[N];

int find(int x){
    while(par[x]!=x){
        x=par[x];
    }
    return x;
}

void un(int a,int b){
    a=find(a);
    b=find(b);
    if(siz[a]<siz[b]){
        par[a]=par[b];
        siz[b]+=siz[a];
    }
    else{
        par[b]=par[a];
        siz[a]+=siz[b];
    }
}

int main(){
    IOS

    int n;
    cin>>n;
    FOR(i,1,n+1){
        par[i]=i;
        siz[i]=1;
        c[i].F=i;
        cin>>c[i].S.F>>c[i].S.S;
    }

    vector<pair<int,pair<int,int>>>v;

    sort(c+1,c+n+1,cmp1);

    FOR(i,1,n){
        v.pb(mp(c[i+1].S.F-c[i].S.F,mp(c[i].F,c[i+1].F)));
    }
    sort(c+1,c+n+1,cmp2);
    FOR(i,1,n){
        v.pb(mp(c[i+1].S.S-c[i].S.S,mp(c[i].F,c[i+1].F)));
    }
    sort(all(v));

    int cnt=0;
    int i=0;
    ll ans=0;
    while(cnt<n-1){
        int x=find(v[i].S.F),y=find(v[i].S.S);
        if(x==y){
            i++;
            continue;
        }
        un(x,y);
        ans+=v[i].F;
        i++;
        cnt++;
    }
    cout<<ans;

    cerr<<"Time: "<<1.0/CLOCKS_PER_SEC<<" ms"<<endl;
    return 0;
}