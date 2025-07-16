#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,m,d;
  cin>>n>>m>>d;
  cout << fixed << setprecision(8);
  double ans=1.000000*(n-d)/n*(m-1)/n;
  if(d!=0)ans*=2;
  cout<<ans<<endl;
}
