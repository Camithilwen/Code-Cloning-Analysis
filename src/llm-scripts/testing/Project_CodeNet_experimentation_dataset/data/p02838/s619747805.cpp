  #include <bits/stdc++.h>
  using namespace std;

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
  #define  D(x)         cout << #x << " - " << x << endl;
  #define  D2(x)        cout << "[" << #x << ": "; for(auto it:x) cout << it << " "; cout << "]" << endl;
  #define  all(x)       (x).begin(), (x).end()
  #define  D2p(x)       cout << #x << " ~ [ "; for(auto n: x) cout << n.first << "-" << n.second << " / "; cout << "]" << endl;
  #define  ps(x,y)      fixed<<setprecision(y)<<x
  #define  rep(i,a,b)   for(ll i=a ; i<b ; ++i)

  const ll MOD = 1e9 + 7;
  const ll INF = 1e18;
  const ll maxn = 1e6 + 4;


  void solve(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	vi bits(64);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	for(int i=0;i<n;i++){
		ll k = v[i];
		int j =0;
		while(k>0){
		   bits[j++] += (k%2);
		   k/=2;
		}
	}
	ll prod = 1;
	ll lst=0;
	ll finalans=0;
	for(int i=0;i<63;i++){
		ll k = bits[i]*(n-bits[i]);
		ll st = (lst+k)%2;
		lst = (lst+k)/2;
		finalans = (finalans + (st*prod))%MOD;
		prod = (prod%MOD*2%MOD)%MOD;
	}

	while(lst>0){
		ll st = (lst)%2;
		finalans = (finalans+(st)*prod)%MOD;
		lst=(lst)/2;
		prod = (prod%MOD*2%MOD)%MOD;
	}
	
	cout << finalans;
  }

  int main(){
    IOS
    solve();
    cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }

// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
