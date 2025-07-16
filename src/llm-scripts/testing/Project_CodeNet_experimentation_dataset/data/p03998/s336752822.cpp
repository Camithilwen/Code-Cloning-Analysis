#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  vector<queue<char>> v(3);

  string s;
  cin >> s;
  for (char c : s) v[0].push(c);

  cin >> s;
  for (char c : s) v[1].push(c);

  cin >> s;
  for (char c : s) v[2].push(c);

  char c = 'a';
  while (true)
  {
    char i = c - 'a';
    if (v[i].empty())
    {
      putchar(toupper(c));
      return 0;
    }

    c = v[i].front(); v[i].pop();
  }
}
