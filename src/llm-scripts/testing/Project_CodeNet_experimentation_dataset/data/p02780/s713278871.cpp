#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int>a(n);
  vector<double>kit(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    kit.at(i)=(a.at(i)+1.0)/2;
  }
  double ans=0,bf=0;
  for(int i=0;i<k;i++)
    bf+=kit.at(i);
  ans=bf;
  for(int i=k;i<n;i++){
    bf+=kit.at(i)-kit.at(i-k);
    ans=max(ans,bf);
  }
  cout << setprecision(9) << ans << endl;
  return 0;
}