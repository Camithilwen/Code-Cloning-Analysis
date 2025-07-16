#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s.size()==3){
	for(int i=2;i>=0;i--){
      cout << s.at(i);
    }
    cout << endl;
  }
  else{
    cout << s << endl;
  }
}
