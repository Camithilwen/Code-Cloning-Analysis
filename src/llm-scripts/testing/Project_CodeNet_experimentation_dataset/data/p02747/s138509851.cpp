#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool flag = (s.size()%2 == 0);
  while(s.size()>0 && flag){
    if(s.substr(0,2) == "hi"){
      s = s.substr(2,s.size()-2);
    }
    else flag = 0;
  }
  cout << (flag?"Yes":"No") << endl;
}