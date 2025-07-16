#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minimum(ll a,ll b,ll c,ll d,ll e){
  return min(min(a,min(b,c)),min(d,e));
}

int main(){
  ll n,a,b,c,d,e;
  cin >> n >> a >> b >> c >> d >> e;
  ll time=4;
  ll data=minimum(a,b,c,d,e);
  time+=(n/data);
  if(n%data!=0){
    time++;
  }
  cout << time << endl;
}
