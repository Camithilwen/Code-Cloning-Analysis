#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string s;
  cin >> s;
  string t = "";
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      string tmp;
      if (i == 0){
        tmp += 'S';
      } else {
        tmp += 'W';
      }
      if (j == 0){
        tmp += 'S';
      } else {
        tmp += 'W';
      }
      for (int k = 2; k < N; k++){
        if ((tmp[k - 1] == 'S') ^ (s[k - 1] == 'o') ^ (tmp[k - 2] == 'S')){
          tmp += 'S';
        } else {
          tmp += 'W';
        }
      }
      bool ok = true;
      if ((tmp[N - 2] == 'S') ^ (tmp[N - 1] == 'S') ^ (tmp[0] == 'S') ^ (s[N - 1] == 'o')){
        ok = false;
      }
      if ((tmp[N - 1] == 'S') ^ (tmp[0] == 'S') ^ (tmp[1] == 'S') ^ (s[0] == 'o')){
        ok = false;
      }
      if (ok){
        t = tmp;
      }
    }
  }
  if (t == ""){
    cout << -1 << endl;
  } else {
    cout << t << endl;
  }
}