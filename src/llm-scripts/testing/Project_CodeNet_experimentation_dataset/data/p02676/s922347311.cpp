#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;
  cin >> k >> s;
  int n = s.size();
  if(n <= k){
    cout << s << endl;
    return 0;
  }else{
    int i = 0;
    while(i<=k-1){
      cout << s.at(i);
      if(i==k-1){
        cout << "..." << endl;
        return 0;
      }
      i++;
    }
  }
}