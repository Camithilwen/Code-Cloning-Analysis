#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void abc_160a();

void abc_161a();

void abc_162a();

void abc_163a();

void abc_164a();

void abc_165a();

void abc_166a();

void abc_167a();

void abc_168a();

void abc_169();

int main()
{
  //abc_160a();
  //abc_161a();
  //abc_162a();
  //abc_163a();
  //abc_164a();
  //abc_165a();
  //abc_166a();
  //abc_167a();
  //abc_168a();
  abc_169();

}

void abc_160a()
{
  string S;
  cin >> S;

  if (S[2] == S[3] && S[4] == S[5]) cout << "Yes\n";
  else cout << "No\n";
}

void swap(int& a, int& b)
{
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}

void abc_161a()
{
  int x, y, z;
  cin >> x >> y >> z;

  swap(x, y);
  swap(x, z);

  cout << x << " " << y << " " << z << "\n";
}

void abc_162a()
{
  string s;
  cin >> s;
  for (char c : s)
  {
    if (c == '7')
    {
      cout << "Yes\n";
      return;
    }
  }

  cout << "No\n";
}

void abc_163a()
{
  int R;
  cin >> R;

  cout << (double)(2 * R * M_PI);
}

void abc_164a()
{
  int s, w;
  cin >> s >> w;

  if (s <= w) cout << "unsafe\n";
  else cout << "safe\n";
}

void abc_165a()
{
  int k, a, b;
  cin >> k >> a >> b;

  for (int i = a; i <= b; ++i)
  {
    if (i % k == 0)
    {
      cout << "OK\n";
      return;
    }
  }

  cout << "NG\n";
}

void abc_166a()
{
  string s;
  cin >> s;

  if (s == "ABC") cout << "ARC\n";
  if (s == "ARC") cout << "ABC\n";

}

void abc_167a()
{
  string s, t;
  cin >> s >> t;

  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] != t[i])
    {
      cout << "No\n";
      return;
    }
  }

  if ('a' <= t[t.size() - 1] && t[t.size() - 1] <= 'z') cout << "Yes\n";
  else cout << "No\n";

}

void abc_168a()
{
  string s;
  cin >> s;

  if (s[s.size() - 1] == '3') cout << "bon\n";
  else if (s[s.size() - 1] == '0' ||
    s[s.size() - 1] == '1' ||
    s[s.size() - 1] == '6' ||
    s[s.size() - 1] == '8') cout << "pon\n";
  else cout << "hon\n";
}

void abc_169()
{
  int a, b;
  cin >> a >> b;
  cout << a * b << "\n";
}
