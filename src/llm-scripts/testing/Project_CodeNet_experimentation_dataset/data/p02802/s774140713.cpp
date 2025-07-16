#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N,M;
  cin>>N>>M;
  vector<bool> isAC(N, false);
  vector<int> check(N,0);
  int wans=0, cans=0;
  int p;
  string s;
  for(int i=0; i<M; i++){
    cin>>p>>s;
    if(isAC.at(p-1)) continue;
    else{
      if(s=="AC"){
        isAC.at(p-1) = true;
        cans++;
        wans+=check.at(p-1);
      }
      else{
        check.at(p-1)++;
      }
    }
  }
  cout<<cans<<" "<<wans<<"\n";
}