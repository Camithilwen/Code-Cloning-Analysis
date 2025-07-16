#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string str;

  cin >> n;
  cin >> str;

  vector<int> vW(n+1,0),vE(n+1,0);

  for(int i=0;i<n;i++){
    vW[i+1]+=vW[i];
    if(str[i]=='W') vW[i+1]++;
    vE[i+1]+=vE[i];
    if(str[i]=='E') vE[i+1]++;
  }

  int ans=999999999;
  int now;

  for(int i=0;i<n;i++){
    now=vW[i]+(vE[n]-vE[i+1]);
    if(ans>now) ans=now;
  }


  cout << ans << endl;
}
