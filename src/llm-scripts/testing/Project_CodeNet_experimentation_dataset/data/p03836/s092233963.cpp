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
  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  int dx=abs(sx-tx);
  int dy=abs(sy-ty);
  cout<<string(dx,'R')<<string(dy,'U');
  cout<<string(dx,'L')<<string(dy,'D');
  cout<<'L'<<string(dy+1,'U')<<string(dx+1,'R')<<'D';
  cout<<'R'<<string(dy+1,'D')<<string(dx+1,'L')<<'U';
  cout<<endl;
  return 0;
}