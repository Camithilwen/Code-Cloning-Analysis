#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, t, s;
  string result;
  cin >> d >> t >> s;
  
  if(d <= t*s){
    result = "Yes";
  }else{
    result = "No";
  }
    

  cout << result << endl;
}
