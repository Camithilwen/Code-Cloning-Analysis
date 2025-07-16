#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,K;
  cin>>N>>K;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<K;i++){
    vector<int>B(N,0);
    for(int j=0;j<N;j++){
      int l=max(0,j-A[j]);
      int r=min(N,j+A[j]+1);
      B[l]++;
      if(r<N)B[r]--;
    }
    for(int i=0;i<N-1;i++)B[i+1]+=B[i];
    A=B;
    bool ok=true;
    for(auto it:A)if(it!=N)ok=false;
    if(ok)break;
  }
  for(auto it:A)cout<<it<<" ";
  cout<<endl;

  return 0;
}
