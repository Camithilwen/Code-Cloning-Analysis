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
void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void  solve(){
  ll n,m;
  cin>>n>>m;
  ll a[n];
  rep(i,0,n) cin>>a[i];
  vector<ll> pre(n,0);
  map<ll,int> m1;
  pre[0]=a[0]%m;
  m1[pre[0]]++;
  rep(i,1,n) pre[i]=(pre[i-1]+a[i])%m,m1[pre[i]]++;
  ll ans=0;
  ll modsum=0;
  rep(i,0,n){
    if(i!=0) ans+= m1[pre[i-1]];
    else ans+=m1[0];
    m1[pre[i]]--;
  }
  cout<<ans<<endl;
}

int main(){
    optimizeIO();
    solve();
    // solve1();
}
