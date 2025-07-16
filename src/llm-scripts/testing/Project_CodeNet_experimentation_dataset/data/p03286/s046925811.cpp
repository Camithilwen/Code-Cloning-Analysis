#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  string ans = "";
  while(n){
    if(n%2==0){
      ans.push_back('0');
    }else{
      ans.push_back('1');
      n -= 1;
    }
    n /= (-2);
  }
  if(int(ans.size())==0)ans.push_back('0');
  rep(i,int(ans.size())){
    cout << ans[int(ans.size())-1-i];
  }
  cout << endl;
  return 0;
}