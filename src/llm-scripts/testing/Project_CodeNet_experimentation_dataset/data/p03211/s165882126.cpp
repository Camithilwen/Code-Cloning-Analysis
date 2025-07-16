#include<bits/stdc++.h>
using namespace std;
int main(){
  string s; cin >> s;
  int ans = 9999;
  for(int i = 0; i < s.size()-2; i++){
    string a;
    for(int j = i; j < 3 + i; j++)
      a.push_back(s.at(j));
    //cout << a << endl;
    ans = min(ans,abs(stoi(a)-753));
    a.erase(a.begin(),a.end());

  }
  cout << ans;
}