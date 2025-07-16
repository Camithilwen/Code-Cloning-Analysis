#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline char dif(char sp) {
  if (sp == 'S') {
    return 'W';
  } else {
    return 'S';
  }
}

inline char next(char prevsp, char prevsay, char nowsp, char nowsay) {
  char res;
  if (nowsp == 'S') {
    if (nowsay == 'o') {
      res = prevsp;
    } else {
      res = dif(prevsp);
    }
  } else {
    if (nowsay == 'o') {
      res = dif(prevsp);
    } else {
      res = prevsp;
    }
  }
  return res;
}

string process(char ze, char one, string say, int n) {
  string ani(n + 2, '0');
  ani[0] = ze;
  ani[1] = one;
  for (int i = 2; i <= n + 1; i++) {
    ani[i] = next(ani[i - 2], say[i - 2], ani[i - 1], say[i - 1]);
  }
  return ani;
}

bool check(string &result, int n) {
  bool res;
  if (result[0] == result[n] && result[1] == result[n + 1]) {
    res = true;
  } else {
    res = false;
  }
  result.pop_back();
  result.pop_back();
  return res;
}
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s.push_back(s[0]);
  string result;
  char sp[2] = {'S', 'W'};
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      result = process(sp[i], sp[j], s, n);
      if (check(result, n)) {
        cout << result << endl;
        return 0;
      }
    }
  cout << -1 << endl;
}
