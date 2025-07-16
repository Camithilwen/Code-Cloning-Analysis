#include <iostream>
#include<string>
#include<map>
using namespace std;

int main(){
  string s; cin >> s;
  int check[26] = {};
  for(int i = 0; i < s.size(); i++){
    int t = s[i]-'a';
    check[t] = 1;
  }
  for(int i = 0; i < 26; i++){
    if(check[i] == 0) { 
      char ans = 'a' + i;
      cout << ans << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}
