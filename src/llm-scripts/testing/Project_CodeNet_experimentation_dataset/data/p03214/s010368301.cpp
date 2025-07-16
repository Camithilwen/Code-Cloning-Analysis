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
  double N;
  cin>>N;
  vector<double>a(N);
  double sum=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    sum+=a[i];
  }
  double m=sum/N;
  double dis=9999999;
  for(int i=0;i<N;i++){
    if(dis>abs(a[i]-m)){dis=abs(a[i]-m);}
  }
  for(int i=0;i<N;i++){
    if(abs(a[i]-m)==dis){cout<<i<<endl;return 0;}
  }
  return 0;
}