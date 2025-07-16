#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};
 
 
struct Timer{
    chrono::system_clock::time_point start, end;
    Timer(){ start = chrono::system_clock::now(); }
    ~Timer(){
        end = chrono::system_clock::now();
        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cerr<<"time : "<<msec<<" ms"<<endl;
    }
};
 
 
 
 
ll n;
ll a[200010]={};
ll cnt[200010]={};
vll G[200010];
ll ans[200010]={};
 

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Timer TM;
    

    ll n;
    ll ans=0;
    string s;
    unordered_map<string,ll> mp;
    cin>>n>>s;
    rep(bit,(1<<n)){
        string u="",t="";
        rep(i,n){
            if(bit&(1<<i)){
                u+=s[i];
            }
            else t+=s[i];
        }
        mp[u+'0'+t]++;
        // cout<<u+'0'+t<<endl;
    }
    rep(bit,(1<<n)){
        string u="",t="";
        rep(i,n){
            if(bit&(1<<i)){
                u=s[i+n]+u;
            }
            else t=s[i+n]+t;
        }
        if(mp[t+'0'+u]>0) ans+=mp[t+'0'+u];
    }
    cout<<ans<<endl;

    
    return 0;
}