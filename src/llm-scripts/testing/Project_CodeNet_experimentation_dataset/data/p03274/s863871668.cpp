#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}
int main() {
  int N,K;
  cin>>N>>K;
  vector<int>x(N);
  for(int i=0;i<N;i++){
    cin>>x[i];
  }
  vector<int>dis;
  for(int i=0;i<N-1;i++){
    dis.push_back(x[i+1]-x[i]);
  }
  vector<int64_t>table(N+2);
  for(int i=0;i<N-1;i++){
    table[i+1]=table[i]+dis[i];
  }
  int64_t ans=999999999999999;
  for(int i=0;i<N;i++){
    if(N-K>=i){
    int64_t sum=0;
    int start=min(abs(x[i]),abs(x[i+K-1]));
    sum=start+table[i+K-1]-table[i];
    //cout<<sum<<endl;
    ans=min(ans,sum);
    }
  }
  cout<<ans<<endl;
  return 0;
}