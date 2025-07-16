#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)

using namespace std;
string repeat(string s, int n) {
    string s1 = "";
    for (int i=0; i<n;i++)
        s1+=s;
    return s1;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
void solve(){
  int n;
  cin>>n;
  int a[n+2];
  rep(i,1,n+1) cin>>a[i];
  a[0]=0;
  a[n+1]=0;
  // int mn=*min_element(a,a+n),mx=*max_element(a,a+n);
  int v1[n+1],pref[n+1];
  rep(i,0,n+1) v1[i]=abs(a[i+1]-a[i]);//a[i+1]*a[i]>=0?abs(a[i+1]-a[i]):abs(a[i+1]-a[i])*2;
  pref[0]=v1[0];
  rep(i,1,n+1) pref[i]=pref[i-1]+v1[i];
  rep(i,1,n+1){
    ll ans=abs(a[i+1]-a[i-1])-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+pref[n];
    cout<<ans<<endl;
  }
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
