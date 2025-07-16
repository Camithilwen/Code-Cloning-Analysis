#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  set<int> s;
  for(int i = 0; i < n; i++){
    //cout << s.size() << endl;
    int a; cin >> a;
    if(s.count(a))
       s.erase(a);
    else
       s.insert(a);
  }
  cout << s.size() << endl;
}
