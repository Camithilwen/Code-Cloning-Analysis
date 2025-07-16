// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n;
  string s;
  cin >> n >> s;
  vector<ll> a(n,0);
  for(int x=0;x<2;x++){
    for(int y=0;y<2;y++){
      a[0] = x;
      a[1] = y;
      for(int i=1;i<n-1;i++){
        //sheep
        if(a[i]==0){
          if(s[i]=='o'){
            a[i+1] = a[i-1];
          }else{
            a[i+1] = !a[i-1];
          }
        //wolf
        }else{
          if(s[i]=='o'){
            a[i+1] = !a[i-1];
          }else{
            a[i+1] = a[i-1];
          }
        }
      }
      bool is_ans=true;
      if(a[0]==0){
        if(s[0]=='o'&&a[1]!=a[n-1]){
          is_ans = false;
        }else if(s[0]=='x'&&a[1]==a[n-1]){
          is_ans = false;
        }
      }else{
        if(s[0]=='o'&&a[1]==a[n-1]){
          is_ans = false;
        }else if(s[0]=='x'&&a[1]!=a[n-1]){
          is_ans = false;
        }
      }
      if(a[n-1]==0){
        if(s[n-1]=='o'&&a[n-2]!=a[0]){
          is_ans = false;
        }else if(s[n-1]=='x'&&a[n-2]==a[0]){
          is_ans = false;
        }
      }else{
        if(s[n-1]=='o'&&a[n-2]==a[0]){
          is_ans = false;
        }else if(s[n-1]=='x'&&a[n-2]!=a[0]){
          is_ans = false;
        }
      }
      if(is_ans){
        for(int i=0;i<n;i++){
          if(a[i]==0) cout <<"S";
          else cout <<"W";
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << "-1\n";
}
