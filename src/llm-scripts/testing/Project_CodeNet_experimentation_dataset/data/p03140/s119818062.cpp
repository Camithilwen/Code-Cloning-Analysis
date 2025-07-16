#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int n;cin>>n;
  int ans=0;
  string s[3];cin>>s[0]>>s[1]>>s[2];
  rep(i,n){
    char c[3];
    rep(j,3)c[j]=s[j][i];
    sort(c,c+3);
    if(c[0]!=c[1])ans++;
    if(c[1]!=c[2])ans++;
  }
  cout<<ans<<endl;
  return 0;
}
