#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=1<<18,INF=1<<29;

int main(){
  int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
  cout<<a+b+c+d+e+f-min({a,b,c,d})-min(e,f)<<endl;
}

