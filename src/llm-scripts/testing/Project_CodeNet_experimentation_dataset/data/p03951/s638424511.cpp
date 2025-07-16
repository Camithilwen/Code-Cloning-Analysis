#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  string s,t; cin>>s>>t;
  int ans=2*n;
  for(int i=0; i<n; i++){
    int s_index=n-1-i;
    int now_ans=2*n-(i+1);
    bool flag=1;
    for(int t_index=0; t_index<=i; t_index++){
      if(t[t_index]!=s[s_index])flag=0;
      s_index++;
    }
    if(flag){
      ans=now_ans;
    }
  }
  cout<<ans<<endl;
}
