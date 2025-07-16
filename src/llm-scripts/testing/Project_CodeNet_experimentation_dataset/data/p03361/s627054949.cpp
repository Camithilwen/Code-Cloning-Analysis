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
void  solve(){
  int h,w;
  cin>>h>>w;
  char x[h][w];
  rep(i,0,h){
    rep(j,0,w){
      cin>>x[i][j];
    }
  }
  rep(i,0,h){
    rep(j,0,w){
      int flag=0;
      if(x[i][j]=='#'){
        if(i>0) flag+= x[i-1][j]==x[i][j]?1:0;
        if(i<h-1) flag+= x[i+1][j]==x[i][j]?1:0;
        if(j>0) flag+= x[i][j-1]==x[i][j]?1:0;
        if(j<w-1) flag+= x[i][j+1]==x[i][j]?1:0;
        if(flag==0){
          cout<<"No\n";
          return;
        }
      }

    }
  }
  cout<<"Yes\n";
}
int main(){
    optimizeIO();
    // tc
    { solve();
    }
}
