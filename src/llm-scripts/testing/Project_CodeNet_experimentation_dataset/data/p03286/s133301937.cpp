#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=10007;


int main() {
  int N;
  cin>>N;
  string t;
  int x=N;
  if(x==0){cout<<0<<endl;return 0;}
  while(x){
    int a=x%(-2);
    if(a<0){a+=2;x-=2;}
    t.push_back(a+'0');
    x/=(-2);
  }
  reverse(t.begin(),t.end());
  cout<<t<<endl;
  return 0;  
}