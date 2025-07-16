#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int mod=1000000007;
  int n;
  cin >> n;
  long to=0;
  vector<int>a(n);
  vector<int>b(n);
  vector<int>c(n);
  rep(i,n){
    cin>>a.at(i)>>b.at(i);
    to-=b.at(i);
    c.at(i)=a.at(i)+b.at(i);
  }
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  rep(i,(n-1)/2+1){
    to+=c.at(i*2);
  } 
  cout<<to<<endl;  
}