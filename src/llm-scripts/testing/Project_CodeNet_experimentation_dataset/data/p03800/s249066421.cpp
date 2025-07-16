#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int N;
string S;

string Mena(string str) {
  string res = str;
  for (int i = 2; i < N; i++) {
    if ((S[i-1] == 'o' && res[i-1] == 'S') || (S[i-1] == 'x' && res[i-1] == 'W')) {
      res += res[i-2]; 
    } else {
      if (res[i-2] == 'W') {
        res += 'S';
      } else {
        res += 'W';
      }
    }
  }
  bool m = true;
  if ((S[N-1] == 'o' && res[N-1] == 'S') || (S[N-1] == 'x' && res[N-1] == 'W')) {
    if (res[N-2] != res[0]) {
      m = false;
    }
  } else {
    if (res[N-2] == res[0]) {
      m = false;
    }
  }
  if ((S[0] == 'o' && res[0] == 'S') || (S[0] == 'x' && res[0] == 'W')) {
    if (res[N-1] != res[1]) {
      m = false;
    }
  } else {
    if (res[N-1] == res[1]) {
      m = false;
    }
  }
  if (m) return res;
  else return "NG";
} 
int main() {
  cin >> N >> S;
  string cand[4];
  cand[0] = Mena("SS");
  cand[1] = Mena("SW");
  cand[2] = Mena("WS");
  cand[3] = Mena("WW");
  for (int i = 0; i < 4; i++) {
    if (cand[i] != "NG") {
      cout << cand[i] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0; 
}