//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int x;
  cin >> x;
  int c500 = 500;
  int c5 = 5;
  int ans = (x / 500) * 1000 + ((x % 500) / 5) *5;
  cout << ans;
 
}