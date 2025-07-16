#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll s;
  cin>>s;
  
  int mi=1000;
  while(s>=100){
    mi=min(mi,abs(753-int(s%1000)));
    s/=10;
  }
  
  cout<<mi<<endl;

  return 0;
}