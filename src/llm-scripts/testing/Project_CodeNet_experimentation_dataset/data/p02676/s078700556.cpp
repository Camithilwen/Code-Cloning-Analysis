//abc168

#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  int k;
  string s;
  cin >> k >> s;

  if(s.size() <= k){
    cout << s;
  }else{
    cout << s.substr(0,k) << "..." << endl;
  }

}
