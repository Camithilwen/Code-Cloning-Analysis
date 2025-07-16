#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int k, is;
  cin >> k >> s;
  is = s.size();
  if(k >= is){
    cout << s << endl;
  }
  else{
    for(int i = 0; i < k; i++){
      cout << s.at(i);
    }
    cout << "..." << endl;
  }
}