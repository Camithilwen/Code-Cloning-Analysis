#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, M, V, P;
  cin>>N>>M>>V>>P;
  vector<ll> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  ll l=0, r=N-1, m;
  ll score;
  ll vote;
  vector<ll> tmparr(N);
  ll zero = 0;
  int index;
  while(l<r) {
    m = (l+r)/2;
    score = M+A[m];
    vote = M*(V-1);
    for(int i=0;i<N;++i) {
      if(i!=m) vote -= min(M, max(zero, score-A[i]));
      tmparr[i] = max(score, A[i]);
    }
    for(int i=N-1;i>=0;--i) {
      if(vote>0) {
        vote -= M-max(score-A[i], zero);
        tmparr[i] = score+1;
      }
    }
    index = upper_bound(tmparr.begin(), tmparr.end(), score)-tmparr.begin();
    if(N-index<P) r = m;
    else l=m+1;
  }
  cout<<N-l<<endl;
}

