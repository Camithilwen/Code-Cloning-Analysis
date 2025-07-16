#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  string s = to_string(n);
  int ans = 0;
  for(int i = 0; i < 3; i++){
    if(s.at(i) == '7'){
      ans = 1;
    }
  }
  
  if(ans == 0){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }

}