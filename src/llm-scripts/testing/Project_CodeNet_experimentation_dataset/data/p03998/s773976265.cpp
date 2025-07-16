#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  string a, b, c;
  cin >> a >> b >> c;

  queue<char> qa, qb, qc;
  for(char ch: a) qa.push(ch);
  for(char ch: b) qb.push(ch);
  for(char ch: c) qc.push(ch);
  char next = 'a';

  while(true) {
    if (next == 'a') {
      if (qa.empty()) {
        cout << 'A' << endl;
        return 0;
      }
      next = qa.front();
      qa.pop();
    }
    if (next == 'b') {
      if (qb.empty()) {
        cout << 'B' << endl;
        return 0;
      }
      next = qb.front();
      qb.pop();
    }
    if (next == 'c') {
      if (qc.empty()) {
        cout << 'C' << endl;
        return 0;
      }
      next = qc.front();
      qc.pop();
    }
  }

  return 0;
}
