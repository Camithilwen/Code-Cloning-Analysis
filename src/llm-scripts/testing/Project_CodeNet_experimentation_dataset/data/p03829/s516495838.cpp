  #include <bits/stdc++.h>
  using namespace std;

  #define vi vector<int>
  #define all(v) v.begin(),v.end()
  #define ll long long int
  #define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define D1(x) {cerr<<" [" <<#x<<": "<<x<<"]";cout << endl;}
  #define D2(x) {cerr<<" [" <<#x<<": ";for(auto it:x)cerr<<it<< " ";cerr<<"] ";cout << endl;}

  const ll MOD=1e9+7;

  void solve(){
     ll n,a,b;
     cin >> n >> a >> b;
     vector<ll> v(n);
     for(int i=0;i<n;i++)cin >>v[i];
     ll ans=0;
     for(int i=0;i<n-1;i++){
        ans+= min((v[i+1]-v[i])*a,b);
     }
     cout << ans;
  }


  int main(){
    IOS
       solve();
  }
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
