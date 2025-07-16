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
int sa[100010];
signed main(){
  int n;cin>>n;
  int ans=0;
  rep(i,n){
    int a,b;cin>>a>>b;
    sa[i]=a+b;
    ans-=b;
  }
  sort(sa,sa+n,greater<int>());
  for(int i=0;i<n;i+=2){
    ans+=sa[i];
  }
  cout<<ans<<endl;
  return 0;
}
