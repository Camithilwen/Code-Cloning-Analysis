#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int w;
  cin >> w;
  int n=1;
  if(w==1){
    cout << s << endl;
    return 0;
  }
  for(int i=0; i<s.size(); i++){
    if(n%w==1) cout << s[i];
    n++;
  }
  cout << endl;
}
      
