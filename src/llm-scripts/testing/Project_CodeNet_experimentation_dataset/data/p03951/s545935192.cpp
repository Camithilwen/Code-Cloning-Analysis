#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  string s,t;
  cin >> s >> t;

  rep(i,n){
    int same=n-i;

    bool check=true;
    rep(j,same){
      if(s.at(n-same+j)!=t.at(j)){check=false; break;}
    }

    if(check){cout<<n*2-same; return 0;}
  }

  cout << n*2;
}