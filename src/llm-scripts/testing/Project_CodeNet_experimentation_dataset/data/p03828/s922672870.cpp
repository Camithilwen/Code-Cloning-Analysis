#include <bits/stdc++.h>
#define rep(i,s,n) for (int i=s;i<n;++i)
#define drep(i,s,n) for (int i=n;i>=s;--i)
#define all(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define print(x) cout<<(x)<<endl
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{if (a%b == 0) return(b);
 else          return(gcd(b,a%b));}
ll lcm(ll a,ll b)
{return a/gcd(a,b)*b;}
void printv(vector<auto> v) {cout<<'[';rep(i,0,v.size()){cout<<v[i]<<',';}cout<<']'<<endl;}
void printvv(vector<vector<auto>> vv)
{cout<<'['<<endl;
  rep(q,0,vv.size()){cout<<'[';rep(p,0,vv.at(q).size())cout<<vv.at(q).at(p)<<',';cout <<']'<<endl;}
  cout<<']'<<endl;}
void solve(); int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}
int step_x[] = {-1,0,0,1};
int step_y[] = {0,-1,1,0};
ll INF=1e18;
//------------------------------------------------------------
int N;
int nums[1100];
ll ans=1;

void solve() {
  cin>>N;

  rep(i,1,N)
  {
    int num = i+1;
    for(int j=2*num;j<=N;j+=num) nums[j]=1;
  }

  rep(i,1,N)
  {
    int num = i+1;
    if(nums[num]==0)
    {
      ll tmp=0;
      for(int j=num; j<=N; j*=num) tmp+=N/j;
      // tmp+=N/num;
      ans = ans*(tmp+1)%(int)(1e9+7);
    }
  }

  print(ans);
  return;
}