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
  int K,T;
  cin>>K>>T;
  vector<int>a(T);
  for(int i=0;i<T;i++){
    cin>>a[i];
  }

  sort(a.rbegin(),a.rend());
  
  int cnt=0;
  for(int i=0;i<T;i++){
    int cap=K-a[i];
    cnt+=max(a[i]-1-cap,0);
  }
  cout<<cnt<<endl;
  return 0;
}