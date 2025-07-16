#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[6];
  cin >> s;
  for(int i=0;i<5;i++){
    if(s[i]=='A'&&s[i+1]=='C'){
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}
