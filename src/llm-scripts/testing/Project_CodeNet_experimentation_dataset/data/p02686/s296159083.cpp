#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int n;
bool bad = false;

int check(vector<pair<int, int>> p){
  sort(p.begin(), p.end());
  int sum = 0;
  for (int i = 0; i < n; i++) {
    auto x = p[i];
    int hituyo = x.first;
    int yojo = x.second;
    if (yojo >= 0) {
      if (hituyo <= sum) {
        sum += yojo;
      } else {
        bad = true;
        break;
      }
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  cin >> n;
  vector<pair<int, int>> p1, p2;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int tmp = 0;
    int hituyo = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(') {
        tmp++;
      } else {
        tmp--;
      }
      if ((-1) * tmp > hituyo) {
        hituyo = tmp * (-1);
      }
    }
    p1.emplace_back(hituyo, tmp);
    tmp = 0;
    hituyo = 0;
    for (int j = s.size() - 1; j >= 0; j--) {
      if (s[j] == ')') {
        tmp++;
      } else {
        tmp--;
      }
      if ((-1) * tmp > hituyo) {
        hituyo = tmp * (-1);
      }
    }
    p2.emplace_back(hituyo, tmp);
  }
  int sum1 = check(p1);
  int sum2 = check(p2);
  /*
  for (auto x : p) {
    cout << x.first << " " << x.second << endl;
  }
  //*/
  if (bad || sum1 != sum2) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
