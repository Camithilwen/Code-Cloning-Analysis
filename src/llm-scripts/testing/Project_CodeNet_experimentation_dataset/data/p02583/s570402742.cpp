//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main(){
  int n;
  cin >> n;
  vector<int> l(n);
  rep1(i, n){
    cin >> l[i];
  }
  int ans = 0;
  rep2(i, 0, n-2){
    rep2(j, i+1, n-1){
      rep2(k, j+1, n){
        int a = l[i];
        int b = l[j];
        int c = l[k];
        if(a != b && b != c && c != a && a+b > c && b+c > a && c+a > b){
          ans += 1;
          
        }
       
      }
    }
  }
  cout << ans;

}