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
  vector<char>s(4);
  for(int i=0;i<4;i++){
    cin>>s[i];
  }
  for(int p=0;p<(1<<3);p++){
    string t;int sum=s[0]-'0';
    t.push_back(s[0]);
    for(int i=0;i<3;i++){
      if((p>>i)&1){sum+=(s[i+1]-'0');t.push_back('+');}
      else{sum-=(s[i+1]-'0');t.push_back('-');}
      t.push_back(s[i+1]);
    }
    t+="=7";
    if(sum==7){cout<<t<<endl;return 0;}
  }
  return 0;
}