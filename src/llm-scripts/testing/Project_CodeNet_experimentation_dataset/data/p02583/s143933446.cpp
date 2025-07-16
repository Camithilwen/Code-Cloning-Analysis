#include <bits/stdc++.h>
using namespace std;

#define fastio                  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define input_output            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 

#define ll                      long long
#define read1(x)                 cin>>x
#define read2(x,y)               cin>>x>>y
#define print(x)                cout<<x<<endl
#define pii                     pair<int, int>
#define pli                     pair<ll, int>
#define pil                     pair<int, ll>
#define pll                     pair<ll, ll>
#define vi                      vector<int>
#define vll                     vector<ll>
#define vb                      vector<bool>
#define vd                      vector<double>
#define vs                      vector<string>
#define ff                      first
#define ss                      second
#define pb                      push_back
#define ppb                     pop_back
#define pf                      push_front
#define ppf                     pop_front
#define vpii                    vector<pii>
#define umap                    unordered_map
#define uset                    unordered_set
#define clr(a,b)                memset(a,b,sizeof a)
#define all(ds)                 ds.begin(), ds.end()
#define rev(ds)                 ds.rbegin(), ds.rend()
#define asc(A)                  sort(A.begin(), A.end())
#define dsc(A)                  sort(A.begin(), A.end(), greater<int>())
#define gcd(x,y)                __gcd(x,y)
#define clr(a,b)                memset(a,b,sizeof a)
#define fr(i, n)                for(int i=0; i<n;++i)
#define fr1(i, n)               for(int i=1; i<=n; ++i)
#define rfr(i, n)               for(int i=n-1; i>=0; --i)
#define printVector(v)          for(int i= 0;i<v.size();i++) {cout<<v[i]<<" ";} cout<<endl;
#define precise(x)              cout<<fixed<<setprecision(x)
#define inf                     10000000000000

 

ll lcm(ll a, ll b) {return (a*b)/__gcd(a, b); }
ll power(ll x, ll y, ll m) { if(!y) return 1; ll p=power(x, y>>1, m)%m; p=p*p%m; return (y&1)?(x*p)%m:p;}
ll modInverse(ll a, ll m){ return power(a, m-2, m); }
bool isPrime(ll num){bool flag=true;for(ll i =2;i<=num/2;i++){if(num%i==0) {flag=false; break;} }return flag;}
ll sumofdigits(ll n){ll c=0;while(n>0){c++;n/=10;}return c;}
bool sortinrev(const pair<int,int>&a,const pair<int,int>&b) {return a.first > b.first; }
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {return a.second < b.second; }

//const double PI= 2*acos(0.0);
const long long MOD= 1000000007;



void solve(){
    int n; cin>>n;
    vi v;
    fr(i, n){
        int x; cin>>x;
        v.push_back(x);
    }
    sort(all(v));
    if(v.size() <= 2){
        print(0);
        return;
    }
    int count = 0;
    for(int i = 0; i < n-2; ++i){
        for(int j = i+1; j < n-1; ++j){
            if(v[i] == v[j])continue;
            for(int k = j+1; k < n; ++k){
                if(v[i] == v[k] || v[j] == v[k])continue;
                if(v[i] + v[j] > v[k])count++;
            }
        }
    }
    cout<<count<<endl;

}
int main()
{
#ifndef ONLINE_JUDGE  
    input_output  
#else   
    fastio
#endif

    int t =1 ;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}