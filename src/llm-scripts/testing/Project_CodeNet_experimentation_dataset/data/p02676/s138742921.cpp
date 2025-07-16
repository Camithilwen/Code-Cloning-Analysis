#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  
  if(s.length() <= n) cout << s << endl;
  
  else{
  	for(int i = 0; i < n; i++) cout << s[i];
  
  	cout << "..." << endl;
  }
}