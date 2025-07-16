#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  int len=0;
  for(int i=0;i<n;i++){
    bool ok=true;
    for(int j=0;j<n-i;j++)
      if(a.at(i+j)!=b.at(j))
        ok=false;
    if(ok)
      len=max(n-i,len);
  }
  cout << n*2-len << endl;
  return 0;
}