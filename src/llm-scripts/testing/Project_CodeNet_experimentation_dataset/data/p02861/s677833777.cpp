#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define MOD 1000000007
#define mod 998244353
#define pie 3.14159265358979323846264338327950L
#define N 200009
#define M 2000009
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define umap unordered_map<int, int>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define endl "\n"
#define int long long
using namespace std;
 
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}
 

vector<pair<int,int> > arr(10);

map<pair<int,int>,ld> mp;
ld ans = 0;
int n;
void fun(vector<int> temp, ld curr) {
    if(temp.size() == n) {
        ans+= curr;
        // for(auto it : temp) {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return;
    }
    for(int i=0; i<n; i++) {
        if(find(all(temp),i) == temp.end()) {
            int prev = temp.back();
            temp.push_back(i);
            fun(temp,curr + mp[mpr(i,prev)]);
            temp.pop_back();
        }
    }
}
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
 

void test_case() {
    
    
    cin>>n;

    COMinit();

    
    rep(i,n) {
        int x,y;
        cin>>x>>y;
        arr[i] = mpr(x,y);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ld  d= pow(arr[i].first - arr[j].first,2) + pow(arr[i].second -arr[j].second,2);
            d = sqrt(d);
            // cout<<d<<endl;
            mp[mpr(i,j)] = d;
            mp[mpr(j,i)] = d;
        }
    }
    

    vec temp;
    for(int i=0; i<n; i++) {
        temp.push_back(i);
        fun(temp,0.0);
        temp.pop_back();

    }

    ld fin = ans/fac[n];

    // cout<<ans<<endl;

    cout<<fin<<endl;


}
    

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int t = 1;
    // cin >> t;
    while (t--)
    {
        test_case();
    }
}