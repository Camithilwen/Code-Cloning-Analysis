  #pragma GCC optimize("Ofast")
  #pragma GCC target("avx,avx2,fma")
  #include <bits/stdc++.h>
  using namespace std;
  //---------------------------------//
  void __print(int x) {cerr << x;}
  void __print(long x) {cerr << x;}
  void __print(long long x) {cerr << x;}
  void __print(unsigned x) {cerr << x;}
  void __print(unsigned long x) {cerr << x;}
  void __print(unsigned long long x) {cerr << x;}
  void __print(float x) {cerr << x;}
  void __print(double x) {cerr << x;}
  void __print(long double x) {cerr << x;}
  void __print(char x) {cerr << '\'' << x << '\'';}
  void __print(const char *x) {cerr << '\"' << x << '\"';}
  void __print(const string &x) {cerr << '\"' << x << '\"';}
  void __print(bool x) {cerr << (x ? "true" : "false");}

  template<typename T, typename V>
  void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
  template<typename T>
  void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
  void _print() {cerr << "]\n";}
  template <typename T, typename... V>
  void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
  #ifndef ONLINE_JUDGE
  #define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
  #else
  #define deb(x...)
  #endif
 //------------------------------//

  typedef long long int ll;
  typedef pair<int,int> pi;
  typedef pair<ll,ll> pll;
  typedef vector<int> vi;
  typedef vector<ll> vll;
  typedef vector<pi> vpi;
  typedef vector<pll> vpll;

  #define  ff           first
  #define  ss           second
  #define  pb           push_back
  #define  IOS          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define  all(x)       (x).begin(), (x).end()
  #define  ps(x,y)      fixed<<setprecision(y)<<x
  #define  rep(i,a,b)   for(ll i=a ; i<b ; ++i)

  const ll MOD = 1e9 + 7;
  const ll INF = 1e18;
  const ll maxn = 1e6 + 4;

 // dp[i][2] -> dp[i][
  void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    vector<vector<ll>> dp(n+1,vector<ll>(2));
     // dp[i][0] max if here operation is applied;

    for(int i=1;i<=n;i++){
       if(i==1){
         dp[i][0] = -v[i-1];
         dp[i][1] = v[i-1];
       }
       else{
        dp[i][0] = max(dp[i-1][0]+v[i-1],dp[i-1][1]-v[i-1]);
        dp[i][1] = max(dp[i-1][0]-(v[i-1]),dp[i-1][1] + v[i-1]);
       }
    }
    cout << dp[n][1];
  }

  int main(){
    IOS
    	solve();
    //cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }

// integer overflow