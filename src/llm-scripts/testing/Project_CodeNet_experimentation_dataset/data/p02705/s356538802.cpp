#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void abc_160a();

void abc_161a();

void abc_162a();

void abc_163a();

int main()
{
  //abc_160a();
  //abc_161a();
  //abc_162a();
  abc_163a();

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