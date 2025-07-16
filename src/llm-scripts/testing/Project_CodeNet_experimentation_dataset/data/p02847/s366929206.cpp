#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  vector<string> D = {"SUN","MON","TUE","WED","THU","FRI","SAT"}; 
  string S;
  cin >> S;
  int ans=0;
  rep(i,7){
    if(D[i]==S) ans = 7-i;
  }
  cout << ans << endl;
  return 0;
}
