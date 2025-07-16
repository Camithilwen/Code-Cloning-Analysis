#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,ans;
  ans=0;
  cin >> n;
  vector<string> s(3);
  
  for(int i=0;i<3;i++){
	cin >> s[i];
  }
  for(int i=0;i<n;i++){
    if(s[0][i]==s[1][i] && s[0][i]==s[2][i]);
    else if(s[0][i]==s[1][i] || s[0][i]==s[2][i] || s[1][i]==s[2][i])ans++;
    else ans+=2;
  }
  cout << ans;
  return 0;
}