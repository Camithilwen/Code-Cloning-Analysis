#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,M;
  cin>>N>>M;
  VI A(N-1+M),B(N-1+M);
  rep(i,N-1+M) cin>>A[i]>>B[i];
  VVI X(N,VI(0));
  VI I(N);
  rep(i,N-1+M){
    X[A[i]-1].pb(B[i]-1);
    I[B[i]-1]++;
  }
  int S=0;
  rep(i,N) if(I[i]==0) S=i;
  VI T(0);
  T.pb(S);
  queue<int> Q;
  Q.push(S);
  VI F(N);
  F[S]++;
  while(!Q.empty()){
    int now=Q.front();
    Q.pop();
    rep(i,X[now].size()){
      int nxt=X[now][i];
      if(!F[nxt]){
        I[nxt]--;
        if(!I[nxt]){
          Q.push(nxt);
          T.pb(nxt);
        }
      }
    }
  }
  VI Z(N);
  rep(i,N){
    int now=T[i];
    if(!Z[now]) Z[now]=1;
    rep(j,X[now].size()){
      int nxt=X[now][j];
      Z[nxt]=max(Z[nxt],Z[now]+1);
    }
  }
  VI ans(N);
  rep(i,N){
    rep(j,X[i].size()){
      int nxt=X[i][j];
      if(Z[i]+1==Z[nxt]) ans[nxt]=i+1;
    }
  }
  ans[S]=0;
  rep(i,N) cout<<ans[i]<<endl;
}
