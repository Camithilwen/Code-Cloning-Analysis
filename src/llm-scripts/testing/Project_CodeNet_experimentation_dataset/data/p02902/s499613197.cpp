//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
////////////////////////////

ll n,m;
#define N 1005
vector<ll>v[N];
ll used[N];

vector<ll>row;
vector<ll>cyc;
bool dfs(ll k){
    if(cyc.size()!=0)return 0;
    for(auto x:v[k]){
        if(used[x]==1){
            if(cyc.size()!=0)return 0;
            bool fl=false;
            rep(i,0,row.size()-1){
                if(fl)cyc.pb(row[i]);
                else if(row[i]==x){
                    cyc.pb(row[i]);fl=true;
                }
            }
            return 0;
        }else if(used[x]==0){
            row.pb(x);
            used[x]=1;
            dfs(x);
            row.pop_back();
        }
    }
    return 0;
}

int main(){fastio
    cin>>n>>m;
    rep(i,1,m){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
    }
    rep(i,1,n){
        if(used[i]==0){
            row.pb(i);
            dfs(i);
            rep(j,1,n){
                if(used[j]==1)used[j]=2;
            }
        }
    }
    if(cyc.size()==0){
        cout<<-1;return 0;
    }
    
    rep(i,1,n)sort(v[i].begin(),v[i].end());
    bool ok[n+1];memset(ok,false,sizeof(ok));
    while(1){
        bool flag=true;
        vector<ll>newcyc;
        ll cs=cyc.size();
        rep(i,0,cs-1){
            if(!flag)break;
            ll top=cyc[i];
            if(ok[top])continue;
            for(ll qj=(i+cs-1);qj>=i+2;qj--){
                ll j=qj%cs;
                if(*lower_bound(v[top].begin(),v[top].end(),cyc[j])==cyc[j]){
                    
                    if(i<j){
                        rep(k,0,i)newcyc.pb(cyc[k]);
                        rep(k,j,cs-1)newcyc.pb(cyc[k]);
                    }else{
                        rep(k,j,i)newcyc.pb(cyc[k]);
                    }
                    ok[top]=true;
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            cout<<cyc.size()<<endl;
            for(auto x:cyc)cout<<x<<endl;
            return 0;
        }else{
            cyc.clear();
            for(auto x:newcyc)cyc.pb(x);
        }
    }
    return 0;
}
