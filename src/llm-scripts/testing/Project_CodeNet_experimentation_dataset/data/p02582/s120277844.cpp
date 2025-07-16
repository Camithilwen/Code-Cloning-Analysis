#define rep(i,n) for (int i=0;i<n;i++)
#include <vector>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main(){
  string s;
  cin >> s;
  int co=0;
  rep(i,3){
    if(s.at(i)=='R') co++;
  }
  
  if(co==3)
    cout << 3 << endl;
  else if(co==2 && s.at(1)!='S')
    cout << 2 << endl;
  else if(co==0)
    cout << 0 << endl;
  else
    cout << 1 << endl;
    
    
}