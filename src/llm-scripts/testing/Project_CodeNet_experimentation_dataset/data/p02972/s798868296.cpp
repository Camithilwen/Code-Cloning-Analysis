#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


const int MOD=1000000007;
int INF=100100100100100;
int a[200010];
int ans[200010];
signed main(){
  int n;cin>>n;
  int cnt=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=n;i>=1;i--){
    int sum=0;
    for(int j=2*i;j<=n;j+=i){
      sum+=ans[j];
    }
    ans[i]=(sum+a[i])%2;
    if(ans[i])cnt++;
  }
  cout<<cnt<<endl;
  for(int i=1;i<=n;i++){
    if(ans[i])cout<<i<<endl;
  }
  return 0;
}
