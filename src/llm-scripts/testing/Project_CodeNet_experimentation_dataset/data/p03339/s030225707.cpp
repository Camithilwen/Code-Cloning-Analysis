#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int w = 0, e = 0;
  int ans[n];
  rep(i,n)ans[i] = 0;
  rep(i,n){
    ans[i] = w;
    if(s[i]=='W')w++;
  }
  rep(i,n){
    ans[n-1-i] += e;
    if(s[n-1-i]=='E')e++;
  }
  int minans = INF;
  rep(i,n)if(minans > ans[i]) minans = ans[i];
  cout << minans << endl;
  return 0;
}