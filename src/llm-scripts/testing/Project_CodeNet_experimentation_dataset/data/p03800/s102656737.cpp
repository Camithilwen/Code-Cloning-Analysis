#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int a[100009];
  for(int b: {0, 1}){
    for(int c: {0, 1}){
      a[1] = b;
      a[2] = c;
      a[0] = (s[1]=='o'?1:0)^b^c;
      for(int i=3;i<n;i++){
        a[i] = (s[i-1]=='o'?1:0)^a[i-1]^a[i-2];
      }
      if((s[n-1]=='o'?1:0)^a[n-1]==a[0]^a[n-2] && (s[0]=='o'?1:0)^a[0]==a[n-1]^a[1]){
        for(int i=0;i<n;i++){
          cout << (a[i]==1?'S':'W');
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}

