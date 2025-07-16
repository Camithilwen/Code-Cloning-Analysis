#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int R;
  cin >> R;

  if (R < 1200)
    cout << "ABC" << endl;
  else if (R < 2800)
    cout << "ARC" << endl;
  else
    cout << "AGC" << endl;

  return 0;
}
