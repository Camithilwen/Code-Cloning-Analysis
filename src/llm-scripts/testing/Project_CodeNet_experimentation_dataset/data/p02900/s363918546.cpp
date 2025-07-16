#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <numeric>


using namespace std;
#define ll long long

vector<int> prime(ll f){
  vector<int> ans(1,2);
  for(int i = 3;i <= sqrt(f);i ++){
    int p = 0;
    bool jud = true;
    while(ans[p]<=sqrt(i)){
      if(i % ans[p] == 0){
        jud = false;
        break;
      }
      p++;
    }
    if(jud == true){
      ans.insert(ans.end(),i);
    }
  }
  return ans;
}

int main(void){
  ll a,b;
  cin >> a >> b;
  while(a !=  b){
    if(a > b){
      if(a % b == 0){
        a = b;
      }else{
        a = a % b;
      }
    }else{
      if(b % a == 0){
        b = a;
      }else{
        b = b % a;
      }
    }
  }
  vector<int> pri = prime(a);
  vector<int> prnum(pri.size()+1,0);
  int s = pri.size();
  for(int i = 0;i < s;i ++){
    while(a % pri[i] == 0){
      a = a / pri[i];
      prnum[i] ++;
    }
    if(a == 1){
      break;
    }
  }
  if(a != 1){
    prnum[pri.size()]++;
  }
  int ans = 1;
  s = prnum.size();
  for(int i = 0;i < s;i ++){
    if(prnum[i]>0){
      ans++;
    }
  }
  cout << ans << endl;
  
  return 0;
}