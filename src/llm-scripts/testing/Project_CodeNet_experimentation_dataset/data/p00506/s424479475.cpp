#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

void divisor(int n, vector<int>& vec){
  for(int i=1;i*i<=n;i++){
    if(n % i == 0){
      vec.push_back(i);
      if(i != n / i) vec.push_back(n / i);
    }
  }
}

main(){
  int n, in[3];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> in[i];
  }
  vector<int> ans;
  if(n == 2) divisor(gcd(in[0], in[1]), ans);
  else divisor(gcd(in[0], gcd(in[1], in[2])), ans);
  sort(ans.begin(), ans.end());
  for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
}