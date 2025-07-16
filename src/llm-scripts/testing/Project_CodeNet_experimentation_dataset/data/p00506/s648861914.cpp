#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <functional>
#include <cmath>
#include <cstdio>
using namespace std;

#define PI 4*atan(1);

int main(){
  int n, a, b, c;
  vector<int> ans;
  ans.push_back(1);
  cin >> n;
  if(n == 2){
    cin >> a >> b;
    for(int i = 2; i < max(a, b); i++){
      if(a % i == 0 && b % i == 0){
        ans.push_back(i);
      }
    }
    for(int i = 0; i < ans.size(); i++){
      cout << ans[i] << endl;
    }
  }else if(n == 3){
    cin >> a >> b >> c;
    for(int i = 2; i < max(max(a, b), c); i++){
      if(a % i == 0 && b % i == 0 && c % i == 0){
        ans.push_back(i);
      }
    }
    for(int i = 0; i < ans.size(); i++){
      cout << ans[i] << endl;
    }
  }
}