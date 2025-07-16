#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;
const int N = 1e6 + 10;

long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
     int n,k;cin >> n >> k;
     vector<int>a(n);
     int cnt = 0;
     int sum = 0;
     for(int i = 0;i<n;i++){
        cin >> a[i];
        if(a[i]>0) sum += a[i];
        if(a[i]<0) cnt++;
     }
    if(k>=n+cnt){
        cout << sum;
        return;
    }
    vector<int>l(220,0);
    multiset<int>ms;
    l[0] = 0;int now = 0;
    for(int i = 0;i<k;i++){
        int cnt = 0;sum = 0;
        now += a[i];
        ms.insert(a[i]);
        l[i+1] = max(l[i+1],max(l[i],now));
        for(auto it : ms){
            if(it<0) {cnt++;sum += it;l[i+cnt+1] = max(now-sum,l[i+cnt+1]);}
            else break;
        }
       // cout << l[i+1] <<endl;
    }
    ms.clear();
    vector<int>r(220,0);
    r[0] = 0;
    reverse(a.begin(),a.end());
    now = 0;
    for(int i = 0;i<k;i++){
        int cnt = 0;sum = 0;
        now += a[i];
        ms.insert(a[i]);
        r[i+1] = max(r[i+1],max(r[i],now));
        for(auto it : ms){
            if(it<0) {cnt++;sum += it;r[i+cnt+1] = max(r[i+cnt+1],now-sum);}
            else break;
        }
    }
    int ans = 0;
    for(int i = 0;i<=k;i++){
        ans = max(ans,r[i]+l[k-i]);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}