#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define MOD 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 100005
#define M 1e6+9
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll,ll>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"
#define int long long
using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}

// ll n,k,a,b,c,d,x,y,z,m,l;
// ll ans;
// vecl arr(N);
// ll dp[509][509];
// ll pre[N];



void test_case() {

    
   ll n,k;
   cin>>n>>k;

   vector<ld> arr(n), temp(n);
   rep(i,n) {
       cin>>arr[i];
   }

   for(int i=0; i<n; i++)
    {
        temp[i] = (arr[i] + 1)/2;
    }

    ld ans = 0;
    ld sum =0;
    for(int i=0; i<k; i++) {
        sum+= temp[i];
    }

    ans = sum;

    for(int i=k; i<n; i++) {
        sum+= temp[i] - temp[i-k];
        ans = max(ans, sum);
    }

    cout<<ans<<endl;
   








}


int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int t = 1;
    // cin >> t;
    while(t--)
    {   
        test_case();
    }
}
