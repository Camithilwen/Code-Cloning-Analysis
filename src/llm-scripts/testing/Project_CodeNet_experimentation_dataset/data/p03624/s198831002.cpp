#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <iostream>
#include <set>
 
int main(void){
  string s;cin >> s;
  vector<int> v(26,0);
  for(char c:s) v[c-'a']++;
  for(int i;i<26;i++){
    if(!v[i]) {
      char c = 'a' +i;
      cout << c <<endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}