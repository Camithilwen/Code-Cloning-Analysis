#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,Y;
  cin >> X >> Y;

  int ans=0;
  vector<int> a={0,300000,200000,100000};
  if(X<=3)  ans+=a.at(X);
  if(Y<=3)  ans+=a.at(Y);
  if(X==1 && Y==1)  ans+=400000;
  cout << ans << endl;

  return 0;
}
