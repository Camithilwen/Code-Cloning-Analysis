#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
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
const ll INF=1e17;
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
ll ans1=0;
void recur(vector<pair<char,int>> str,int val,ll sum,int idx){
  if(val<0) return;
  else if(val==0){
    ans1=max(ans1,sum);
    return;
  }
  if(idx>=str.size()) return;
  rep(j,idx,str.size()){
    recur(str,val-str[j].s,sum*10+str[j].f-'0',idx+1);
    recur(str,val-str[j].s,sum*10+str[j].f-'0',idx);
  }
}
void  solve(){
  int n,m2;
  cin>>n>>m2;
  int a[m2];
  rep(i,0,m2) cin>>a[i];
  sort(a,a+m2);
  map<int,int> m,m1;
  m[1]=2;
  m[2]=5;
  m[3]=5;
  m[4]=4;
  m[5]=5;
  m[6]=6;
  m[7]=3;
  m[8]=7;
  m[9]=6;
  rep(i,0,m2){
    m1[m[a[i]]]=a[i];
  }
  int sma= (*m1.begin()).s;
  int rep = max(n/m[sma]-7,0);
  int rem=n%m[sma]+min(n/m[sma],7)*m[sma];

  string ans="";
  ans+=repeat(getString('0'+sma),rep);
  vector<pair<char,int>> str;
  for(auto i:m1){
    str.pb({i.s+'0',i.f});
  }
  ans1=0;
  recur(str,rem,0,0);
  vector<char> res;
  rep(i,0,ans.length()) res.pb(ans[i]);
  // cout<<ans1<<endl;
  while(ans1){
    res.pb(ans1%10+'0');
    ans1/=10;
  }
  sort(all(res),greater<char>());
  rep(i,0,res.size()) cout<<res[i];
  cout<<endl;
  // if(rem==0) cout<<ans<<endl;
  // else{
  //   int mx=-1;
  //   for(auto i:m1){
  //     if(i.f<=rem) mx=max(mx,i.s);
  //   }
  //   cout<<rem<<endl;
  //   if(mx!=-1 && sma>mx) ans+= getString(mx+'0');
  //   else if(mx!=-1 && sma<=mx) ans=getString(mx+'0')+ans;
  //   cout<<ans<<endl;
  // }
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
