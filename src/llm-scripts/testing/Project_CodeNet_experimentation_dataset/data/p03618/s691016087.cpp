#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  string S;
  cin>>S;
  vector<int64_t> A(26,0);
  int64_t a=-97,b=S.size();
  rep(i,b){
    int64_t c=S.at(i);
    A.at(a+c)++;
  }
  int64_t ans=b*(b-1)/2;
  rep(i,26){
    int64_t d=A.at(i);
    if(d>1) ans-=d*(d-1)/2;
  }
  cout<<ans+1;
}
