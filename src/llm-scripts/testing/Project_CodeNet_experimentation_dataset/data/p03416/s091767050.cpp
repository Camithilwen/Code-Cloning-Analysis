#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, ans = 0;
  cin >> a >> b;
  while(a <= b){
    if(a / 10000 == a % 10 &&(a / 1000 - (a / 10000) * 10) == (a % 100 - a % 10) / 10){
      ans++;
    }
    a++;
  }
  cout << ans;
}