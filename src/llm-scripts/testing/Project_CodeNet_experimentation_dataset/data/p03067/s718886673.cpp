#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const long long INF = 1LL << 60;
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  if(A<=C&&C<=B){
      cout<<"Yes"<<endl;
  }
  else if(B<=C&&C<=A){
      cout<<"Yes"<<endl;
  }
  else{
      cout<<"No"<<endl;
  }
}
