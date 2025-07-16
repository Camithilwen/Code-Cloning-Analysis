#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  set <int> s;
  for(int i = 0;i < n;++i){
    int num;
    cin >> num;
    auto itr = s.find(num);
    if(itr == s.end()) s.insert(num);
    else s.erase(num);
  }
  cout << (int)s.size() << endl;
  return 0;
}